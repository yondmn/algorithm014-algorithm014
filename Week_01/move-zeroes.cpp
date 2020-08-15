class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int length = nums.size();
        if (length <= 0) return;

        int slow = 0;
        for (int fast = 0; fast < length; fast++) {
            if (nums[fast] != 0) {
                nums[slow] = nums[fast];
                if (slow != fast) {
                    nums[fast] = 0;
                }
                slow++;
            }
        }
    }
};
