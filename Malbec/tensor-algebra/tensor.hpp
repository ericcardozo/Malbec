#ifndef TENSOR_HPP
#define TENSOR_HPP

#include <iostream>
#include <memory>
#include <vector>

#include "tensor_body.hpp"
#include "tensor_expression.hpp"
#include "tensor_base.hpp"

namespace ml {

class Tensor : public Internal::Tensor::Base {
    public:
    using Internal::Tensor::Base::Base;
    ~Tensor() override = default;
    void backward(Internal::Expression* gradient) override { return; };
};

} // namespace ml

#endif // TENSOR_HPP