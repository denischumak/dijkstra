#include "graphgen.h"

std::vector<std::vector<std::pair<size_t, size_t>>> GraphGenerator::randomGraph_V(size_t num_of_nodes)
{
    ValueGenerator generator(num_of_nodes);

    return randomGraph_(num_of_nodes, generator.getNumOfEdges(num_of_nodes - 1, std::min(num_of_nodes * (num_of_nodes - 1), num_of_nodes * 3)));
}

std::vector<std::vector<std::pair<size_t, size_t>>> GraphGenerator::randomGraph_V15(size_t num_of_nodes)
{
    ValueGenerator generator(num_of_nodes);

    size_t num_of_edges = num_of_nodes * sqrt(num_of_nodes);

    return randomGraph_(num_of_nodes, generator.getNumOfEdges(std::max(num_of_nodes - 1, num_of_edges / 3), std::min(num_of_nodes * (num_of_nodes - 1), num_of_edges * 3)));
}

std::vector<std::vector<std::pair<size_t, size_t>>> GraphGenerator::randomGraph_V2(size_t num_of_nodes)
{
    ValueGenerator generator(num_of_nodes);

    size_t num_of_edges = num_of_nodes * num_of_nodes;

    return randomGraph_(num_of_nodes, generator.getNumOfEdges(std::max(num_of_nodes - 1, num_of_edges / 3), num_of_nodes * (num_of_nodes - 1)));
}

std::vector<std::vector<std::pair<size_t, size_t>>> GraphGenerator::randomTree_(size_t num_of_nodes)
{
    ValueGenerator generator(num_of_nodes);

    Graph graph(num_of_nodes);

    for (size_t i = 1; i < num_of_nodes; ++i)
    {
        graph[generator.getNodeId(i - 1)].emplace_back(std::make_pair(i, generator.getEdgeValue()));
    }

    return graph;
}

std::vector<std::vector<std::pair<size_t, size_t>>> GraphGenerator::randomGraph_(size_t num_of_nodes, size_t num_of_edges)
{
    ValueGenerator generator(num_of_nodes);
    Graph graph = randomTree_(num_of_nodes);
    num_of_edges -= num_of_nodes - 1;

    while (num_of_edges)
    {
        size_t node_1 = generator.getNodeId();
        size_t node_2 = generator.getNodeId();
        if (node_1 == node_2)
        {
            continue;
        }
        graph[node_1].emplace_back(std::make_pair(node_2, generator.getEdgeValue()));
        --num_of_edges;
    }

    return graph;
}

GraphGenerator::ValueGenerator::ValueGenerator(size_t num_of_nodes) : num_of_nodes(num_of_nodes), generator(rd()), edge_value(0, 100000), node_id(0, num_of_nodes - 1)
{
}

size_t GraphGenerator::ValueGenerator::getNodeId()
{
    return node_id(generator);
}

size_t GraphGenerator::ValueGenerator::getNodeId(size_t max_id)
{
    return std::uniform_int_distribution<>{0, (int)max_id}(generator);
}

size_t GraphGenerator::ValueGenerator::getEdgeValue()
{
    return edge_value(generator);
}

size_t GraphGenerator::ValueGenerator::getNumOfEdges(size_t min_num_of_edges, size_t max_num_of_edges)
{
    return std::uniform_int_distribution<>{(int)min_num_of_edges, (int)max_num_of_edges}(generator);
}

size_t GraphGenerator::estimateEdgesSize(const GraphGenerator::Graph& graph) {
    size_t num_of_edges = 0;
    for (size_t i = 0; i < graph.size(); ++i) {
        num_of_edges += graph[i].size();
    }
    return num_of_edges;
}

GraphGenerator::Graph GraphGenerator::preGeneratedGraph() {
    Graph graph(5);
    graph[0].emplace_back(1, 10);
    graph[0].emplace_back(4, 5);
    graph[1].emplace_back(2, 1);
    graph[1].emplace_back(4, 2);
    graph[2].emplace_back(3, 4);
    graph[3].emplace_back(2, 6);
    graph[3].emplace_back(0, 7);
    graph[4].emplace_back(3, 2);
    graph[4].emplace_back(1, 3);
    graph[4].emplace_back(2, 9);

    return graph;
}