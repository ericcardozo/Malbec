#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <memory>

#include "tensor.hpp"
#include "parameter.hpp"

int main() {
    ml::Parameter p({2, 2});
    p.initialize(ml::Initializer::He);

    for(auto x : p) std::cout << x << std::endl;

};