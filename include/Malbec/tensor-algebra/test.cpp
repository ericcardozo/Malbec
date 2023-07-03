#include <iostream>
#include <vector>

#include "tensor.hpp"

int main() {
    std::vector<float> a = {1,2,3,4};
    Tensor A(a,{2, 2});
    A.print();
    return 0;
}
