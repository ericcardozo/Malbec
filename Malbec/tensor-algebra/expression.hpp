#ifndef INTERNAL_EXPRESSION_HPP
#define INTERNAL_EXPRESSION_HPP

#include <iostream>
#include <memory>
#include <vector>

#include "tensor_base.hpp"

namespace Internal {

class Expression {
    public:
    virtual ~Expression() = default;
    virtual void backward(Expression* gradient) = 0;

    Tensor::Base* tensor_pointer() { return _result.get(); }
    Tensor::Base::shape_type shape() const { return _result->shape(); }
    
    protected:
    void clone(Expression* other) {
        _result = std::make_shared<Tensor::Base>(other->shape());
        std::copy(other->_result->begin(), other->_result->end(), _result->begin());
    }

    void copy(Expression* other) {
        _result = other->_result;
    }

    private:
    std::shared_ptr<Tensor::Base> _result;
};

} // namespace Internal

#endif // INTERNAL_EXPRESSION_HPP