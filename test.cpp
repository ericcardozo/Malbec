#include <iostream>
#include <vector>
#include <span>

int main() {
    std::vector<float> v = {1,2,3,4,5};
    std::span<float> w(v.data(), v.size())
    for(auto element : W) std::cout << element;

    return 0;
}