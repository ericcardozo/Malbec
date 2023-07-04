#ifndef PARAMETER_HPP
#define PARAMETER_HPP

#include <iostream>
#include <map>
#include <vector>

#include "./tensor.hpp"
#include "../statistics/distributions/distribution.hpp"
#include "../statistics/distributions/normal.hpp"
#include "../statistics/distributions/zeros.hpp"

enum class Initializer {
    He,
    Xavier,
    Zeros
};

class Parameter : public Tensor {
    public:    
    std::map<Initializer, std::unique_ptr<Distribution::Distribution>> initializers_map;
    Parameter(shape_type shape)
    :   Tensor(shape)   
    {
        initializers_map[Initializer::He] = std::make_unique<Distribution::Normal>(0, 1);
        initializers_map[Initializer::Xavier] = std::make_unique<Distribution::Normal>(0, 2);
        initializers_map[Initializer::Zeros] = std::make_unique<Distribution::Zeros>();
    }

    void initialize(Initializer initializer) {
        auto iterator = initializers_map.find(initializer);
        distribution_ = std::move(iterator->second);
        std::vector<float> data = distribution_->generate(size());
        std::move(std::make_move_iterator(data.begin()), std::make_move_iterator(data.end()), begin());
    }

    private:
    std::unique_ptr<Distribution::Distribution> distribution_;
};

#endif // PARAMETER_HPP