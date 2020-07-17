#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <cstdlib>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int result = 0;
        for(int i = 0; i < nums.size(); i++){
            for(int j = i; j < nums.size(); j++){
                if(nums[i] > nums[j])
                    result++;
            }
        }
        return result;
    }
};
int main(){
    Solution a;
    vector<int> input = {7,5,6,4};
    cout << a.reversePairs(input);
	return 0; 
}