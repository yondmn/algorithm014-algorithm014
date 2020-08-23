class Solution {
public:
    // 用于构建小根堆 (C++ 中默认大根堆)
    struct cmp {
        bool operator()(pair<int, int>& a, pair<int, int>& b){ return a.second > b.second; }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ret;
        unordered_map<int, int> hash;
        for (auto a : nums) hash[a]++;

        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> mq;
        
        for (auto num: nums) hash[num]++;

        for (auto np: hash) {
            mq.push(np);
            if (mq.size() > k) mq.pop();
        }

        vector<int> result;

        while (!mq.empty()) {
            result.push_back(mq.top().first);
            mq.pop();
        }

        return result;
    }
};
