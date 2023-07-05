#ifndef INTERNAL_TENSOR_BODY_HPP
#define INTERNAL_TENSOR_BODY_HPP

#include <iostream>
#include <memory>
#include <vector>

//#include "tensor_buffer.hpp"

namespace Internal {

struct Body {
    using size_type = std::size_t;
    using shape_type = std::vector<size_type>;
    
    size_type size;
    size_type rank;
    shape_type shape;

    Body(shape_type shape)
    : size(flat(shape))
    , rank(shape.size())
    , shape(shape)
    {}

    static size_type flat(shape_type shape) {
        std::size_t size = 1;
        for(auto dimension : shape) size *= dimension;
        return size;
    }
};

} // namespace Internal

#endif // TENSOR_BODY_HPP