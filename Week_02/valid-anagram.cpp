class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;

        unordered_map<char, int> m;
        for (char c: s) {
            ++m[c];
        }

        for (char c: t) {
            if (m.count(c)) {
                --m[c];
                if (m[c] == 0) {
                    m.erase(c);
                }
            } else {
                return false;
            }
        }

        return true;
    }

    bool isAnagram1(string s, string t) {
        if (s.size() != t.size()) return false;

        unordered_map<char, int> m;
        for (int i = 0; i < s.size(); ++i) {
            m[s[i]]++;
            m[t[i]]--;
        }
        for (auto c: m) {
            if (m.second) return false;
        }

        return true;
    }
};