class Solution {
private:
    int rows, columns;
public:
    void dfs(vector<vector<char>>& board, int x, int y) {
        if (x < 0 || x >= rows || y < 0 || y >= columns || board[x][y] != 'O') {
            return;
        }

        board[x][y] = 'A';
        dfs(board, x - 1, y);
        dfs(board, x + 1, y);
        dfs(board, x, y - 1);
        dfs(board, x, y + 1);
    }
    void solve(vector<vector<char>>& board) {
        rows = board.size();
        if (rows == 0) return;
        columns = board[0].size();

        for (int i = 0; i < rows; i++) {
            dfs(board, i, 0);
            dfs(board, i, columns - 1);
        }
        for (int i = 0; i < columns; i++) {
            dfs(board, 0, i);
            dfs(board, rows - 1, i);
        }

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                if (board[i][j] == 'A') {
                    board[i][j] = 'O';
                } else if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }
};
