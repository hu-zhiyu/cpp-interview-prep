/*
 * @lc app=leetcode.cn id=62 lang=cpp
 *
 * [62] 不同路径
 */

// @lc code=start
/*
class Solution {
    // BFS, Time Limit Exceeded
public:
    int uniquePaths(int m, int n) {
        int res = 0;
        int start_x = 1, start_y = 1;
        int end_x = m, end_y = n;
        vector<vector<bool>> isVisited(m + 1, vector<bool>(n + 1, false));
        queue<pair<int, int>> q;
        q.push({1, 1});
        isVisited[1][1] = true;   

        while(!q.empty()) {
            pair<int, int> cur = q.front();
            q.pop();
            if(cur.first == m && cur.second == n) res++;
            else {
                if(cur.first < m && isVisited[cur.first + 1][cur.second] == false) {
                    q.push({cur.first + 1, cur.second});
                    isVisited[cur.first + 1][cur.second] == true;
                }
                if(cur.second < n && isVisited[cur.first][cur.second + 1] == false) {
                    q.push({cur.first, cur.second + 1});
                    isVisited[cur.first][cur.second + 1] == true;
                } 
            }
        }  
        return res;   
    }
};
*/
/*
class Solution {
    // DFS, Time Limit Exceeded
public:
    int uniquePaths(int m, int n) {
        int res = 0;
        int start_x = 1, start_y = 1;
        int end_x = m, end_y = n;
        dfs(start_x, start_y, end_x, end_y, res);
        return res;
    }
    void dfs(int start_x, int start_y, int end_x, int end_y, int & res) {
        if(start_x == end_x && start_y == end_y) {
            res++;
            return;
        }
        if(start_x <= end_x) dfs(start_x + 1, start_y, end_x, end_y, res);
        if(start_y <= end_y) dfs(start_x, start_y + 1, end_x, end_y, res);
        return;
    }
};
*/
class Solution {
    // DP
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for(int i = 1; i <= m; i++) dp[i][1] = 1;
        for(int i = 1; i <= n; i++) dp[1][i] = 1;
        for(int i = 2; i <= m; i++) {
            for(int j = 2; j <= n; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m][n];
    }

};
// @lc code=end

