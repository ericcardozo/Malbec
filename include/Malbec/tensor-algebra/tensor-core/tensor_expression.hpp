/******************************************************************************
This class is the base class for all the expressions in the tensor algebra.
The idea is to make a tree of expressions, for example:

    A = B + C

would be represented as:

    A
   / \
  B   C

Where A, B and C are expressions as nodes. The expression class is responsible
for storing the prior expressions, in this case B and C. The expression class
is also responsible for storing the data of the resulting tensor of the
expression. For example, in tree the expression class would store the data of
the resulting tensor A.

******************************************************************************/

#ifndef INTERNAL_TENSOR_EXPRESSION_HPP
#define INTERNAL_TENSOR_EXPRESSION_HPP

#include <iostream>
#include <memory>
#include <vector>

#include "tensor_body.hpp"
#include "tensor_buffer.hpp"

namespace Internal::Tensor {

class Expression : public Body {
    public:
    using self = Expression;
    using buffer = Buffer<scalar>;

    virtual ~Expression() = default;
    virtual void backward(Expression* gradient) = 0;

    Expression(shape_type shape) : Body(shape) {}

    protected:
    std::vector<Expression*> prior_expressions;
};

} // namespace Internal::Tensor

#endif // INTERNAL_TENSOR_EXPRESSION_HPP