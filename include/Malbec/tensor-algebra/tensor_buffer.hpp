#ifndef INTERNAL_BUFFER_HPP
#define INTERNAL_BUFFER_HPP

namespace Internal {

template<typename T>
class Buffer {
    public:
    using value_type = std::remove_cv_t<T>;
    using size_type = std::size_t;
    using pointer = T *;
    using const_pointer = const T*;

    size_type size() const {return size_;}
    pointer data() const {return data_;}

    Buffer(pointer data, size_type size)
    :   data_(data)
    ,   size_(size)
    {}

    private:
    pointer data_;
    size_type size_;
};

} // namespace Internal

#endif // INTERNAL_BUFFER_HPP