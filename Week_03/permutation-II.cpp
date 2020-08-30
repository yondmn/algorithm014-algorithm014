class Solution {
public:
    
    vector<vector<int>> permuteUnique(vector<int>& a) {
        vector<vector<int>> res;
        backtrack(a, res, 0);
        return res;
    }
    void backtrack(vector<int>& a, vector<vector<int>>& res, int level) {
        if (level == a.size()) {
            res.push_back(a);
            return;
        }
        //枚举的时候去重，只用没有排过的
        unordered_set<int> uniq;
        for (int i = level; i < a.size(); ++i) {
            if (uniq.count(a[i])) {
                continue; //already used
            }
            swap(a[i], a[level]);
            backtrack(a, res, level+1);
            swap(a[i], a[level]);
            uniq.insert(a[i]);
        }
    }
};
