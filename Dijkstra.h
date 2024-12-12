#ifndef DIJKSTRAALGORITHM
#define DIJKSTRAALGORITHM

#include <vector>
#include <map>
#include <numeric>

template<typename W_type>
class Dijkstra {
public:
	static std::vector<W_type> 
		findShortestPaths(const std::vector<std::vector<std::pair<size_t, W_type>>>& graph, size_t startVertex) {
		size_t n = graph.size();
		std::vector<W_type> d(n, std::numeric_limits<W_type>::max());
		std::map<W_type, size_t> q;
		size_t u;
		size_t v;
		size_t w;

		q.emplace(W_type(), startVertex);
		d[startVertex] = W_type();
		while (!q.empty()) {
			u = q.begin()->second;
			q.erase(q.begin());
			for (size_t i = 0; i < graph[u].size(); ++i) {
				v = graph[u][i].first;
				w = graph[u][i].second;
				if (d[v] > d[u] + w) {
					q.erase(d[v]);
					d[v] = d[u] + w;
					q.emplace(d[v], v);
				}
			}
		}

		return d;
	}
};

#endif // !DIJKSTRAALGORITHM
