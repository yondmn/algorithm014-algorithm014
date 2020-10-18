class Solution {
public:
    int dp[10001];
    int racecar(int target) {
        if (dp[target] > 0) return dp[target];
        int n = floor(log2(target)) + 1;
        if (target + 1 == (1<<n)) {
            dp[target] = n;
        } else {
            // n个A到达2^n-1位置，然后R反向，走完剩余
            dp[target] = n + 1 + racecar((1<<n) - 1 - target);
            // n-1个A到达2^(n-1)-1位置，然后R反向走m个A，再R反向，走完剩余
            // m取值遍历[0, n-1)
            for (int m = 0; m < n-1; ++m) {
                dp[target] = std::min(dp[target], n + m + 1 + racecar(target - (1<<(n - 1)) + (1<<m)));
            }
        }

        return dp[target];
    }
};
