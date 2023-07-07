#ifndef INTERNAL_TENSOR_BODY_HPP
#define INTERNAL_TENSOR_BODY_HPP

#include <iostream>
#include <memory>
#include <vector>

//#include "tensor_buffer.hpp"

namespace Internal::Tensor {

class Body {
    public:
    using size_type = std::size_t;
    using shape_type = std::vector<size_type>;

    static size_type flatten(shape_type shape) {
        std::size_t size = 1;
        for(auto dimension : shape) size *= dimension;
        return size;
    }

    Body(shape_type shape)
    : _shape(shape)
    , _size(flatten(shape))
    {}

    size_type size() const { return _size; }
    shape_type shape() const { return _shape; }
    size_type rank() const { return _shape.size(); }

    private:
    size_type _size;
    shape_type _shape;
};

} // namespace Internal

#endif // INTERNAL_TENSOR_BODY_HPP