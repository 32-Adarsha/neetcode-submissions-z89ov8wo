#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> results;
        vector<string> board(n, string(n, '.'));

        vector<bool> col(n, false);
        vector<bool> leftDiag(2 * n - 1, false);   // indexed by (row - col + n - 1)
        vector<bool> rightDiag(2 * n - 1, false);  // indexed by (row + col)

        backtrack(0, n, board, col, leftDiag, rightDiag, results);
        return results;
    }

private:
    void backtrack(
        int row, int n,
        vector<string>& board,
        vector<bool>& col,
        vector<bool>& leftDiag,
        vector<bool>& rightDiag,
        vector<vector<string>>& results
    ) {
        // Base case: all n queens placed
        if (row == n) {
            results.push_back(board);
            return;
        }

        // Try placing a queen in each column of the current row
        for (int c = 0; c < n; c++) {
            int ld = row - c + n - 1;
            int rd = row + c;

            if (col[c] || leftDiag[ld] || rightDiag[rd])
                continue;

            // Place
            col[c] = leftDiag[ld] = rightDiag[rd] = true;
            board[row][c] = 'Q';

            backtrack(row + 1, n, board, col, leftDiag, rightDiag, results);

            // Remove (backtrack)
            col[c] = leftDiag[ld] = rightDiag[rd] = false;
            board[row][c] = '.';
        }
    }
};