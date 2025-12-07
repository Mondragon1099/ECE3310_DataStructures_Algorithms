#include "backtrack_benchmark.h"
#include <iostream>
#include <fstream> // library file for file handling
#include <sstream> // provides string stream classes
#include <chrono>  // library to measure time

#define N 9
using namespace std;

// Forward declare the solving function from your main file
extern bool solveSudokuBacktracking(vector<vector<int>>& board);

vector<vector<int>> stringToBoard(const string& puzzleStr)
{
    vector<vector<int>> board(N, vector<int>(N, 0));
    
    for (int i = 0; i < 81; i++) {
        int row = i / 9;
        int col = i % 9;
        board[row][col] = puzzleStr[i] - '0';
    }
    
    return board;
}

bool verifySolution(const vector<vector<int>>& board, const string& solution)
{
    for (int i = 0; i < 81; i++) {
        int row = i / 9;
        int col = i % 9;
        if (board[row][col] != (solution[i] - '0')) {
            return false;
        }
    }
    return true;
}

void benchmark(const string& filename, int numPuzzles)
{
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Error: Could not open file " << filename << endl;
        return;
    }
    
    string line;
    // Skip header line
    getline(file, line);
    
    int solved = 0;
    int failed = 0;
    double totalTime = 0.0;
    double minTime = 1e9;
    double maxTime = 0.0;
    
    cout << "Starting benchmark with " << numPuzzles << " puzzles...\n" << endl;
    
    for (int puzzleNum = 0; puzzleNum < numPuzzles; puzzleNum++) {
        if (!getline(file, line)) {
            cout << "Reached end of file at puzzle " << puzzleNum << endl;
            break;
        }
        
        // Parse CSV line
        stringstream ss(line);
        string puzzle, solution;
        
        getline(ss, puzzle, ',');
        getline(ss, solution, ',');
        
        // Convert string to board
        vector<vector<int>> board = stringToBoard(puzzle);
        
        // Time the solve
        auto start = chrono::high_resolution_clock::now();
        bool success = solveSudokuBacktracking(board);
        auto end = chrono::high_resolution_clock::now();
        
        // Calculate time in microseconds
        chrono::duration<double, micro> duration = end - start;
        double timeMs = duration.count() / 1000.0;
        
        if (success) {
            solved++;
            totalTime += timeMs;
            minTime = min(minTime, timeMs);
            maxTime = max(maxTime, timeMs);
            
            // Verify solution
            bool correct = verifySolution(board, solution);
            if (!correct) {
                cout << "Warning: Puzzle " << puzzleNum << " solved incorrectly!" << endl;
            }
        } else {
            failed++;
            cout << "Failed to solve puzzle " << puzzleNum << endl;
        }
        
        // Print progress every 100 puzzles
        if ((puzzleNum + 1) % 100 == 0) {
            cout << "Processed " << (puzzleNum + 1) << " puzzles..." << endl;
        }
    }
    
    file.close();
    
    // Print statistics
    cout << "\n=== Benchmark Results ===" << endl;
    cout << "Total puzzles attempted: " << (solved + failed) << endl;
    cout << "Solved: " << solved << endl;
    cout << "Failed: " << failed << endl;
    cout << "Success rate: " << (100.0 * solved / (solved + failed)) << "%" << endl;
    
    if (solved > 0) {
        cout << "\nTiming Statistics (milliseconds):" << endl;
        cout << "Total Time: " << (totalTime) << " ms" << endl;
        cout << "Average time per puzzle: " << (totalTime / solved) << " ms" << endl;
        cout << "Min time per puzzle: " << minTime << " ms" << endl;
        cout << "Max time per puzzle: " << maxTime << " ms" << endl;
    }
}