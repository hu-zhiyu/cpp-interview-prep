/*
 * @lc app=leetcode.cn id=1013 lang=cpp
 *
 * [1013] 将数组分成和相等的三个部分
 */

// @lc code=start
class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        if(A.size() < 3) return false; 
        int i = 0, j, sum = 0, subSum1 = 0, subSum2 = 0, subSum3 = 0;
        for(int k = 0; k < A.size(); k++) sum += A[k];
        if(sum % 3 != 0) return false;
        sum = sum / 3;
        while(i < A.size()-2){
            subSum1 += A[i];
            if(subSum1 == sum){
                break;
            }
            i++;
        }
        if(i < A.size()-2) j = i + 1;
        else return false;
        while(j < A.size()-1){
            subSum2 += A[j];
            if(subSum2 == sum){
                break;
            }
            j++;
        }
        if(j < A.size()-1) return true;
        return false;       
    }
};
// @lc code=end

