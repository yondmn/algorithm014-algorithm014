class Solution {
public:
    string reverseOnlyLetters(string S) {
        int length = S.size();
        if (length == 0) return S;
        
        int l = 0, r = length - 1;
        while (l < r) {
            while (!isalpha(S[l]) && l < r) l++;
            while (!isalpha(S[r]) && l < r) r--;

            swap(S[l++], S[r--]);
        }

        return S;
    }
};
