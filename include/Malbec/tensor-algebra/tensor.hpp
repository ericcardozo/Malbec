#ifndef TENSOR_HPP
#define TENSOR_HPP

#include <iostream>
#include <memory>
#include <vector>

#include "tensor-core/tensor_body.hpp"
#include "tensor-core/tensor_buffer.hpp"
#include "tensor-core/tensor_reference.hpp"
#include "tensor-core/tensor_expression.hpp"

class Tensor : public Internal::Tensor::Body {
    public:
    using self = Tensor;

    using Reference = Internal::Tensor::Reference;
    using Expression = Internal::Tensor::Expression;

    Tensor(shape_type shape) : Body(shape) {
        data_ptr = std::make_shared<buffer>(size());
    }

    template <class Iterable>
    Tensor(Iterable begin, Iterable end, shape_type shape) : Body(shape) {
        data_ptr = std::make_shared<buffer>(begin, end);
    }
    
    void print() {
        std::cout << "Tensor of shape: ";
        for(size_type dimension : shape()) std::cout << dimension << " ";
        std::cout << std::endl;

        for(size_type i = 0; i < size(); i++) {
            std::cout << data()[i] << " ";
        }
        std::cout << std::endl;
    }
};

#endif // TENSOR_HPP