class Solution {
public:
    bool validPalindrome(string s) {
        int left = 0, right = s.size() - 1;
        
        while (left < right) {
            char cl = s[left], cr = s[right];
            if (cl == cr) {
                left++;
                right--;
            } else {
                return checkPalindrome(s, left + 1, right) || checkPalindrome(s, left, right - 1);
            }
        }

        return true;
    }

    bool checkPalindrome(string s, int left, int right) {
        for (; left < right; left++, right--) {
            if (s[left] != s[right]) {
                return false;
            }
        }

        return true;
    }
};
