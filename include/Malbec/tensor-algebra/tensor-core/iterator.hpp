/*
This classes provides an iterator and a const iterator with random access
for the custom buffer.
*/

#ifndef INTERNAL_ITERATOR_HPP
#define INTERNAL_ITERATOR_HPP

#include <iostream>
#include <concepts>

namespace Internal {

template <class Buffer>
class Iterator {
    public:
    using iterator_category = std::random_access_iterator_tag;
    using self = Iterator<Buffer>;
    using value_type = typename Buffer::value_type;
    using size_type = typename Buffer::size_type;
    using reference = typename Buffer::reference;
    using pointer = typename Buffer::pointer;
    using const_reference = typename Buffer::const_reference;
    using const_pointer = typename Buffer::const_pointer;
    using difference_type = std::ptrdiff_t;

    Iterator(pointer address) : address_(address) {}

    self& operator ++() { ++address_; return *this; }
    self& operator --() { --address_; return *this; }
    self operator ++(int) { self copy = *this; ++address_; return copy; }
    self operator --(int) { self copy = *this; --address_; return copy; }

    reference operator *() const { return *address_; }
    pointer operator ->() const { return address_; }

    self& operator +=(size_type index) { address_ += index; return *this; }
    self& operator -=(size_type index) { address_ -= index; return *this; }
    self operator +(size_type index) const { return self(address_ + index); }
    self operator -(size_type index) const { return self(address_ - index); }
    difference_type operator -(const self& other) const { return address_ - other.address_; }

    reference operator [](size_type index) const { return address_[index]; }

    bool operator ==(const self& other) const { return address_ == other.address_; }
    bool operator !=(const self& other) const { return address_ != other.address_; }
    bool operator <(const self& other) const { return address_ < other.address_; }
    bool operator >(const self& other) const { return address_ > other.address_; }
    bool operator <=(const self& other) const { return address_ <= other.address_; }
    bool operator >=(const self& other) const { return address_ >= other.address_; }

    private:
    pointer address_;    
};

template<class Buffer>
class ConstIterator {
    public:
    using iterator_category = std::random_access_iterator_tag;
    using self = ConstIterator<Buffer>;
    using value_type = typename Buffer::value_type;
    using size_type = typename Buffer::size_type;
    using reference = typename Buffer::reference;
    using pointer = typename Buffer::pointer;
    using const_reference = typename Buffer::const_reference;
    using const_pointer = typename Buffer::const_pointer;
    using difference_type = std::ptrdiff_t;

    ConstIterator(const_pointer address) : address_(address) {}
    
    self& operator = (const Iterator<Buffer>& other) { address_ = other.address_; return *this; }

    self& operator ++() { ++address_; return *this; }
    self& operator --() { --address_; return *this; }
    self operator ++(int) { self copy = *this; ++address_; return copy; }
    self operator --(int) { self copy = *this; --address_; return copy; }

    const_reference operator *() const { return *address_; }
    const_pointer operator ->() const { return address_; }

    self& operator +=(size_type index) { address_ += index; return *this; }
    self& operator -=(size_type index) { address_ -= index; return *this; }
    self operator +(size_type index) const { return self(address_ + index); }
    self operator -(size_type index) const { return self(address_ - index); }
    difference_type operator -(const self& other) const { return address_ - other.address_; }

    const_reference operator [](size_type index) const { return address_[index]; }

    bool operator ==(const self& other) const { return address_ == other.address_; }
    bool operator !=(const self& other) const { return address_ != other.address_; }
    bool operator <(const self& other) const { return address_ < other.address_; }
    bool operator >(const self& other) const { return address_ > other.address_; }
    bool operator <=(const self& other) const { return address_ <= other.address_; }
    bool operator >=(const self& other) const { return address_ >= other.address_; }

    private:
    const_pointer address_;
};

} // namespace Internal

#endif // INTERNAL_ITERATOR_HPP