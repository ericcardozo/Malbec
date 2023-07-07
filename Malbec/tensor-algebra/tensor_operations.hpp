#ifndef INTERNAL_TENSOR_OPERATIONS_HPP
#define INTERNAL_TENSOR_OPERATIONS_HPP

#include <iostream>

#include "expression.hpp"
#include "tensor_base.hpp"

#include <eigen3/Eigen/Dense>

namespace Internal {

struct Softmax {
    using scalar = float;
    using size_type = std::size_t;

    static void value(Tensor::Base* input) {
        size_type columns = input->shape().back();
        size_type rows = input->size() / columns;

        Eigen::Map<Eigen::Array<scalar,-1,-1,1>> X(input->data(), rows, columns);
        auto exp_shifted = (X.colwise() - X.rowwise().maxCoeff()).exp();
        auto sum_exp_shifted = exp_shifted.rowwise().sum();
        auto output = exp_shifted.colwise() / sum_exp_shifted;
        X = output;
    }

    static void gradient(Tensor::Base* gradient, Tensor::Base* input) {
        /*Empty*/
    }

    Softmax() = delete;
};


template<class Implementation>
class Functor : public Expression {
    public:
    
    Functor(Expression* input) : _cache(input) {
        this->clone(input);
        Implementation::value(this->tensor_pointer());
    }

    void backward(Expression* gradient) override {
        Implementation::gradient(gradient->value, this->tensor());
        _cache->backward(gradient);
    }

    private:
    Expression* _cache;
};

class Addition {
    public:
    using scalar = float;
    using pointer = scalar *;
    using size_type = std::size_t;

    static void value(Tensor::Base* augend, Tensor::Base* addend) {
        //assert shape1 == shape2
        size_type columns = augend->shape().back();
        size_type rows = augend->size() / columns;
        Eigen::Map<Eigen::Array<scalar,-1,-1,1>> lhs(augend->data(), rows, columns);
        Eigen::Map<Eigen::Array<scalar,-1,-1,1>> rhs(addend->data(), rows, columns);
        lhs += rhs;
    }

    static void gradient(Tensor::Base* gradient, Tensor::Base* first, Tensor::Base* second) {
        std::swap(first, second);
        Eigen::Map<Eigen::Array<scalar, 1,-1,1>> lhs(first->data(), first->size());
        Eigen::Map<Eigen::Array<scalar, 1,-1,1>> rhs(second->data(), second->size());
        Eigen::Map<Eigen::Array<scalar, 1,-1,1>> J(gradient->data(), gradient->size());
        
        lhs*=J;
        rhs*=J;
    }
};

template<class Operation>
class Binary : public Expression {
    public:
    Addition(Expression* first, Expression* second)
    : _cache{first, second} {
        this->clone(first);
        this->tensor_pointer()->data();
        Operation::value(_cache.first->tensor(), _cache.second->tensor())
    }

    void backward(Expression* gradient) override {
        Operation::gradient(gradient->tensor(), _cache.first->tensor(), _cache.second->tensor())

    }

    private:
    std::pair<Expression*, Expression*> _cache;
};

} // namespace Internal

#endif // INTERNAL_TENSOR_OPERATIONS_HPP