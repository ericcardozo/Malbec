#ifndef COMPUTATIONAL_GRAPH_HPP
#define COMPUTATIONAL_GRAPH_HPP

#include <iostream>
#include <vector>

#include "./tensor-core/tensor_expression.hpp"

namespace Internal {

class Graph {
    public:
    Graph() = default;

    ~Graph() { clear(); }
    Graph(const Graph&) = delete;
    Graph(Graph&&) = delete;
    Graph& operator =(const Graph&) = delete;
    Graph& operator =(Graph&&) = delete;

    void clear() { 
        for(auto expression : expressions_) delete expression;
        expressions_.clear();
    }

    void add(Tensor::Expression* expression) {
        expressions_.push_back(expression); 
    }

    private:
    std::vector<Tensor::Expression*> expressions_;
};

} ; // namespace Internal

#endif // COMPUTATIONAL_GRAPH_HPP