// C++ program to solve a Sudoku puzzle using the Naive
// approach

#include <iostream>
#include <vector>
using namespace std;
// Size of the Sudoku board
#define N 9

// Function to print the board
void printBoard(const vector<vector<int> >& board)
{
    for (int r = 0; r < N; r++) {
        for (int d = 0; d < N; d++) {
            cout << board[r][d] << " ";
        }
        cout << endl;
    }
}

// Function to check if it is safe to place a number in the
// cell
bool isSafe(const vector<vector<int> >& board, int row,
            int col, int num)
{
    // Check if the number is already present in the current
    // row, column or 3x3 subgrid
    for (int x = 0; x < N; x++) {
        // Check the row
        if (board[row][x] == num) {
            return false;
        }
        // Check the column
        if (board[x][col] == num) {
            return false;
        }
        // Check the 3x3 subgrid
        if (board[row - row % 3 + x / 3]
                 [col - col % 3 + x % 3]
            == num) {
            return false;
        }
    }
    return true; // Safe to place the number
}

// Function to solve the Sudoku using Naive approach
bool solveSudokuNaive(vector<vector<int> >& board)
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

    if (isEmpty) {
        // No empty cells left, solution found
        return true;
    }

    // Try placing numbers 1 to 9 in the empty cell
    for (int num = 1; num <= 9; num++) {
        if (isSafe(board, row, col, num)) {
            // Place the number
            board[row][col] = num;
            if (solveSudokuNaive(board)) {
                // If placing the number leads to a
                // solution, return true
                return true;
            }
            // Undo the placement (backtracking)
            board[row][col] = 0;
        }
    }
    // No solution found
    return false;
}

int main()
{
    // Initial Sudoku board with some cells filled
    vector<vector<int> > board
        = { { 5, 3, 0, 0, 7, 0, 0, 0, 0 },
            { 6, 0, 0, 1, 9, 5, 0, 0, 0 },
            { 0, 9, 8, 0, 0, 0, 0, 6, 0 },
            { 8, 0, 0, 0, 6, 0, 0, 0, 3 },
            { 4, 0, 0, 8, 0, 3, 0, 0, 1 },
            { 7, 0, 0, 0, 2, 0, 0, 0, 6 },
            { 0, 6, 0, 0, 0, 0, 2, 8, 0 },
            { 0, 0, 0, 4, 1, 9, 0, 0, 5 },
            { 0, 0, 0, 0, 8, 0, 0, 7, 9 } };

    // Solve the Sudoku and print the result
    if (solveSudokuNaive(board)) {
        // Print the solved board
        printBoard(board);
    }
    else {
        // No solution found
        cout << "No solution exists" << endl;
    }

    return 0;
}
