/*
 * @lc app=leetcode.cn id=1042 lang=cpp
 *
 * [1042] 不邻接植花
 */

// @lc code=start
class Solution {
public:
    vector<int> ans;
    vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
        ans = vector<int>(N, 0); // 初始化全部未染色
        set<int> flower = {1,2,3,4};
        vector<int> G[N]; // 建立邻接表
        for(int i = 0; i < paths.size(); i++){
            G[paths[i][0] - 1].push_back(paths[i][1] - 1);
            G[paths[i][1] - 1].push_back(paths[i][0] - 1);
        }
        for(int i = 0; i < N; i++){ // 对给出的花园逐个种花
            set<int> flower = {1,2,3,4};
            for(int j = 0; j < G[i].size(); j++){
                flower.erase(ans[G[i][j]]);
            }
            ans[i] = *(flower.begin());
        }
        return ans;
    }
};
// @lc code=end

