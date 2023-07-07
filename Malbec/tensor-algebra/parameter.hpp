#ifndef PARAMETERS_HPP
#define PARAMETERS_HPP

#include <iostream>
#include <memory>
#include <vector>
#include <map>

#include "tensor_base.hpp"
#include "../statistics/distributions.hpp"

namespace ml {

enum class Initializer {
    He,
    Xavier,
    Zeros
};

class Parameter : public Internal::Tensor::Base {
    public:

    ~Parameter() override = default;

    std::map<Initializer, std::unique_ptr<Distribution::Distribution>> initializers_map;
    
    Parameter(shape_type shape) : Base(shape) {
        initializers_map[Initializer::He] = std::make_unique<Distribution::Normal>(0, 1);
        initializers_map[Initializer::Xavier] = std::make_unique<Distribution::Normal>(0, 2);
        initializers_map[Initializer::Zeros] = std::make_unique<Distribution::Zeros>();
    }

    void initialize(Initializer initializer) {
        auto iterator = initializers_map.find(initializer);
        distribution_ = std::move(iterator->second);
        std::vector<scalar> data = distribution_->generate(size());
        std::move(std::make_move_iterator(data.begin()), std::make_move_iterator(data.end()), begin());
    }

    private:
    std::unique_ptr<Distribution::Distribution> distribution_;
};

} // namespace ml

#endif