/********************************************************************************

This class is a wrapper for the expression class. Because the expression class
is a base for polymorphic expressions, and we want to be able to pass around
expressions by value, we need a wrapper class to hold the pointer to the
expression.

*********************************************************************************/

#ifndef INTERNAL_TENSOR_REFERENCE_HPP
#define INTERNAL_TENSOR_REFERENCE_HPP

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