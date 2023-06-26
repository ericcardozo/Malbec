#ifndef INTERNAL_FUNCTOR_EXPRESSION_HPP
#define INTERNAL_FUNCTOR_EXPRESSION_HPP

#include "./tensor_expression.hpp"

namespace Internal {

template<class Function>
class Functor : public Expression {
    
    static Tensor forward(const Tensor& input) {
        Functor(input.downcast());
        pointer output_ptr = Function::forward_implementation(prior_ptr, input.shape());
        return Tensor(output_ptr, input.shape());
    }

    void backward(Expression* gradient) {
        Expression* seed = Function::backward_implementation(gradient);
        prior_ptr->backward(seed);
    }

    protected:
    Expression* prior_ptr;

    private:
    Functor(Expression* input) : prior_ptr(input) {}

};

};

#endif // INTERNAL_FUNCTOR_EXPRESSION_HPP