class Solution {
public:
    string reverseStr(string s, int k) {
        if (s.size() <= 0 || k <= 1) return s;

        for (int i = 0, length = s.size(); i < length; i += (k * 2)) {
            if (i + k < length) {
                reverse(s.begin() + i, s.begin() + i + k);
                continue;
            }

            reverse(s.begin() + i, s.end());
        }

        return s;
    }
};