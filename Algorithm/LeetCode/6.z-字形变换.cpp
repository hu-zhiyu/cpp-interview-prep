/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] Z 字形变换
 */

// @lc code=start
class Solution {
public:
    string convert(string s, int numRows) {
        string result;
        vector<string> temp(numRows);
        if(numRows == 1) return s;
        int intervalSum = 2 * (numRows - 1);
        for(int i = 0; i < numRows; i++) {
            int interval1 = 2 * (numRows - i - 1);
            int interval2 = intervalSum - interval1;
            int pos = i;
            bool flag = true;
            while(pos < s.size()) {
                temp[i].push_back(s[pos]);
                if(interval1 == 0 || interval2 == 0) {
                    pos += (interval1 == 0 ? interval2 : interval1);
                }
                else {
                    pos += (flag ? interval1 : interval2);
                    flag = (!flag);                    
                }
            }
        }
        for(int i = 0; i < numRows; i++) {
            cout << temp[i] << endl;
            result += temp[i];
        }
        return result;
    }
};
// @lc code=end

