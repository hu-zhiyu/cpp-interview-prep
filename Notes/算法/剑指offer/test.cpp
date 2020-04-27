// for testing code
#include <iostream>
#include <vector>
#include <math.h>
#define QUEEN_NUM 8
using namespace std;

// 判断当前参数给出的排列是否满足条件
bool is_valid(vector<int> & array){  
    for(int i=0; i<QUEEN_NUM-1; i++){
        for(int j=i+1; j<QUEEN_NUM; j++){
            // 同一行的情况不用判断
            if( array[i]==array[j] || (j-i)==abs(array[j]-array[i]) )
                return false;
        }
    }
    return true;
}

void swap(int & fir, int & sec){
    int temp = sec;
    sec = fir;
    fir = temp;
}

void permutation(vector<int> & queen_array, int begin, int & result){
    if(begin == QUEEN_NUM-1){
        if(is_valid(queen_array)){
            ++result;
        }
    }
    else{
        for(int i=begin; i<QUEEN_NUM; i++){
            swap(queen_array[i], queen_array[begin]);
            permutation(queen_array, begin+1, result);
            swap(queen_array[i], queen_array[begin]);
        }
    }
    
}

int main(){
    int result = 0; // 皇后的摆放方式总数
    int begin = 0;
    vector<int> queen_array = {1,2,3,4,5,6,7,8}; // 任意初始化皇后在每一行的位置，只需保证无相同的位置    
    permutation(queen_array, begin, result);
    cout << result << endl;
    return result;
}

