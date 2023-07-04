#ifndef DISTRIBUTION_HPP
#define DISTRIBUTION_HPP

#include <iostream>
#include <vector>
#include <random>
#include <memory>

namespace Distribution {

class Distribution {
    public:
    using real_type = float;
    virtual ~Distribution() = default;

    virtual std::vector<real_type> generate(std::size_t) = 0;

    protected:
    Distribution() = default;
    std::mt19937 generator{std::random_device()()};
};

} // namespace Statistics::Distribution

#endif // DISTRIBUTION_HPP