/*
 * @lc app=leetcode.cn id=59 lang=cpp
 *
 * [59] 螺旋矩阵 II
 */

// @lc code=start
class Solution {
public:
    int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};  // right, downward, left, upward
    vector<vector<int>> generateMatrix(int n) {
        int count = 1;
        int turnCount = 0;
        vector<vector<int>> res(n, vector<int>(n, false));
        vector<vector<bool>> vis(n, vector<bool>(n, false));
        dfs(res, vis, 0, 0, count, turnCount, n);
        return res;
    }
    void dfs(vector<vector<int>>& res, vector<vector<bool>>& vis, int i, int j, int count, int turnCount, int n) {
        vis[i][j] = true;
        res[i][j] = count;
        if(count == n * n) return;
        int dirIdx = turnCount % 4;
        int x = i + dirs[dirIdx][0];
        int y = j + dirs[dirIdx][1];
        if(x >= 0 && x < n && y >= 0 && y < n && !vis[x][y]) {
            dfs(res, vis, x, y, count + 1, turnCount, n);
        }
        else {
            dirIdx = (turnCount + 1) % 4;
            x = i + dirs[dirIdx][0];
            y = j + dirs[dirIdx][1];
            dfs(res, vis, x, y, count + 1, turnCount + 1, n);
        }
    }
};
// @lc code=end

