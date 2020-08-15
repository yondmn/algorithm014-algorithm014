class Solution {    
    void rotate(vector<int>& nums, int k) {
        int length = nums.size();
        // 对 k 进行取模，防止 k 大于 length 的情况做多余的操作
        k = k % length;

        // count 记录替换次数，最大就是数组长度
        int count = 0;
        for (int i = 0; count < length; i++) {
            int prev = nums[i];
            int current = i;
            do {
                int next = (current + k) % length;
                int temp = nums[next];
                nums[next] = prev;
                prev = temp;
                current = next;
                count++;
            } while (i != current);
        }
    }
}
