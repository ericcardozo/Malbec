#ifndef TENSOR_BUFFER_HPP
#define TENSOR_BUFFER_HPP

/******************************************************************************

This is just a chunk of memory allocated in the heap, similiar to std::vector,
for storing the data of expressions.

Why don't just use std::vector? because sometimes i want to make experiments
with the memory layout of the tensor, for example making the destructor of the
buffer class virtual for making a polymorphic buffer, add custom methods for
allocating and deallocating memory, etc.

******************************************************************************/

#include <iostream>
#include <algorithm>

namespace Internal::Tensor {
    
template <typename T>
class Buffer {
    public:
    using self = Buffer<T>;
    using value_type = T;
    using pointer = value_type*;
    using size_type = std::size_t;

    Buffer(pointer data, size_type size){ allocate(data, size); }
    Buffer(const Buffer& other) { copy(other); }
    Buffer(Buffer&& other) noexcept { move(other); }
    ~Buffer() { deallocate(); }

    Buffer& operator =(const Buffer& other) { if (this != &other) copy(other); return *this; }
    Buffer& operator =(Buffer&& other) noexcept { if (this != &other) move(other); return *this; }

    pointer data() const { return data_; }
    size_type size() const { return size_; }

    protected: 
    void allocate(pointer data, size_type size) {
        size_ = size;
        data_ = new value_type[size];
        std::copy(data, data + size, data_);
    }

    void deallocate() {
        delete[] data_;
        data_ = nullptr;
        size_ = 0;
    }

    void copy(const self& other) {
        if(data_ != nullptr) delete[] data_;
        allocate(other.data_, other.size_);
    }

    void move(self&& other) noexcept {
        delete[] data_;
        size_ = other.size_;
        data_ = other.data_;
        other.size_ = 0;
        other.data_ = nullptr;
    }

    private:
    pointer data_ = nullptr;
    size_type size_ = 0;
};

} // namespace Internal::Tensor

#endif // TENSOR_BUFFER_HPP