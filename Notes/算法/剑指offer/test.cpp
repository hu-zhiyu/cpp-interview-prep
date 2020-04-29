// for testing code
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
class Solution {
public:
    int cutRope(int number) {
        int result;
        if(number<=1){return 0;}
        if(number==2){return 1;}
        if(number==3){return 2;}
        int * products = new int[number+1];
        products[0] = 0;
        products[1] = 1;
        products[2] = 2;
        products[3] = 3;
        for(int i=4; i<=number; i++){
            int max = 0;
            for(int j=1; j<=i/2; j++){
                products[i] = products[j] * products[i-j];
                if(products[i]>max){
                    max = products[i];
                }
            }
            products[i] = max;           
        }
        return products[number];    
    }
};

int main(){
    Solution a;
    int NUMBER;
    cin >> NUMBER;
    int result = a.cutRope(NUMBER);
    cout << result << endl;
    return result;
}

