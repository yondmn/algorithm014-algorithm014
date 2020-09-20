class Solution {
public:
    long mod = 1e9 + 7;
    int checkRecord(int n) {
        if(n == 1) return 3;
        vector<vector<long>> dp(2, vector<long>(3, 0));
        dp[0][0] = 1;
        dp[0][1] = 1;
        dp[0][2] = 0;
        dp[1][0] = 1;
        dp[1][1] = 0;
        dp[1][2] = 0;
        vector<vector<long>> cur(2, vector<long>(3, 0));
        for(long i = 2; i <= n; i++){
            cur[0][0] = (dp[0][0] + dp[0][1] + dp[0][2]) % mod;
            cur[0][1] = dp[0][0];
            cur[0][2] = dp[0][1];
            cur[1][0] = (dp[0][0] + dp[0][1] + dp[0][2] + dp[1][0] + dp[1][1] + dp[1][2]) % mod;
            cur[1][1] = dp[1][0];
            cur[1][2] = dp[1][1];
            dp = cur;
        }
        int ans = (dp[0][0] + dp[0][1] + dp[0][2] + dp[1][0] + dp[1][1] + dp[1][2]) % mod;
        return ans;
    }
};
