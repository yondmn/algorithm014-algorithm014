class Solution {
public:
    string removeOuterParentheses(string S) {
        string result;
        int l = 1, r = 0;

        for (int i = 1; i < S.size(); i++) {
            if (S[i] == '(') l++;
            else r++;

            if (l != r) result.push_back(S[i]);
            else {
                i++;
                l = 1;
                r = 0;
            }
        }
        
        return result;
    }
};
