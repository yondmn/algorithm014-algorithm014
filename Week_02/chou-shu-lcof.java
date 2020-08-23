class Solution {
    private int[] uglyNumbers = {2, 3, 5};
    public int nthUglyNumber(int n) {
        // 利用小根堆
        Queue<Long> q = new PriorityQueue<>();
        q.add(1L);
        int count = 0;

        while (!q.isEmpty()) {
            long cut = q.poll();

            if (++count >= n) {
                return (int)cut;
            }

            for (int num: uglyNumbers) {
                if (!q.contains(cut * num)) {
                    q.add(cut * num);
                }
            }
        }
        return -1;
    };
}
