class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == '1') {
                    count++;
                    dfs(i, j, grid.size(), grid[i].size(), grid);
                }
            }
        }

        return count;
    }

    void dfs(int row, int col, int rows, int cols, vector<vector<char>>& grid) {
        if (row < 0 || col < 0 || row >= rows || col >= cols || grid[row][col] == '0') {
            return;
        }

        grid[row][col] = '0';

        dfs(row - 1, col, rows, cols, grid);
        dfs(row + 1, col, rows, cols, grid);
        dfs(row, col - 1, rows, cols, grid);
        dfs(row, col + 1, rows, cols, grid);
    }
};
