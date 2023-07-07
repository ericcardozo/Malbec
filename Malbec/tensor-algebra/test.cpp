#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <memory>

#include "tensor.hpp"
#include "parameter.hpp"
#include "tensor_operations.hpp"

int main() {
    ml::Parameter p({2, 2});
    p.initialize(ml::Initializer::He);

    Internal::Expression(&p);
    Internal::Functor<Internal::Softmax> func(&p);

    for(auto x : p) std::cout << x << std::endl;
};