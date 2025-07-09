class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty())
            return 0;
        int m = matrix.size(), n = matrix[0].size();
        vector<int> dp(n + 1, 0);
        int maxLen = 0, prev = 0;

        for (int i = 1; i <= m; ++i) {
            prev = 0;
            for (int j = 1; j <= n; ++j) {
                int temp = dp[j];
                if (matrix[i - 1][j - 1] == '1') {
                    dp[j] = min({dp[j], dp[j - 1], prev}) + 1;
                    maxLen = max(maxLen, dp[j]);
                } else {
                    dp[j] = 0;
                }
                prev = temp;
            }
        }

        return maxLen * maxLen;
    }
};
