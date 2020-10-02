/*
 * @lc app=leetcode.cn id=207 lang=cpp
 *
 * [207] 课程表
 */

// @lc code=start
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, set<int>> adjcent;
        vector<int> indegree(numCourses);
        for (auto& edge : prerequisites) {
            int a = edge[0];
            int b = edge[1];
            adjcent[b].insert(a);
            ++indegree[a];
        }
        int count = 0;
        queue<int> todo;
        for (int i = 0; i < numCourses; ++i) {
            if (!indegree[i]) todo.push(i);
        }
        while (!todo.empty()) {
            auto v = todo.front();
            todo.pop();   
            ++count;
            auto& adjs = adjcent[v];
            for (auto adj : adjs) {
                --indegree[adj];
                if (!indegree[adj]) todo.push(adj);
            }
        }
        return count == numCourses;
    }
};
// @lc code=end

