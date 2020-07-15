/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */
// @lc code=start
class Solution {
public:
    string minWindow(string s, string t) {
        int start;
        int min;
        int head = 0, tail = 0;
        string temp = t;
        unordered_map<char, int> m;
        for(int i = 0; i < s.size(); ++i){
            if(temp.find(s[i]) != temp.end()){
                // s[i] 在 temp 中
                start = i;
                m[s[i]] = i;
                temp.eraze(std::remove(temp.begin(), temp.end(), *(t.find(s[i]))), temp.end());
                if(temp.empty()){
                    // temp 被删空, 其中的字母都在 s 中被找到
                    min = i - 
                    i = 
                    temp = t;
                    continue;
                }
            }
            i = m[s[]];
        }
    }
};
// @lc code=end

