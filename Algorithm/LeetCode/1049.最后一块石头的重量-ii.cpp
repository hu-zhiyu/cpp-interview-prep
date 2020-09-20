/*
 * @lc app=leetcode.cn id=1049 lang=cpp
 *
 * [1049] 最后一块石头的重量 II
 */

// @lc code=start
class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum = 0;
        for(int i = 0; i < stones.size(); i++) {
            sum += stones[i];
        }
        vector<bool> f(sum + 1, false);  // f(n)表示是否存在某种划分，使得某组的重量总和为n
        f[0] = true;
        for(int i = 0; i < stones.size(); i++) {
            for(int j = sum / 2; j >= stones[i]; j--) {
                f[j] = f[j] || f[j - stones[i]];
            }
        }
        for(int i = sum / 2; i >= 0; i--) {
            if(f[i])
                return sum - 2 * i;
        }
        return sum;
    }
};
// @lc code=end

