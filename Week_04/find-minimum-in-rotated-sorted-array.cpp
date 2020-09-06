class Solution {
public:
    int findMin(vector<int>& nums) {
        int len = nums.size();
        int left = 0, right = len - 1;

        while (left < right) {
            int mid = (left + right) / 2;
            int mV = nums[mid], rV = nums[right];
            if (mV < rV) {
                right = mid;
            } else if (mV == rV) {
                right--;
            } else if (mV > rV) {
                left = mid + 1;
            }
        }

        return nums[left];
    }
};
