#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;
class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0) return 1;
        double result = 1;
        int temp, flag = 1;
        double pow_temp = x;
        while(n){
            temp = (n & 1);
            (flag == 1) ? pow_temp = x : pow_temp = pow_temp * pow_temp;
            if(temp == 1) result *= pow_temp;
            n >> 1;
            flag = 0;
        }
        return result;
    }
};
int main(){
    Solution a;
    double temp = a.myPow(2.0, 4);
    cout << temp << endl;
}