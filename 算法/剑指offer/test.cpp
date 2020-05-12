#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;
static int num_board = 0;
static int row = 0;
static int col = 0;
static int num_word = 0;
static vector<vector<int>> flag;
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        num_board = sizeof(board)/sizeof(char);
        row = board.size();
        col = num_board / row;
        num_word = word.size();
        flag = vector<vector<int>>(row, vector<int>(col, 0));
        for(int i = 0; i < num_board; i++){
            if(search_path(board, word, i, 0))
                return true;
            else{
                std::fill(flag.begin(), flag.end(), vector<int>(col, 0));
                continue;
            }        
        }
        return false;
    }
    bool search_path(vector<vector<char>>& board, string word, int start, int count){
        if(count == word.size()) return true;
        if(start >= 0 && start < num_board && board[start / row][start % row] == word[count] && flag[start / row][start % row] == 0){
            flag[start / row][start % row] = 1;
            bool res =  search_path(board, word, start - 1, count + 1) ||
                        search_path(board, word, start + 1, count + 1) ||
                        search_path(board, word, start - col, count + 1) ||
                        search_path(board, word, start + col, count + 1);
            if(res) return true;
            else flag[start / row][start % row] = 0;
        }
        return false;
    }
};
int main(){
    Solution a;
    vector<vector<char>> board = {{'a','b','t','g'}, {'c','f','c','s'}, {'j','d','e','h'}};
    string word("abt");
    cout << a.exist(board, word) << endl;
}