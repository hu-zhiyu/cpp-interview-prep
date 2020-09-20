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
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                bfs(grid, res);
            }
        }
        return res;
    }
    void bfs(vector<vector<char>>& grid, int & res) {
        
    }
};
// @lc code=end

