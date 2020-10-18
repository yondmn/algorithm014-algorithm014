class Solution {
public:
    string reverseWords(string s) {
        int length = s.size();
        if (length <= 0) return s;

        int l = 0, r = 0;
        while (l < length && r < length) {
            while (s[r] != ' ' && r < length) {
                r++;
            };

            reverse(s.begin() + l, s.begin() + r);
            while (s[r] == ' ' && r < length) {
                r++;
            }
            l = r;
        }

        return s;
    }
};