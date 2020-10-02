/*
 * @lc app=leetcode.cn id=542 lang=cpp
 *
 * [542] 01 矩阵
 */

// @lc code=start
class Solution {
private:
    int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        vector<vector<int>> res(matrix.size(), vector<int>(matrix[0].size(), -1));
        queue<pair<int, int>> q;
        if(matrix.size() == 0) return res;
        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < matrix[0].size(); j++) {
                if(matrix[i][j] == 0) {
                    res[i][j] = 0;
                    q.push({i, j});
                }       
            }
        }
        while(!q.empty()) {
            auto p = q.front();
            q.pop();
            for(int i = 0; i < 4; i++) {
                int x = p.first + dirs[i][0];
                int y = p.second + dirs[i][1];
                if(x >= 0 && y >= 0 && x < matrix.size() && y < matrix[0].size() && res[x][y] == -1) {
                    res[x][y] = res[p.first][p.second] + 1;
                    q.push({x, y});
                }
            }
        }
        return res;
    }
};
// @lc code=end

