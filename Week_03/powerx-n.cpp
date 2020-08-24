class Solution {
public:
    // 为什么改成 long long 就可以了，int 不行
    double myPow(double x, long long n) {
        double res;
        return n >= 0 ? helper(x, n) : 1.0 / helper(x, -n);
    }

    double helper(double x, int n) {
        if (n == 0) return 1.0;
        double res = helper(x, n / 2);
        return n % 2 == 0 ? res * res : res * res * x;
    }
};
