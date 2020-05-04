// for testing code
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;
struct listNode{
    int val;
    listNode* next;
    listNode(int a) : val(a), next(nullptr) {}
};

class Solution {
public:
    vector<int> a;
    vector<vector<int>> b;
    void a_init(vector<int> x = a){
        x.push_back(2);
    }
    void b_init(vector<vector<int>> y = b){
        for(int i = 0; i < 3; i++){
        y[i].push_back(2);
    }
    }
    
};

int main(){
    Solution S;
    S.a_init();
    S.b_init();
}

