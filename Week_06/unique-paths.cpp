class Solution {
public:
    int uniquePaths1(int m, int n) {
        if (m == 0 || n == 0) return 0;
        vector<vector<int>> dp(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) dp[i][0] = 1;
        for (int j = 0; j < n; j++) dp[0][j] = 1;

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }

        return dp[m - 1][n - 1];
    }

    int uniquePaths(int m, int n) {
      // 空间压缩
      int dp[n];
      for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
          if (i == 0 || j == 0) dp[j]  = 1;
          else dp[j] = dp[j-1] + dp[j];
        }
      }

      return dp[n - 1];
    }
};