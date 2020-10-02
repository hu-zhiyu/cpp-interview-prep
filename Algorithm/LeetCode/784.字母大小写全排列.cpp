/*
 * @lc app=leetcode.cn id=784 lang=cpp
 *
 * [784] 字母大小写全排列
 */

// @lc code=start
class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        int sz = S.size();
        int begin = 0;
        vector<string> res;
        permutationHelper(res, S, begin, sz);
        return res;
    }
    void permutationHelper(vector<string> & res, string& str, int i, int sz) {
        if(i == sz) {
            res.push_back(str);
            return;
        }
        if(isLetter(str[i])) {
            reverseCase(str[i]);
            permutationHelper(res, str, i + 1, sz);
            reverseCase(str[i]);
        }
        permutationHelper(res, str, i + 1, sz);
    }
    bool isLetter(char c) {
        if(c <= 'Z' && c >= 'A' || c <= 'z' && c >= 'a') return true;
        return false;
    }
    void reverseCase(char& c) {
        if(c <= 'Z' && c >= 'A') c = c + 32;
        else if(c <= 'z' && c >= 'a') c = c - 32;
        else return;
    }
};
// @lc code=end

