#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;
class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {
        if(postorder.empty()) return true;
        return helper(postorder, 0, postorder.size()-1);
    }
    bool helper(vector<int>& postorder, int start, int end){
        if(start == end) return true;
        int l_start = start, l_end = end - 1, r_start = start, r_end = end - 1;
        for(int i = start; i < end; i++){
            if(postorder[i] < postorder[end]) l_end = i;
        }
        for(int i = start; i < end; i++){
            if(postorder[i] > postorder[end]){
                r_start = i;
                break;
            }
        }        
        if(l_end > r_start) return false;
        else if(l_start == l_end && r_start == r_end) return true;
        return helper(postorder, r_start, r_end) && helper(postorder, l_start, l_end); 
    }
};
int main(){
    Solution a;
    vector<int> nums = {1,3,2,6,5};
    // vector<int> nums = {4,8,6,12,16,14,10};
    // vector<int> nums = {10};
    bool result = a.verifyPostorder(nums);
    cout << result << endl;
    // for(int i = 0; i < result.size(); i++){
    //     cout << result[i] << endl;
    // }
}