/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */

// @lc code=start
class Solution {
// dynamic programming solution
public:
    string longestPalindrome(string s) {
        int length = s.size();
        int start = 0;
        int max = 1; // 最长回文子串长度
        vector<vector<int> > flag(length, vector<int>(length));
        // memset(flag, 0, sizeof(flag));
        for(int i=0; i<length; i++){
            flag[i][i] = 1;
            if(s[i]==s[i+1]){
                flag[i][i+1] = 1;
                max = 2;
                start = i;
            }
        }
        for(int l=3; l<=length; l++){
            // 从长度为3的子串开始判断，找出长度最大的回文子串
            for(int i=0; i+l-1<length; i++){
                int j = i+l-1; // 判断终止位置
                if(s[i]==s[j] && flag[i+1][j-1]==1){
                    flag[i][j] = 1;
                    start = i;
                    max = l;
                }
            }
        }
        return s.substr(start,max);
    }
};
// @lc code=end

