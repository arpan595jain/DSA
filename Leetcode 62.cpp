class Solution {
public:
    int dp[103][103];
    int uniquePaths(int m, int n) {
        dp[1][1] = 1;
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                dp[i][j] = max(dp[i][j], dp[i-1][j]+dp[i][j-1]);
            }
        }
        return dp[m][n];
    }
};
