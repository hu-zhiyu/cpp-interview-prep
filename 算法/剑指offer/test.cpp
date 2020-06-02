#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;
int Partition(vector<int>& nums, int begin, int end) {
	int key = nums[end];//取最后一个
	int i = begin - 1;
	for (int j = begin; j < end; j++)
	{
		if (nums[j] <= key)
		{
			i++;
			//i一直代表小于key元素的最后一个索引，当发现有比key小的a[j]时候，i+1 后交换     
			swap(nums[i], nums[j]);
		}
	}
	swap(nums[i + 1], nums[end]);//将key切换到中间来，左边是小于key的，右边是大于key的值。
	return i + 1;
}
int main(){
    
}