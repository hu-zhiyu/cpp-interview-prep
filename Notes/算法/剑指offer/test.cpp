// for testing code
#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    vector<vector<int> > chessboard;
    // 初始化为全0
    // for(auto chessboard[i]: chessboard){
    //     chessboard[i] = 0;
    // }
    // for(int i=0; i<8; i++){
    //     for(int j=0; i<8; i++){
    //         chessboard[i][j] = 0;
    //     }
    // }
};

int main(){
    Solution a;
    vector<vector<int> > chessboard;
    chessboard = a.chessboard;
    cout << chessboard;
}