class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        deque<int> q;
        int length = nums.size();
        
        for (int i = 0; i < length; i++) {
            // 把队里内小的都给 pop 出去
            while (!q.empty() && nums[i] > nums[q.back()]) {
                q.pop_back();
            }

            // 窗口划过的给 pop 出去
            if (!q.empty() && q.front() < i - k + 1) q.pop_front();
            q.push_back(i);

            if (i >= k - 1) result.push_back(nums[q.front()]);
        }

        return result;
    }
};
