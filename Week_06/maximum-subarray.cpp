class Solution {
public:
    int maxSubArray(vector<int>& nums) {
      int temp = 0, sum = nums[0];

      for (int num: nums) {
        temp = max(temp + num, num);
        sum = max(temp, sum);
      }

      return sum;
    }
};