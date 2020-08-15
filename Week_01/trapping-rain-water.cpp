class Solution {
public:
    // 备忘录解法 O(n) O(n)
    int trap1(vector<int>& height) {
        if (height.empty()) return 0;
        int length = height.size(), result = 0;
        vector<int> l_max(length), r_max(length);
        l_max[0] = height[0];
        r_max[length - 1] = height[length - 1];
        // 记录第 i 个位置的左边最大的柱子高度
        for (int i = 1; i < length; i++) {
            l_max[i] = max(height[i], l_max[i - 1]);
        }
        // 记录第 i 个位置的右边边最大的柱子高度
        for (int i = length - 2; i >= 0; i--) {
            r_max[i] = max(height[i], r_max[i + 1]);
        }
        
        // 一次求出总储水量就是总量
        for (int i = 1; i < length - 1; i++) {
            result += min(l_max[i], r_max[i]) - height[i];
        }

        return result;
    }

    // 双指针解法 O(n) O(1)
    int trap(vector<int>& height) {
        if (height.empty()) return 0;
        int length = height.size(), result = 0;
        int l_max = height[0], r_max = height[length - 1], left = 0, right = length - 1;
        while (left <= right) {
            // 左右指针边走边记录 left 左边 或者 right 右边最高的柱子
            l_max = max(l_max, height[left]);
            r_max = max(r_max, height[right]);
        
            if (l_max < r_max) {
                // 如果左边最高的比较低，那么看左边的就行了
                result += l_max - height[left];
                left++;
            } else {
                // 否则就看右边的
                result += r_max - height[right];
                right--;
            }
        }

        return result;
    }
};