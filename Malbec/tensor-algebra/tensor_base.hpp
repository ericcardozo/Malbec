#ifndef INTERNAL_TENSOR_BASE_HPP
#define INTERNAL_TENSOR_BASE_HPP

#include <iostream>
#include <memory>
#include <vector>

#include "tensor_body.hpp"
#include "expression.hpp"

namespace Internal::Tensor {

class Base {
    public:
    using scalar = float;
    using pointer = scalar *;
    using self = Base;

    using storage_type = std::vector<scalar>;
    using iterator = typename storage_type::iterator;
    using const_iterator = typename storage_type::const_iterator;

    using body_type = Internal::Tensor::Body;
    using size_type = typename body_type::size_type;
    using shape_type = typename body_type::shape_type;

    iterator begin() {return _data.begin(); }
    iterator end() { return _data.end(); }

    const_iterator begin() const { return _data.cbegin(); }
    const_iterator end() const { return _data.cend(); }

    const_iterator cbegin() const { return _data.cbegin(); }
    const_iterator cend() const { return _data.cend(); }

    Base(shape_type shape)
    : _body(shape)
    , _data(Body::flatten(shape))
    {}

    template<class Iterable>
    Base(Iterable begin, Iterable end)
    : _body({static_cast<size_type>(std::distance(begin, end))})
    , _data(begin, end)
    {}

    virtual ~Base() = default;

    size_type size() const { return _body.size(); }
    size_type rank() const { return _body.rank(); }
    shape_type shape() const { return _body.shape(); }
    pointer data() { return _data.data(); }

    void reshape(shape_type shape) { _body = body_type(shape); }

    private:
    storage_type _data;
    body_type _body;
};

}

#endif // INTERNAL_TENSOR_BASE_HPP