#ifndef BACKTRACK_BENCHMARK_H
#define BACKTRACK_BENCHMARK_H

#include <vector>
#include <string>

// CSV and benchmarking utilities
std::vector<std::vector<int>> stringToBoard(const std::string& puzzleStr);
bool verifySolution(const std::vector<std::vector<int>>& board, const std::string& solution);
void benchmark(const std::string& filename, int numPuzzles);

#endif // BACKTRACK_BENCHMARK_H