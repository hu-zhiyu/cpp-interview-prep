/*
 * @lc app=leetcode.cn id=1005 lang=cpp
 *
 * [1005] K 次取反后最大化的数组和
 */

// @lc code=start
class Solution {
public:
    int largestSumAfterKNegations(vector<int>& A, int K) {
        int result = 0;
        priority_queue<int, vector<int>, greater<int>> minHeap;  // 小顶堆
        for(int i = 0; i < A.size(); i++){
            minHeap.push(A[i]);  
        }
        while(K--){
            int temp = minHeap.top();
            minHeap.pop();
            minHeap.push(-temp);              
        }
        while(!minHeap.empty()){
            result += minHeap.top();
            minHeap.pop();
        }
        return result;
    }
};
// @lc code=end

// 排序，空间和时间复杂度更优的解法
class Solution {
public:
    int largestSumAfterKNegations(vector<int>& A, int K) {
        int result = 0;
        int numberOfNegativeDigits = 0;
        for(int i = 0; i < A.size(); i++){
            if(A[i] < 0) numberOfNegativeDigits++;
        }
        std::sort(A.begin(), A.end());
        if(numberOfNegativeDigits >= K){
            for(int i = 0; i < K; i++){
                A[i] = -A[i];
            }
        }
        if(numberOfNegativeDigits < K){
            int gap = K - numberOfNegativeDigits;
            if(gap % 2) { // 如果K和负数个数之间的差为奇数
                for(int i = 0; i < numberOfNegativeDigits; i++){
                    A[i] = -A[i];
                }
                std::sort(A.begin(), A.end());
                A[0] = -A[0];
            }
            else{ // 如果K和负数个数之间的差为偶数
                for(int i = 0; i < numberOfNegativeDigits; i++){
                    A[i] = -A[i];
                }
            }
        }
        for(int i = 0; i < A.size(); i++){
            result += A[i];
        }
        return result;
    }
};

