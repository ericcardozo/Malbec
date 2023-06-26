#ifndef TENSOR_HPP
#define TENSOR_HPP

#include "./tensor_expression.hpp"

class Tensor : public Internal::Expression {
    public:

    shape_type shape() const { return shape_; }
    size_type rank() const { return shape_.size(); }
    pointer data() const { return buffer_ptr->data(); }
    size_type size() const { return buffer_ptr->size(); }

    Internal::Expression* downcast() {
        return this;
    }

    Tensor(pointer data_ptr, shape_type shape)
    :   Expression(data_ptr, shape)
    {}

    ~Tensor() override = default;

    void backward(Internal::Expression* gradient) override {
        return;
    }

    
};

#endif // TENSOR_HPP