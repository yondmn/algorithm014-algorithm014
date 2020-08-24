class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string track;

        backtrack(n, n, track, result);

        return result;
    }

    void backtrack(int left, int right, string& track, vector<string>& result) {
        // 右括号少，还不合法
        if (right < left) return;
        // 左或右小于 0 了也不合法
        if (left < 0 || right < 0) return;
        // 左右括号数量一致那么合法了
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
