/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 */
// @lc code=start
class Solution {
    // BFS
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty()) return 0;
        int res = 0;
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == '1') {
                    dfs(grid, i, j);
                    res++;
                }
            }
        }
        return res;
    }
    void dfs(vector<vector<char>>& grid, int i, int j) {
        if(grid[i][j] == '0') return;
        grid[i][j] = '0';
        if(i - 1 >= 0) dfs(grid, i - 1, j);
        if(j - 1 >= 0) dfs(grid, i, j - 1);
        if(i + 1 < grid.size()) dfs(grid, i + 1, j);
        if(j + 1 < grid[0].size()) dfs(grid, i, j + 1);
    }
};
// @lc code=end

