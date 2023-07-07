#ifndef INTERNAL_COMPUTATIONAL_GRAPH_HPP
#define INTERNAL_COMPUTATIONAL_GRAPH_HPP

#include <iostream>
#include <vector>
#include <forward_list>

#include "expression.hpp"

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
        for(auto expression : _expressions) delete expression;
        _expressions.clear();
    }

    void add(Expression* expression) {
        _expressions.push_back(expression); 
    }

    private:
    std::vector<Expression*> _expressions;
};

} ; // namespace Internal

#endif // INTERNAL_COMPUTATIONAL_GRAPH_HPP