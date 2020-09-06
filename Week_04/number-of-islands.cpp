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

    void dfs(int i, int j, int column, int row, vector<vector<char>>& grid) {
        if (i < 0 || j < 0 || i >= column || j >= row || grid[i][j] == '0') {
            return;
        }
        
        grid[i][j] = '0';
        dfs(i - 1, j, column, row, grid);
        dfs(i + 1, j, column, row, grid);
        dfs(i, j - 1, column, row, grid);
        dfs(i, j + 1, column, row, grid);
    }
};
