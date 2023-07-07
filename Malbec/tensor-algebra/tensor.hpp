#ifndef TENSOR_HPP
#define TENSOR_HPP

#include <iostream>
#include <memory>
#include <vector>

#include "tensor_body.hpp"
#include "expression.hpp"
#include "tensor_base.hpp"

namespace ml {

class Tensor : public Internal::Tensor::Base {
    public:
    using Internal::Tensor::Base::Base;
    ~Tensor() override = default;
};

} // namespace ml

#endif // TENSOR_HPP