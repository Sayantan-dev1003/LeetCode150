class Solution {
private:
    bool dfs(std::vector<std::vector<char>>& board, const std::string& word,
             int index, int i, int j) {
        if (index == word.size())
            return true;

        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() ||
            board[i][j] != word[index])
            return false;

        char temp = board[i][j];
        board[i][j] = '#';

        bool found = dfs(board, word, index + 1, i + 1, j) ||
                     dfs(board, word, index + 1, i - 1, j) ||
                     dfs(board, word, index + 1, i, j + 1) ||
                     dfs(board, word, index + 1, i, j - 1);

        board[i][j] = temp;

        return found;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dfs(board, word, 0, i, j))
                    return true;
            }
        }

        return false;
    }
};
