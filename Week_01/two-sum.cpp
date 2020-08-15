class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        unordered_map<int, int> hash;
        for (int i = 0; i < nums.size(); i++) {
            if (hash[target - nums[i]]) {
                result = {hash[target - nums[i]] - 1, i};
            } else {
                hash[nums[i]] = i + 1;
            }
        }

        return result;
    }
};