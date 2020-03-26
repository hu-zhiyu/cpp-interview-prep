// for testing code
#include <iostream>
using namespace std;
// int fibonacci(int n){
//     if(n==0){ return 0;}
//     if(n==1){ return 1;}
//     return fibonacci(n-1) + fibonacci(n-2);
// }
long long fibonacci(int n){
    long long result = 0;
    long long temp_1 = 0;
    long long temp_2 = 1;
    long long temp_3 = 0;
    if(n==0) { result = 0; return 0;}
    if(n==1) { result = 1; return 1;}    
    for(int i=2; i<=n; i++){
        temp_3 = temp_2;
        temp_2 = temp_1 + temp_2;
        temp_1 = temp_3;
        result = temp_2;
    }
    cout << result << endl;
    return result;
}
int main(){
    int n = 0;
    int result;
    result = fibonacci(n);
    cout << result << endl;
}