class Solution {
public:
    string replaceSpace(string s) {
        if (s.empty()) return s;
        int spaceCount = 0, i = s.size() - 1;
        for (auto c: s) {
            if (c == ' ') spaceCount++;
        }

        // 扩容
        s.resize(s.size() + spaceCount * 2);
        int j = s.size() - 1;
        while (i != j) {
            if (s[i] != ' ') {
                s[j] = s[i];
                i--;
                j--;
            } else {
                i--;
                s[j] = '0';
                s[j-1] = '2';
                s[j-2] = '%';
                j -= 3;
            }
        }

        return s;
    }
};
