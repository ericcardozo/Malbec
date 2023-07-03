/******************************************************************************

This class is just a chunk of memory allocated in the heap, similiar to std::vector,
for storing the data of expressions.

Why don't just use std::vector? because sometimes i want to make experiments
with the memory layout of the tensor, for example making the destructor of the
buffer class virtual for making a polymorphic buffer, or adding custom methods for
allocating and deallocating memory, etc.

Also I don't think it is a bad idea to spend a few hours learning about memory
management in C++. RAII and iterators are important concepts to know.

******************************************************************************/

#ifndef INTERNAL_TENSOR_BUFFER_HPP
#define INTERNAL_TENSOR_BUFFER_HPP

#include <iostream>
#include <algorithm>

#include "iterator.hpp"

namespace Internal::Tensor {
    
template <typename T>
class Buffer {
    public:
    using self = Buffer<T>;
    using value_type = T;
    using reference = value_type &;
    using const_reference = const value_type &;
    using pointer = value_type *;
    using const_pointer = const value_type *;
    using size_type = std::size_t;
    using iterator = Iterator<self>;
    using const_iterator = ConstIterator<self>;

    Buffer(size_type size) { allocate(size); }
    Buffer(const_pointer data, size_type size) : Buffer(size) { std::copy(data, data + size, data_); }

    Buffer(const Buffer& other) { copy(other); }
    Buffer(Buffer&& other) noexcept { move(other); }
    ~Buffer() { deallocate(); }
    Buffer& operator =(const Buffer& other){ if (this != &other) copy(other); return *this; }
    Buffer& operator =(Buffer&& other) noexcept { if (this != &other) move(other); return *this; }

    iterator begin() { return iterator(data_); }
    iterator end() { return iterator(data_ + size_); }

    const_iterator begin() const { return const_iterator(data_); }
    const_iterator end() const { return const_iterator(data_ + size_); }

    const_iterator cbegin() const { return const_iterator(data_); }
    const_iterator cend() const { return const_iterator(data_ + size_); }

    pointer data() const { return data_; }
    size_type size() const { return size_; }

    protected: 

    void allocate(size_type size) {
        delete[] data_;
        size_ = size;
        data_ = new value_type[size_];
    }
    
    void deallocate() {
        delete[] data_;
        data_ = nullptr;
        size_ = 0;
    }

    void copy(const self& other) {
        allocate(other.size_);
        std::copy(other.data_, other.data_ + other.size_, data_);
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

#endif // INTERNAL_TENSOR_BUFFER_HPP