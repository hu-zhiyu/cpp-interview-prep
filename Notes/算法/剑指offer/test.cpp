// for testing code
#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    int solution_num = 0;
    vector<vector<int> > chessboard;
    vector<vector<int> > Eightqueens(){
    }
};

int main(){
    Solution a;
    vector<vector<int> > chessboard;
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            a.chessboard[i][j] = 0;
        }
    }
    chessboard = a.chessboard;
    cout << chessboard.size();
}