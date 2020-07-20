#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <cstdlib>
#include <unordered_map>
using namespace std;
class Solution1 {
    // 超时解法: 两层for循环
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

class Solution2 {
    // 归并排序
public:
    int reversePairs(vector<int> & nums) {
        if(nums.size() < 2) return 0;
        vector<int> temp(nums.size(), 0);
        return reversePairs(nums, 0, nums.size() - 1, temp);
    }
private:
    int reversePairs(vector<int>& nums, int begin, int end, vector<int>& temp){
        if(begin >= end) return 0; 
        int mid = begin + (end - begin) / 2;
        int leftPairs = reversePairs(nums, begin, mid, temp);
        int rightPairs = reversePairs(nums, mid + 1, end, temp);
        int crossPairs = mergeAndCount(nums, begin, mid, end, temp);
        return leftPairs + rightPairs + crossPairs;
    }
    int mergeAndCount(vector<int>& nums, int begin, int mid, int end, vector<int>& temp){
        for(int i = begin; i <= end; i++){
            temp[i] = nums[i];
        }
        int lptr = begin, rptr = mid + 1;  // lptr和rptr分别指向左右两个有序子数组的起始位置
        int count = 0;
        for(int k = begin; k <= end; k++){
            if(lptr == mid + 1){
                nums[k] = temp[rptr++];
            }
            else if(rptr == end + 1){
                nums[k] = temp[lptr++];
            }
            else if(temp[lptr] <= temp[rptr]){
                nums[k] = temp[lptr++];
            }
            else{
                nums[k] = temp[rptr++];
                count += mid - lptr + 1;
            }
        }
        return count;
    }
};

class Solution3 {
    // 
public:
    int reversePairs(vector<int>& nums, ) {
        

    }
};

int main(){
    Solution a;
    vector<int> input = {7,5,6,4};
    cout << a.reversePairs(input);
	return 0; 
}