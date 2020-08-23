class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        int length = arr.size();
        vector<int> result;
        if (k == 0) return result;
        // 1. 排序后取前 k 个
        // sort(arr.begin(), arr.end());

        // for (int i = 0; i < k; ++i) {
        //     result.push_back(arr[i]);
        // }


        // 2. 维护一个大根堆，C++ 默认是大根堆, 所以堆顶就是最大的
        priority_queue<int> Q;
        for (int i = 0; i < k; ++i) Q.push(arr[i]);

        for (int i = k; i < length; ++i) {
            if (Q.top() > arr[i]) {
                Q.pop();
                Q.push(arr[i]);
            }
        }

        for (int i = 0; i < k; ++i) {
            result.push_back(Q.top());
            Q.pop();
        }


        // 3. 利用快排思想
        // 我们可以借鉴快速排序的思想。我们知道快排的划分函数每次执行完后都能将数组分成两个部分，
        // 小于等于分界值 pivot 的元素的都会被放到数组的左边，大于的都会被放到数组的右边，然后返回分界值的下标。
        // 与快速排序不同的是，快速排序会根据分界值的下标递归处理划分的两侧，而这里我们只处理划分的一边。
        // 我们定义函数 randomized_selected(arr, l, r, k) 表示划分数组 arr 的 [l,r] 部分，使前 k 小的数在数组的左侧，
        // 在函数里我们调用快排的划分函数，假设划分函数返回的下标是 pos（表示分界值 pivot 最终在数组中的位置）
        // 即 pivot 是数组中第 pos - l + 1 小的数，那么一共会有三种情况：
        // 如果 pos - l + 1 == k，表示 pivot 就是第 kk 小的数，直接返回即可；
        // 如果 pos - l + 1 < k，表示第 kk 小的数在 pivot 的右侧，因此递归调用 randomized_selected(arr, pos + 1, r, k - (pos - l + 1))；
        // 如果 pos - l + 1 > k，表示第 kk 小的数在 pivot 的左侧，递归调用 randomized_selected(arr, l, pos - 1, k)。
        // 函数递归入口为 randomized_selected(arr, 0, arr.length - 1, k)。在函数返回后，将前 k 个数放入答案数组返回即可。

        return result;
    }
};
