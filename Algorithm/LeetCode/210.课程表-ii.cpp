/*
 * @lc app=leetcode.cn id=210 lang=cpp
 *
 * [210] 课程表 II
 */

// @lc code=start
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> res;
        vector<int> inDegree(numCourses, 0);
        unordered_map<int, set<int>> adject;
        queue<int> q;
        for(auto& i : prerequisites) {
            int a = i[0];  // a: course
            int b = i[1];  // b: a's dependency
            adject[b].insert(a);
            ++inDegree[a];
        }
        for(int i = 0; i < numCourses; i++) {
            if(inDegree[i] == 0) q.push(i);
        }

    }
};
// @lc code=end

