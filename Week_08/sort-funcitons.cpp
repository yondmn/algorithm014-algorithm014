#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <exception>

using namespace std;

class Solution {
public:
    void bubbleSort(vector<int>& nums) {
        int length = nums.size();
        if (length == 0) return;

        for (int i = 0; i < length; i++) {
            for (int j = 0; j < length - i - 1; j++) {
                if (nums[j] > nums[j + 1]) {
                    swap(nums[j], nums[j + 1]);
                }
            }
        }
    }

    void selectionSort(vector<int>& nums) {
        int length = nums.size();
        if (length == 0) return;

        for (int i = 0; i < length; i++) {
            int minIndex = i;
            for (int j = i; j < length; j++) {
                if (nums[j] < nums[minIndex]) {
                    minIndex = j;
                }
            }

            swap(nums[i], nums[minIndex]);
        }
    }

    void insertinSort(vector<int>& nums) {
        int length = nums.size();
        if (length <= 1) return;

        for (int i = 1; i < length; i++) {
            int preIndex = i - 1;
            int current = nums[i];

            while (preIndex >= 0 && current < nums[preIndex]) {
                nums[preIndex + 1] = nums[preIndex];
                preIndex--;
            }

            nums[preIndex + 1] = current;
        }
    }

    void shellSort(vector<int>& nums) {
        int length = nums.size();
        if (length <= 1) return;

        for (int gap = length / 2; gap > 0; gap = gap / 2) {
            // 多个分组交替执行
            for (int i = gap; i < length; i++) {
                int j = i;
                int current = nums[i];
                while (j - gap >= 0 && current < nums[j - gap]) {
                    nums[j] = nums[j - gap];
                    j = j - gap;
                }
                nums[j] = current;
            }
        }
    }
};

void coutVector(vector<int> nums) {
    for (auto num: nums)
        cout << num << " ";
}

int main() {
    vector<int> nums = {4, 23, 32, 1, 3, 12, 5, 54};
    Solution* solution = new Solution();
    solution->shellSort(nums);
    coutVector(nums);
    return 1;
}
