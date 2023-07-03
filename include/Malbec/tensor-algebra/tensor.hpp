#ifndef TENSOR_HPP
#define TENSOR_HPP

#include <iostream>
#include <memory>
#include <vector>

#include "tensor_body.hpp"
#include "tensor_buffer.hpp"
#include "tensor_reference.hpp"
#include "tensor_expression.hpp"

class Tensor : public Internal::Tensor::Body {
    public:
    using self = Tensor;
    using buffer = Internal::Tensor::Buffer<scalar>;

    Tensor(shape_type shape) : Body(shape) {}


    private:
    std::shared_ptr<buffer> data_;
};


#endif // TENSOR_HPP