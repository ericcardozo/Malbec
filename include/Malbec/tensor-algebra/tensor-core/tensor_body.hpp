/******************************************************************************

******************************************************************************/

#ifndef INTERNAL_TENSOR_BODY_HPP
#define INTERNAL_TENSOR_BODY_HPP

#include <iostream>
#include <memory>
#include <vector>

#include "tensor_buffer.hpp"

namespace Internal::Tensor {

class Body {
    public:
    using self = Body;
    using scalar = float;
    using pointer = scalar*;
    using size_type = std::size_t;
    using shape_type = std::vector<size_type>;
    using buffer = std::vector<scalar>;
    using iterator = buffer::iterator;
    using const_iterator = buffer::const_iterator;

    Body(shape_type shape) : shape_(shape) {
        size_ = 1;
        for(size_type dimension : shape_) size_ *= dimension;
    }

    iterator begin() { return data_ptr->begin(); }
    iterator end() { return data_ptr->end(); }

    const_iterator begin() const { return data_ptr->cbegin(); }
    const_iterator end() const { return data_ptr->cend(); }

    const_iterator cbegin() const { return data_ptr->cbegin(); }
    const_iterator cend() const { return data_ptr->cend(); }

    pointer data() const { return data_ptr->data(); }

    size_type size() const { return size_; }
    size_type rank() const { return shape_.size(); }
    shape_type shape() const { return shape_; }

    protected:
    std::shared_ptr<buffer> data_ptr;

    private:
    shape_type shape_;
    size_type size_;
};

} // namespace Internal::Tensor

#endif // TENSOR_BODY_HPP