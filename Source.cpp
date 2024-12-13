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
	size_t avg_value;
	for (int i = 2; i <= 10000; i *= 2)
	{
		std::cout << i << '\t';
		avg_value = 0;
		for (int j = 0; j < 10; ++j) {
			auto graph = GraphGenerator::randomGraph_V(i);
			auto start = std::chrono::system_clock::now();
			Dijkstra<size_t>::findShortestPaths(graph, 0);
			auto stop = std::chrono::system_clock::now();
			auto res = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
			avg_value += res;
		}
		std::cout << std::setw(20) << (double)avg_value / 10 << '\t';
		avg_value = 0;
		for (int j = 0; j < 10; ++j) {
			auto graph = GraphGenerator::randomGraph_V15(i);
			auto start = std::chrono::system_clock::now();
			Dijkstra<size_t>::findShortestPaths(graph, 0);
			auto stop = std::chrono::system_clock::now();
			auto res = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
			avg_value += res;
		}
		std::cout << std::setw(20) << (double)avg_value / 10 << '\t';
		avg_value = 0;
		for (int j = 0; j < 10; ++j) {
			auto graph = GraphGenerator::randomGraph_V2(i);
			auto start = std::chrono::system_clock::now();
			Dijkstra<size_t>::findShortestPaths(graph, 0);
			auto stop = std::chrono::system_clock::now();
			auto res = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
			avg_value += res;
		}
		std::cout << std::setw(20) << (double)avg_value / 10 << '\n';
	}
	return 0;
}
