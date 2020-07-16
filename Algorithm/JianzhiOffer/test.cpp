#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <cstdlib>
using namespace std;
class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        if(grid.empty()) return 0;
        vector<vector<int>> dp = grid;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(i == 0 && j == 0) continue;
                else if(i == 0) dp[i][j] += dp[i][j-1];
                else if(j == 0) dp[i][j] += dp[i-1][j];
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[grid.size() - 1][grid[0].size() - 1];
    }
};
int main(){
    Solution a;
    a.translateNum(12258);
	return 0; 
}