/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 */

// @lc code=start
class Solution {
public:
    int dirs[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    bool exist(vector<vector<char>>& board, string word) {
        if(board.empty()) return false;
        int row = board.size();
        int col = board[0].size();
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                if(board[i][j] != word[0]) continue;
                vector<vector<bool>> visit(row, vector<bool>(col, false));
                if(dfs(board, word, visit, i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
    bool dfs(vector<vector<char>>& board, string word, vector<vector<bool>>& visit, int i, int j, int k) {
        if(board[i][j] == word[k] && visit[i][j] == false) {
            if(k == word.size() - 1) return true;
            visit[i][j] = true;
            for(int dir = 0; dir < 4; dir++) {
                int di = dirs[dir][0];
                int dj = dirs[dir][1];
                if(i + di >= 0 && i + di < board.size() && j + dj >= 0 && j + dj < board[0].size())
                    if(dfs(board, word, visit, i + di, j + dj, k + 1)) return true;
            }
            visit[i][j] = false;
        }
        return false;
    }
};
// @lc code=end

