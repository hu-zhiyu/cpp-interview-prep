/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */
// @lc code=start
class Solution {
public:
    string minWindow(string s, string t) {
        int lptr = 0, rptr = -1;
        int start = -1, len = INT_MAX;
        unordered_map<char, int> sm, tm;
        for(const auto & i : t) {
            ++tm[i];
        }
        while(rptr < (int)s.size()) {
            if(tm.find(s[++rptr]) != tm.end()) {
                ++sm[s[rptr]];
            }
            while(cmpTwoMap(sm ,tm) && lptr <= rptr) {
                if(len > rptr - lptr + 1) {
                    start = lptr;
                    len = rptr - lptr + 1;
                }   
                if(tm.find(s[lptr]) != tm.end()) {
                    --sm[s[lptr]];
                }  
                ++lptr;           
            }
        }
        if(start == -1) return "";
        return s.substr(start, len);
    }
    bool cmpTwoMap(unordered_map<char, int>& sm, unordered_map<char, int>& tm) {  // 如果sm和tm相同，返回true
        for(const auto & i : tm) 
            if(i.second > sm[i.first]) return false;
        return true;
    }
}; 

// @lc code=end

