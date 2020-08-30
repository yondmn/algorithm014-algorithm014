var permute = function(nums) {
    const res = [], track = [];
    backtrack(res, nums, track);
    return res;
};

var backtrack = function(res, nums, track) {
    const len = nums.length;
    if (track.length === len) {
        return res.push([...track]);
    }
    for (let i = 0; i < len; i++) {
        if (track.includes(nums[i])) {
            continue;
        }
        track.push(nums[i]);
        backtrack(res, nums, track);
        track.pop();
    }
}
