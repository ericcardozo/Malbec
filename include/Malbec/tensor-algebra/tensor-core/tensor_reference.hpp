#ifndef TENSOR_REFERENCE_HPP
#define TENSOR_REFERENCE_HPP

#include "tensor_expression.hpp"

namespace Internal::Tensor {

class Reference {
    public:
    Reference(Expression* expression) : expression_(expression) {}

    Expression* expression() const { return expression_; }
    Expression* operator ->() const { return expression_; }
    Expression& operator *() const { return *expression_; }

    private:
    Expression* expression_;
};

} // namespace Internal::Tensor

#endif // TENSOR_REFERENCE_HPP