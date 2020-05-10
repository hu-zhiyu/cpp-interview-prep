/*
 * @lc app=leetcode.cn id=1143 lang=cpp
 *
 * [1143] 最长公共子序列
 */

// @lc code=start
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int len1 = text1.size();
        int len2 = text2.size();
        vector<vector<int> > len(len1+1, vector<int>(len2+1, 0));
        for(int i=1; i<len1+1; i++){
            for(int j=1; j<len2+1; j++){
                if(text1[i-1]==text2[j-1]){
                    len[i][j] = len[i-1][j-1] + 1;
                }
                else{
                    len[i][j] = len[i-1][j] > len[i][j-1] ? len[i-1][j] : len[i][j-1];
                }
            }
        }
        return len[len1][len2];       
    }
};
// @lc code=end

