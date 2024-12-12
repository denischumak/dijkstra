#include "graphgen.h"
#include "Dijkstra.h"
#include<iostream>
#include <iomanip>
#include <chrono>
#include <string>



int main() {
	std::cout << std::setprecision(20);
	std::cout << "Vertices" << std::setw(20) << " V ~ E" << '\t'
		<< std::setw(20) << "V^1.5 ~ E" << '\t'
		<< std::setw(20) << "V^2 ~ E" << '\n';

	for (int i = 2; i <= 10000; i *= 2)
	{
		std::cout << i << '\t';
		auto graph = GraphGenerator::randomGraph_V(i);
		auto start = std::chrono::system_clock::now();
		Dijkstra<size_t>::findShortestPaths(graph, 0);
		auto stop = std::chrono::system_clock::now();
		auto res = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
		std::cout << std::setw(20) << std::to_string(res) + "us" << '\t';

		graph = GraphGenerator::randomGraph_V15(i);
		start = std::chrono::system_clock::now();
		Dijkstra<size_t>::findShortestPaths(graph, 0);
		stop = std::chrono::system_clock::now();
		res = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
		std::cout << std::setw(20) << std::to_string(res) + "us" << '\t';

		graph = GraphGenerator::randomGraph_V2(i);
		start = std::chrono::system_clock::now();
		Dijkstra<size_t>::findShortestPaths(graph, 0);
		stop = std::chrono::system_clock::now();
		res = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
		std::cout << std::setw(20) << std::to_string(res) + "us" << '\n';
	}
	return 0;
}
