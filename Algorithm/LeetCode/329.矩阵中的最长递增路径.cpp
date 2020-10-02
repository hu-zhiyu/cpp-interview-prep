/*
 * @lc app=leetcode.cn id=329 lang=cpp
 *
 * [329] 矩阵中的最长递增路径
 */

// @lc code=start
class Solution {
    // DFS + memorization
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int row = matrix.size();
        if(row == 0) return 0;
        int col = matrix[0].size();
        int res = 0;
        vector<vector<int>> dp(row, vector<int>(col, -1));
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                int tempRes = 1;
                tempRes = dfs(matrix, i, j, tempRes, dp);
                if(tempRes > res) res = tempRes;
            }
        }
        return res;
    }
    int dfs(vector<vector<int>>& matrix, int i, int j, int tempRes, vector<vector<int>>& dp) {
        if(isLast(matrix, i, j)) {
            dp[i][j] = tempRes;
            return tempRes;
        }
        int temp1 = 0, temp2 = 0, temp3 = 0, temp4 = 0;
        if(i - 1 >= 0) {
            if(dp[i-1][j] != -1 && matrix[i][j] < matrix[i-1][j]) temp1 = dp[i-1][j];
            else if(matrix[i][j] < matrix[i-1][j]) temp1 = dfs(matrix, i - 1, j, 1, dp);
            else temp1 = 0;
        }
        if(j - 1 >= 0) {
            if(dp[i][j-1] != -1 && matrix[i][j] < matrix[i][j-1]) temp2 = dp[i][j-1];
            else if(matrix[i][j] < matrix[i][j-1]) temp2 = dfs(matrix, i, j - 1, 1, dp);
            else temp2 = 0;
        }
        if(i + 1 < matrix.size()) {
            if(dp[i+1][j] != -1 && matrix[i][j] < matrix[i+1][j]) temp3 = dp[i+1][j];
            else if(matrix[i][j] < matrix[i+1][j]) temp3 = dfs(matrix, i + 1, j, 1, dp);
            else temp3 = 0;
        }
        if(j + 1 < matrix[0].size()) {
            if(dp[i][j+1] != -1 && matrix[i][j] < matrix[i][j+1]) temp4 = dp[i][j+1];
            else if(matrix[i][j] < matrix[i][j+1]) temp4 = dfs(matrix, i, j + 1, 1, dp);
            else temp4 = 0;
        }
        tempRes += maxOfFour(temp1, temp2, temp3, temp4);
        dp[i][j] = tempRes;
        return tempRes;
    }
    bool isLast(vector<vector<int>>& matrix, int i, int j) {
        bool res = true;
        if(i - 1 >= 0) res = res && matrix[i][j] >= matrix[i-1][j];
        if(j - 1 >= 0) res = res && matrix[i][j] >= matrix[i][j-1];
        if(i + 1 < matrix.size()) res = res && matrix[i][j] >= matrix[i+1][j];
        if(j + 1 < matrix[0].size()) res = res && matrix[i][j] >= matrix[i][j+1];
        return res;
    }
    int maxOfFour(int a, int b, int c, int d) {
        return max(max(max(a, b), c), d);
    }
};

class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        
    }  
};
// @lc code=end

