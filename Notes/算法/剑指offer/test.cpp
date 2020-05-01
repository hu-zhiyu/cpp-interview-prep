// for testing code
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.size();
        if(len==0){
            return 0;
        }
        if(len==1){
            return 1;
        }
        int win_size = 0;
        for(int i=0; i<len; i++){
            for(int j=i; j<len; j++){
                if(s.find(s[j+1], i)<=j && s.find(s[j+1], i)>=i ){
                    if(j-i+1 > win_size){
                        win_size = j-i+1;
                    }
                    break;
                }
                if(j-i+1 > win_size){
                    win_size = j-i+1;
                }
            }
        }
        return win_size;
    }
};

int main(){
    Solution a;
    string input1;
    cin >> input1;
    int len = input1.size();
    cout << len << endl;
    cout << input1[len];
}

