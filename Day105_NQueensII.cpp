class Solution {
private:
    int solve(int row, int columns, int diag1, int diag2, int n) {
        if (row == n)
            return 1;

        int count = 0;
        int availablePositions = ((1 << n) - 1) & ~(columns | diag1 | diag2);

        while (availablePositions) {
            int position = availablePositions & -availablePositions;
            availablePositions -= position;
            count += solve(row + 1, columns | position, (diag1 | position) << 1,
                           (diag2 | position) >> 1, n);
        }

        return count;
    }

public:
    int totalNQueens(int n) { return solve(0, 0, 0, 0, n); }
};
