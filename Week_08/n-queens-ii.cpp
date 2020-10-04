// 使用常规深度优先一层层搜索
// 使用三个整形分别标记每一层哪些格子可以放置皇后，这三个整形分别代表列、左斜下、右斜下（_col, ld, rd_），二进制位为 1 代表不能放置，0 代表可以放置
// 核心两个位运算：
// x & -x 代表除最后一位 1 保留，其它位全部为 0
// x & (x - 1) 代表将最后一位 1 变成 0


class Solution {
private:
    int res = 0;
public:
    int totalNQueens(int n) {
        dfs(n, 0, 0, 0, 0);
        
        return this->res;
    }
    
    void dfs(int n, int row, int col, int ld, int rd) {
        if (row >= n) { res++; return; }
        
        // 将所有能放置 Q 的位置由 0 变成 1，以便进行后续的位遍历
        int bits = ~(col | ld | rd) & ((1 << n) - 1);
        while (bits > 0) {
            int pick = bits & -bits; // 注: x & -x
            dfs(n, row + 1, col | pick, (ld | pick) << 1, (rd | pick) >> 1);
            bits &= bits - 1; // 注: x & (x - 1)
        }
    }
};
