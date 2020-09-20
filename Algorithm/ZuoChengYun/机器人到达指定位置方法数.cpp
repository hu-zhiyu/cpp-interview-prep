#include <iostream>
#include <vector>
using namespace std;

// 方法一: 暴力递归
void recursion(int N, int M, int K, int P, unsigned long long & res) {
    if(K == 0) {
        if(M == P) res++;
        return;
    }
    if(M == P) {
        if(M < N) recursion(N, M + 1, K - 1, P, res); 
        if(M > 1) recursion(N, M - 1, K - 1, P, res);
    }
    else {
        if(M < N) recursion(N, M + 1, K - 1, P, res);
        if(M > 1) recursion(N, M - 1, K - 1, P, res);
    }
    return;
}

// 方法二: 动态规划
unsigned long long findNumberOfMethods(int N, int M, int K, int P) {
    vector<vector<unsigned long long>> dp(N + 1, vector<unsigned long long>(K + 1, 0));
    dp[M][K] = 1;
    for(int j = K - 1; j >= 0; j--) {
        for(int k = 0; k <= N; k++) {
            if(k + 1 <= N && k - 1 >= 0)
                dp[k][j] = dp[k + 1][j + 1] + dp[k - 1][j + 1];
            else if(k + 1 <= N)
                dp[k][j] = dp[k + 1][j + 1];
            else
                dp[k][j] = dp[k - 1][j + 1];
        }
    }
    return dp[P][0];
}

int main() {
    int N, M, K, P;  // N:最大位置, M:当前所处位置, K:步数, P:指定位置
    cin >> N >> M >> K >> P;
    unsigned long long res = 0;
    res = findNumberOfMethods(N, M, K, P);
    cout << res % (unsigned long long)(1e9+7) << endl;
    return 0;
}