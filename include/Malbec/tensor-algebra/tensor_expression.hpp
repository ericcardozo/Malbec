#ifndef INTERNAL_EXPRESSION_HPP
#define INTERNAL_EXPRESSION_HPP

#include <iostream>
#include <memory>
#include <vector>
#include <span>

#include "./tensor_buffer.hpp"

namespace Internal {

class Expression {
    public:
    using scalar = float;
    using buffer = Buffer<scalar>;
    using pointer = typename buffer::pointer;
    using size_type = typename buffer::size_type;
    using shape_type = std::vector<size_type>;

    Expression() = default;

    Expression(pointer data_ptr, shape_type shape)
    :   shape_(shape)
    {
        size_type memory_size = 1;
        for(size_type dimension : shape) memory_size *= dimension;
        buffer_ptr = std::make_shared<buffer>(data_ptr, memory_size);
    }

    virtual ~Expression() = default;

    virtual void backward(Expression* gradient) = 0;

    protected:
    std::shared_ptr<buffer> buffer_ptr;
    shape_type shape_;
};

} // namespace Internal

#endif // INTERNAL_EXPRESSION_HPP