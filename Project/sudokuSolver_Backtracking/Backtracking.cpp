// C++ program to solve a Sudoku puzzle using the Backtracking approach
#include "backtrack_benchmark.h"
#include <iostream>
#include <vector>
// Size of the Sudoku board
#define N 9

using namespace std;

unsigned int isSafeCallCount = 0; // how many times is isSafe function is called

// Function to print the Sudoku board
void printBoard(const vector<vector<int> >& board)
{
    for (int r = 0; r < N; r++) {
        for (int d = 0; d < N; d++) {
            // Print each cell
            cout << board[r][d] << " ";
        }
        // New line after each row
        cout << endl;
    }
}

// Function to check if placing a number in the cell is safe
bool isSafe(const vector<vector<int> >& board, int row,
            int col, int num)
{
    isSafeCallCount++;  
    // Check if the number is already present in the current row
    for (int x = 0; x < N; x++) {
        if (board[row][x] == num) {
            return false;
        }
    }

    // Check if the number is already present in the current column
    for (int x = 0; x < N; x++) {
        if (board[x][col] == num) {
            return false;
        }
    }

    // Check if the number is already present in the 3x3 subgrid
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[startRow + i][startCol + j] == num) {
                return false;
            }
        }
    }
    // Number can be safely placed
    return true;
}

// Function to solve the Sudoku using Backtracking approach
bool solveSudokuBacktracking(vector<vector<int> >& board)
{
    // To store the row index of the empty cell
    int row = -1;
    // To store the column index of the empty cell
    int col = -1;
    // Flag to check if there are any empty cells left
    bool isEmpty = true;

    // Find an empty cell in the Sudoku board
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j] == 0) {
                row = i;
                col = j;
                // Empty cell found
                isEmpty = false;
                break;
            }
        }
        if (!isEmpty) {
            break;
        }
    }

    // If no empty cell is found, Sudoku is solved
    if (isEmpty) {
        return true;
    }

    // Try placing numbers 1 to 9 in the empty cell
    for (int num = 1; num <= 9; num++) {
        // Check if placing num in the cell (row, col) is
        // safe
        if (isSafe(board, row, col, num)) {
            // Place the number
            board[row][col] = num;

            // Recursively attempt to solve the rest of the board
            if (solveSudokuBacktracking(board)) {
                // If a solution is found, return true
                return true;
            }

            // If placing num does not lead to a solution,
            // undo the placement (backtrack)
            board[row][col] = 0;
        }
    }
    // No solution found
    return false;
}

int main()
{
    // Initial Sudoku board with some cells filled for testing
   /* vector<vector<int> > board

        = {{0,0,4,3,0,0,2,0,9},
           {0,0,5,0,0,9,0,0,1},
           {0,7,0,0,6,0,0,4,3},
           {0,0,6,0,0,2,0,8,7},
           {1,9,0,0,0,7,4,0,0},
           {0,5,0,0,8,3,0,0,0},
           {6,0,0,0,0,0,1,0,5},
           {0,0,3,5,0,8,6,9,0},
           {0,4,2,9,1,0,3,0,0}}; 

    // Solve the Sudoku and print the result
    if (solveSudokuBacktracking(board)) {
        // Print the solved board
        printBoard(board);
        cout << endl;
    }
    else {
        // No solution found
        cout << "No solution exists" << endl;
    } */

    // CSV Benchmark
    cout << "CSV Benchmark:" << endl;
    benchmark("sudoku.csv", 100000);
    cout << "\nTotal isSafe() calls: " << isSafeCallCount << endl;

    return 0;
}
