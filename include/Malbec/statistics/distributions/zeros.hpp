#ifndef DISTRIBUTION_ZEROS_HPP
#define DISTRIBUTION_ZEROS_HPP

#include "distribution.hpp"

namespace Distribution {

class Zeros : public Distribution {
    public:

    ~Zeros() override = default;
    Zeros() = default;

    std::vector<real_type> generate(std::size_t number_of_samples) override {
        std::vector<real_type> samples(number_of_samples);
        for(auto& sample : samples) sample = 0;
        return samples;
    }
};

} // namespace Distribution

#endif // DISTRIBUTION_NORMAL_HPP