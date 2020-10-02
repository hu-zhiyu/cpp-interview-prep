/*
 * @lc app=leetcode.cn id=1293 lang=cpp
 *
 * [1293] 网格中的最短路径
 */

// @lc code=start
struct Point {
    int x, y;
    int oneCount;  // oneCount 记录到(x, y)时还有多少次消除障碍物的机会
};
class Solution {
    // BFS 解法
public:
    int dirs[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        if(m == 1 && n == 1) return 0;
        queue<Point> q;
        // visit[i][j] 记录遍历到(i,j)时还有多少次消除障碍物的机会, 越多越好(贪心), 初始化为-1
        vector<vector<int>> visit(m, vector<int>(n, -1));
        int res = 0;
        q.push({0, 0, k});
        visit[0][0] = k;
        while(!q.empty()) {
            res++;
            int sz = q.size();
            for(int i = 0; i < sz; i++) {
                Point temp = q.front();
                q.pop();
                for(int dir = 0; dir < 4; dir++) {
                    int x1 = temp.x + dirs[dir][0];
                    int y1 = temp.y + dirs[dir][1];
                    if(!isValid(x1, y1, m, n)) {
                        continue;
                    }
                    if(temp.oneCount - grid[x1][y1] == -1) {
                        continue;
                    }
                    if(x1 == m - 1 && y1 == n - 1) {
                        return res;
                    }
                    if(visit[x1][y1] == -1 || visit[x1][y1] < temp.oneCount - grid[x1][y1]) {
                        visit[x1][y1] = temp.oneCount - grid[x1][y1];
                        q.push({x1, y1, visit[x1][y1]});
                    }
                }
            }
        }
        return -1;
    }
    bool isValid(int i, int j, int m, int n) {
        if(i >= 0 && i < m && j >= 0 && j < n) return true;
        return false;
    }
};
/*
class Solution {
    // DFS 解法, 超时
public:
    int dirs[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    int shortestPath(vector<vector<int>>& grid, int k) {
        int res = -1;
        int m = grid.size();
        int n = grid[0].size();
        int step = 0;
        vector<vector<bool>> visit(m, vector<bool>(n, false));
        dfs(grid, visit, k, 0, 0, m, n, step, res);
        return res;
    }
    void dfs(vector<vector<int>>& grid, vector<vector<bool>>& visit, int k, int i, int j, int m, int n, int step, int& res) {
        // 递归终止条件: 1) 跳出网格(已做检查) 2) 次数 K 用完 3) 到达网格右下角
        if(k < 0) return;
        if(i == m - 1 && j == n - 1) {
            if(res == -1 || step < res) res = step;
            return;
        }
        if(res != -1 && step >= res) return;
        visit[i][j] = true;
        for(int dir = 0; dir < 4; dir++) {
            int di = dirs[dir][0];
            int dj = dirs[dir][1];
            if(isValid(i + di, j + dj, m, n) && !visit[i+di][j+dj]) dfs(grid, visit, k - grid[i+di][j+dj], i + di, j + dj, m, n, step + 1, res);
        }
        visit[i][j] = false;
    }
    bool isValid(int i, int j, int m, int n) {
        if(i >= 0 && i < m && j >= 0 && j < n) return true;
        return false;
    }
};
*/
// @lc code=end

