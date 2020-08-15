class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int current = m + n - 1;

        while (current >= 0) {
            if (n == 0) return;

            // 如果 nums1 为 空
            if (m < 1) {
                nums1[current--] = nums2[--n];
                continue;
            }

            // 如果 nums2 为 空
            if (n < 1) {
                nums1[current--] = nums1[--m];
                continue;
            }

            // 从后先前那么就先放大的
            if (nums1[m -1] < nums2[n - 1]) {
                nums1[current--] = nums2[--n];
            } else {
                nums1[current--] = nums1[--m];
            }
        }
    }
};
