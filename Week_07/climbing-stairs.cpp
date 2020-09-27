class Solution {
public:
    int climbStairs(int n) {
      if (n < 3) return n;
      int first = 1, second = 2, sum = 0;
      for (int i = 3; i <= n; i++) {
        sum = first + second;
        first = second;
        second = sum;
      }

      return sum;
    }
};
