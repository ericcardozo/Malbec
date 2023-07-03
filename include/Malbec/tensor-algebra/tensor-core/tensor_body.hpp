#ifndef TENSOR_BODY_HPP
#define TENSOR_BODY_HPP

#include <iostream>
#include <memory>
#include <vector>

namespace Internal::Tensor {

class Body {
    public:
    using self = Body;
    using scalar = float;
    using pointer = scalar*;
    using size_type = std::size_t;
    using shape_type = std::vector<size_type>;

    Body(shape_type shape) : shape_(shape) {
        size_ = 1;
        for(size_type dimension : shape_) size_ *= dimension;
    }

    size_type size() const { return size_; }
    size_type rank() const { return shape_.size(); }
    shape_type shape() const { return shape_; }

    private:
    shape_type shape_;
    size_type size_;
};

} // namespace Internal::Tensor

#endif // TENSOR_BODY_HPP