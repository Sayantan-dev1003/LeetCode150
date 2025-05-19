struct TrieNode {
    TrieNode* children[26] = {nullptr};
    string word = "";
};

class Solution {
private:
    TrieNode* buildTrie(vector<string>& words) {
        TrieNode* root = new TrieNode();
        for (string& word : words) {
            TrieNode* node = root;
            for (char c : word) {
                int idx = c - 'a';
                if (!node->children[idx]) {
                    node->children[idx] = new TrieNode();
                }
                node = node->children[idx];
            }
            node->word = word;
        }
        return root;
    }

    void dfs(vector<vector<char>>& board, int i, int j, TrieNode* node,
             unordered_set<string>& result) {
        char c = board[i][j];
        if (c == '#' || !node->children[c - 'a'])
            return;
        node = node->children[c - 'a'];
        if (!node->word.empty()) {
            result.insert(node->word);
            node->word = "";
        }

        board[i][j] = '#';
        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};

        for (int d = 0; d < 4; ++d) {
            int ni = i + dx[d], nj = j + dy[d];
            if (ni >= 0 && ni < board.size() && nj >= 0 &&
                nj < board[0].size()) {
                dfs(board, ni, nj, node, result);
            }
        }

        board[i][j] = c;
    }

public:
    vector<string> findWords(vector<vector<char>>& board,
                             vector<string>& words) {
        TrieNode* root = buildTrie(words);
        unordered_set<string> resultSet;
        int m = board.size(), n = board[0].size();

        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                dfs(board, i, j, root, resultSet);

        return vector<string>(resultSet.begin(), resultSet.end());
    }
};
