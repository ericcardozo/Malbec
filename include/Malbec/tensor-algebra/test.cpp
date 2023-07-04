#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <memory>

#include "tensor.hpp"
#include "tensor-core/tensor_expression.hpp"
#include "tensor-core/tensor_reference.hpp"
#include "parameter.hpp"

class Graph {
    public:
    Graph() = default;
    ~Graph() { clear(); }

    void clear() { 
        for(auto expression : expressions_) delete expression;
        expressions_.clear();
    }

    void add(Internal::Tensor::Expression* expression) {
        expressions_.push_back(expression);
    }

    private:
    std::vector<Internal::Tensor::Expression*> expressions_;
};

class Module {};


class Dense : public Module {
    public:
    using size_type = typename Parameter::size_type;
    Dense ( size_type input_features, size_type output_features)
    :   weight_({input_features, output_features})
    ,   bias_({1,output_features})
    {}

    void initialize(
        Initializer weight_initializer = Initializer::He,
        Initializer bias_initializer = Initializer::Zeros
    ) {
        weight_.initialize(weight_initializer);
        bias_.initialize(bias_initializer);
    }
    
    private:
    Parameter weight_;
    Parameter bias_;
};

class Softmax

int main() {
    Parameter parameter({2, 2});
    parameter.initialize(Initializer::He);
    for(auto e : parameter) std::cout << e;
};