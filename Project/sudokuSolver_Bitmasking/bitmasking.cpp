// C++ program to solve a Sudoku puzzle using the
// Bit masking approach
#include "bitmask_benchmark.h"
#include <iostream>
#include <vector>
// Size of the Sudoku board
#define N 9

using namespace std;

// Function to print the Sudoku board
void printBoard(const vector<vector<int> >& board)
{
    // Iterate over each row of the board
    for (int r = 0; r < N; r++) {
        // Iterate over each column of the board
        for (int d = 0; d < N; d++) {
            // Print each cell
            cout << board[r][d] << " ";
        }
        // New line after each row
        cout << endl;
    }
}

// Function to solve the Sudoku using Bit Masks approach
bool solveSudokuBitMasks(vector<vector<int> >& board,
                         vector<int>& rows,
                         vector<int>& cols,
                         vector<int>& grids)
{
    // Find the first empty cell
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            // Check if the cell is empty
            if (board[i][j] == 0) {
                // Determine the grid index (0-8) for the
                // 3x3 subgrid
                int grid = (i / 3) * 3 + j / 3;

                // Try placing numbers from 1 to 9
                for (int num = 1; num <= 9; num++) {
                    // Create a bitmask for the number
                    int bit = 1 << num;

                    // Check if the number can be placed in
                    // the current cell
                    if (!(rows[i] & bit) && !(cols[j] & bit)
                        && !(grids[grid] & bit)) {
                        // Place the number in the cell
                        board[i][j] = num;

                        // Update the bitmask for the row
                        rows[i] |= bit;

                        // Update the bitmask for the column
                        cols[j] |= bit;

                        // Update the bitmask for the 3x3
                        // subgrid
                        grids[grid] |= bit;

                        // Recursively attempt to solve the
                        // rest of the board
                        if (solveSudokuBitMasks(
                                board, rows, cols, grids)) {
                            return true; // If a solution is
                                         // found, return
                                         // true
                        }

                        // If placing num does not lead to a
                        // solution, undo the placement
                        // (backtrack) Reset the cell
                        board[i][j] = 0;

                        // Remove the bitmask for the row
                        rows[i] &= ~bit;

                        // Remove the bitmask for the column
                        cols[j] &= ~bit;

                        // Remove the bitmask for the 3x3
                        // subgrid
                        grids[grid] &= ~bit;
                    }
                }
                // No valid number found for this cell,
                // return false
                return false;
            }
        }
    }
    // All cells are filled correctly, return true
    return true;
}

int main()
{
    // Initial Sudoku board with some cells filled
   /* vector<vector<int> > board
        = { { 5, 3, 0, 0, 7, 0, 0, 0, 0 },
            { 6, 0, 0, 1, 9, 5, 0, 0, 0 },
            { 0, 9, 8, 0, 0, 0, 0, 6, 0 },
            { 8, 0, 0, 0, 6, 0, 0, 0, 3 },
            { 4, 0, 0, 8, 0, 3, 0, 0, 1 },
            { 7, 0, 0, 0, 2, 0, 0, 0, 6 },
            { 0, 6, 0, 0, 0, 0, 2, 8, 0 },
            { 0, 0, 0, 4, 1, 9, 0, 0, 5 },
            { 0, 0, 0, 0, 8, 0, 0, 7, 9 } };

    // Arrays to keep track of bitmasks for rows, columns,
    // and 3x3 subgrids Bitmasks for each row
    vector<int> rows(N, 0);

    // Bitmasks for each column
    vector<int> cols(N, 0);

    // Bitmasks for each 3x3 subgrid
    vector<int> grids(9, 0);

    // Initialize bitmasks based on the current state of the
    // board
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            // Check if the cell is not empty
            if (board[i][j] != 0) {
                int num = board[i][j];

                // Create a bitmask for the number
                int bit = 1 << num;

                // Update the bitmask for the row
                rows[i] |= bit;

                // Update the bitmask for the column
                cols[j] |= bit;

                // Update the bitmask for the 3x3 subgrid
                grids[(i / 3) * 3 + j / 3] |= bit;
            }
        }
    }

    // Solve the Sudoku and print the result
    if (solveSudokuBitMasks(board, rows, cols, grids)) {
        // Print the solved board
        printBoard(board);
    }
    else {
        // No solution found
        cout << "No solution exists" << endl;
    }
    */
    // CSV Benchmark
    cout << "CSV Benchmark:" << endl;
    benchmarkBitMask("sudoku.csv", 1000);
 


    return 0;
}