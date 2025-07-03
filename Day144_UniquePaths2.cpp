class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        if (obstacleGrid[0][0] == 1) {
            return 0;
        }

        vector<long long> dp(n, 0);

        dp[0] = 1;

        for (int j = 1; j < n; ++j) {
            if (obstacleGrid[0][j] == 0) {
                dp[j] = dp[j-1];
            } else {
                dp[j] = 0;
            }
        }

        for (int i = 1; i < m; ++i) {
            if (obstacleGrid[i][0] == 1) {
                dp[0] = 0;
            }
            for (int j = 1; j < n; ++j) {
                if (obstacleGrid[i][j] == 1) {
                    dp[j] = 0;
                } else {
                    dp[j] = dp[j] + dp[j-1];
                }
            }
        }

        return dp[n-1];
    }
};
