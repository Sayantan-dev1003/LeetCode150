class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();

        vector<int> flatBoard(n * n + 1, -1);
        int label = 1;
        bool leftToRight = true;

        for (int row = n - 1; row >= 0; row--) {
            if (leftToRight) {
                for (int col = 0; col < n; col++) {
                    flatBoard[label++] = board[row][col];
                }
            } else {
                for (int col = n - 1; col >= 0; col--) {
                    flatBoard[label++] = board[row][col];
                }
            }
            leftToRight = !leftToRight;
        }

        queue<int> q;
        vector<bool> visited(n * n + 1, false);
        q.push(1);
        visited[1] = true;
        int moves = 0;

        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                int curr = q.front();
                q.pop();

                if (curr == n * n)
                    return moves;

                for (int i = 1; i <= 6 && curr + i <= n * n; i++) {
                    int next = curr + i;
                    if (flatBoard[next] != -1) {
                        next = flatBoard[next];
                    }

                    if (!visited[next]) {
                        visited[next] = true;
                        q.push(next);
                    }
                }
            }
            moves++;
        }

        return -1;
    }
};
