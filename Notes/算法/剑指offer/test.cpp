// for testing code
#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    vector<string> result;
    int begin = 0;
    vector<string> Combination(string str){
        if(str.empty()){
            return result;
        }
        Combination(str, result, begin);
        return result;
    }
    void Combination(string str, vector<string> & result, int begin){
        // 终止条件
        if(begin == str.size()-1){
            cout << "terminated" << endl;
            string last(1, str[begin]);
            result.push_back(last);
        }
        else{
            Combination(str, result, begin+1);
            int result_length = result.size();
            vector<string> temp = result;
            cout << "testing" << endl;
            string s(1, str[begin]);
            for(int i=0; i<result_length; i++){
                result.push_back(s+temp[i]);
            }
            result.push_back(s);
        }           
    }
};

int main(){
    vector<string> result;
    Solution a;
    result = a.Combination("abcd");
    for(int i=0; i<result.size(); i++){
        cout << result[i] << endl;
    }
    cout << "total numbers: " << result.size();
}