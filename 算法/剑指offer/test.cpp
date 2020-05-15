#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;
class Solution {
public:
    int movingCount(int m, int n, int k) {
        if (!k) return 1;
        queue<pair<int,int> > Q;
        // 向右和向下的方向数组
        int dx[2] = {0, 1};
        int dy[2] = {1, 0};
        vector<vector<int> > vis(m, vector<int>(n, 0));
        Q.push(make_pair(0, 0));
        vis[0][0] = 1;
        int ans = 1;
        while (!Q.empty()) {
            auto [x, y] = Q.front();
            Q.pop();
            for (int i = 0; i < 2; ++i) {
                int tx = dx[i] + x;
                int ty = dy[i] + y;
                if (tx < 0 || tx >= m || ty < 0 || ty >= n || vis[tx][ty] || calDigits(tx) + calDigits(ty) > k) continue;
                Q.push(make_pair(tx, ty));
                vis[tx][ty] = 1;
                ans++;
            }
        }
        return ans;
    }
    int calDigits(int m){
        int sum = 0;
        while((m / 10) != 0 || (m % 10) != 0){
            sum += m % 10;
            m = m / 10;
        }
        return sum;
    }
};
int main(){
    Solution a;
    int temp = a.movingCount(38,15,9);
    cout << temp <<endl;
}