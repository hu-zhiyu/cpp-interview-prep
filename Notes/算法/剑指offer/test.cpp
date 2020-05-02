// for testing code
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.empty()) return 0;
        if(s.size()==1) return 1;
        unordered_map<char,int> m;
        int head=0,res=0;
        for(int tail=0;tail<s.size();++tail)
        {
            if(m.find(s[tail])!=m.end()) head=max(m[s[tail]], head);
            m[s[tail]]=tail+1;
            res=max(res,tail-head+1);
        }
        return res;
    }
};

int main(){
    Solution a;
    string input1;
    cin >> input1;
    int len = a.lengthOfLongestSubstring(input1);
    cout << len << endl;
}

