class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxp = nums[0], minp = nums[0], product = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            int mx = maxp, mn = minp;
            maxp = max(mx * nums[i], max(nums[i], mn * nums[i]));
            minp = min(mn * nums[i], min(nums[i], mx * nums[i]));
            product = max(maxp, product);
        }

        return product;
    }
};
