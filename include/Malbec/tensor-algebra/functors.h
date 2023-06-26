#ifndef FUNCTORS_H
#define FUNCTORS_H

#include "./functor_expression.hpp"
#include "./tensor_expression.hpp"
#include "./tensor.hpp"

#include <eigen3/Eigen/Dense>

using array_type = Eigen::Array<float, Eigen::Dynamic, Eigen::Dynamic, Eigen::RowMajor>;

class Softmax : public Internal::Functor<Softmax> {

    friend class Internal::Functor<Softmax>;

    static pointer forward_implementation(
        pointer input_ptr,
        shape_type shape )
    {
        size_type columns = shape.back();
        size_type rows = 1;

        for(auto index = 0; index < shape.size() - 1; index++)
            rows *= shape[index];
        
        auto X = Eigen::Map<const array_type>(input_ptr, rows, columns);
        auto shifted_exp = (X.colwise() - X.rowwise().maxCoeff()).exp();
        auto sum_shifted_exp = shifted_exp.rowwise().sum();

        array_type output_array =  shifted_exp.colwise() / sum_shifted_exp;
        return output_array.data();
    }

    static Internal::Expression* backward_implementation(
        Internal::Expression* gradient,
        Internal::Expression* input )
    {
        return gradient;
    }
};

#endif // FUNCTORS_H