class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string track;

        backtrack(n, n, track, result);

        return result;
    }

    void backtrack(int left, int right, string& track, vector<string>& result) {
        // 如果左括号多，那么说明不合法
        if (left > right) return;
        // 如果左或者右小于 0 也不合法了
        if (left < 0 || right < 0) return;
        // 如果左右都等于 0 了，那说明所有括号匹配了，添加到 result 中
        if (left == 0 && right == 0) {
            result.push_back(track);
            return;
        }

        track.push_back('(');
        backtrack(left - 1, right, track, result);
        track.pop_back();

        track.push_back(')');
        backtrack(left, right - 1, track, result);
        track.pop_back();
    }
};