class Solution {
private:
    vector<vector<int>> res;
public:
    vector<vector<int>> combine(int n, int k) {
        if (n <= 0 || k <= 0) return res;
        vector<int> path;
        dfs(n, k, 1, path);
        return res;
    }

    void dfs(int n, int k, int start, vector<int>& path) {
        if (path.size() == k) {
            res.push_back(path);
            return;
        }

        for (int i = start; i <= n - (k - path.size()) + 1; i++) {
            path.push_back(i);
            dfs(n, k, i + 1, path);
            path.pop_back();
        }
    }
};
