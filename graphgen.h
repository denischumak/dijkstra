#pragma once
#include <vector>
#include <random>


class GraphGenerator
{
public:

	using Graph = std::vector<std::vector<std::pair<size_t, size_t>>>;

	static Graph randomGraph_V(size_t num_of_nodes);
	static Graph randomGraph_V15(size_t num_of_nodes);
	static Graph randomGraph_V2(size_t num_of_nodes);
	static Graph preGeneratedGraph();
	static size_t estimateEdgesSize(const Graph& graph);

private:

	struct ValueGenerator
	{
		size_t num_of_nodes;
		std::uniform_int_distribution<> edge_value;
		std::uniform_int_distribution<> node_id;
		std::random_device rd;
		std::mt19937 generator;

		ValueGenerator(size_t num_of_nodes);

		size_t getNodeId();
		size_t getNodeId(size_t max_id);
		size_t getEdgeValue();
		size_t getNumOfEdges(size_t min_num_of_edges, size_t max_num_of_edges);
	};

	static Graph randomTree_(size_t num_of_nodes);
	static Graph randomGraph_(size_t num_of_nodes, size_t num_of_edges);
};