class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size(), n = board[0].size();

        vector<vector<int>> directions = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1},
                                          {0, 1},   {1, -1}, {1, 0},  {1, 1}};

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int liveNeighbors = 0;

                for (auto& dir : directions) {
                    int ni = i + dir[0], nj = j + dir[1];
                    if (ni >= 0 && ni < m && nj >= 0 && nj < n &&
                        abs(board[ni][nj]) == 1) {
                        liveNeighbors++;
                    }
                }

                if (board[i][j] == 1 && (liveNeighbors < 2 || liveNeighbors > 3)) {
                    board[i][j] = -1;
                }
                if (board[i][j] == 0 && liveNeighbors == 3) {
                    board[i][j] = 2;
                }
            }
        }

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == -1)
                    board[i][j] = 0;
                if (board[i][j] == 2)
                    board[i][j] = 1;
            }
        }
    }
};
