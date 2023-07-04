#ifndef DISTRIBUTION_NORMAL_HPP
#define DISTRIBUTION_NORMAL_HPP

#include "distribution.hpp"

namespace Distribution {

class Normal : public Distribution {
    public:

    ~Normal() override = default;

    Normal(real_type mean, real_type standard_deviation)
    :   distribution_(mean, standard_deviation)
    {}

    std::vector<real_type> generate(std::size_t number_of_samples) override {
        std::vector<real_type> samples(number_of_samples);
        for(auto& sample : samples) sample = distribution_(generator);
        return samples;
    }

    private:
    std::normal_distribution<real_type> distribution_;
};

} // namespace Distribution

#endif // DISTRIBUTION_NORMAL_HPP