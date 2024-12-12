//#include "Dijkstra.h"
//
//
//
//template<typename W_type>
//std::vector<W_type> 
//Dijkstra<W_type>::findShortestPaths(const std::vector<std::vector<std::pair<size_t, W_type>>>& graph, size_t startVertex) {
//	size_t n = graph.size();
//	std::vector<W_type> d(n, std::numeric_limits<W_type>::max());
//	std::set<W_type, size_t> q;
//	size_t u;
//	size_t v;
//	size_t w;
//
//	q.emplace(W_type(), startVertex);
//	d[startVertex] = W_type();
//
//	while (!q.empty()) {
//		u = q.begin()->second;
//		q.erase(q.begin());
//		for (size_t i = 0; i < graph[u].size(); ++i) {
//			v = graph[u][i].first;
//			w = graph[u][i].second;
//			if (d[v] > d[u] + w) {
//				q.erase(std::make_pair(d[v], v));
//				d[v] = d[u] + w;
//				q.emplace(d[v], v);
//			}
//		}
//	}
//
//	return d;
//}