#ifndef TENSOR_EXPRESSION_HPP
#define TENSOR_EXPRESSION_HPP

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

    protected:
    std::vector<Expression*> prior_expressions;
    std::shared_ptr<buffer> buffer;
};


} // namespace Internal::Tensor

#endif // TENSOR_EXPRESSION_HPP