impl Solution {
    pub fn remove_duplicates(nums: &mut Vec<i32>) -> i32 {
        let length = nums.len();
        // 如果数组长度小于 2，也就是 0 或 1 个元素那就直接返回
        if length < 2 {
            return length as i32;
        }
        // 慢指针起始位置 0
        let mut slow = 0;
        // 快指针作为数组循环下标
        for fast in 0..length {
            // 如果快慢指针位置数值不相等那么就快慢指针同时向前跑
            // 相等的话就快指针自己向前跑，一直跑到不相等，然后把慢指针位置的数字替换掉
            if nums[fast] != nums[slow] {
                slow += 1;
                nums[slow] = nums[fast];
            }
        }
        // slow 作为下标，题目要求返回其长度那么就将 slow + 1
        slow as i32 + 1
    }
}
