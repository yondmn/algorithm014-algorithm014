class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int sl = s.size(), tl = t.size();
        if (sl == 0 && tl == 0) {
            return true;
        }
        if (sl != tl) {
            return false;
        }

        for (int i = 0; i < sl; i++) {
            if (s.find(s[i]) != t.find(t[i])) {
                return false;
            }
        }

        return true;
    }
};
