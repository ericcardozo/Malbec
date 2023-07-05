#ifndef INTERNAL_EXPRESSION_HPP
#define INTERNAL_EXPRESSION_HPP

#include <iostream>
#include <memory>
#include <vector>

#include "tensor.hpp"

namespace Internal {

class Expression {
    public:
    using self = Expression;

    virtual ~Expression() = default;
    virtual void backward(Expression* gradient) = 0;

    protected:
    std::vector<Expression*> views;
};

} // namespace Internal

#endif // INTERNAL_EXPRESSION_HPP