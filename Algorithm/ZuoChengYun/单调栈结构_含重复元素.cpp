#include <vector>
#include <iostream>
#include <stack>
#include <list>
using namespace std;

int main() {
    int N, input;
    list<int> temp;
    cin >> N;
    vector<int> arr;
    vector<int> arrL(N, -1);
    vector<int> arrR(N, -1);
    stack<list<int>> s1;
    for(int i = 0; i < N; i++) {
        cin >> input;
        arr.push_back(input);
    }
    for(int i = 0; i < N;) {
        if(s1.empty() || arr[s1.top().front()] <= arr[i]) {
            if(!s1.empty() && arr[s1.top().front()] == arr[i]) s1.top().push_front(i);
            else s1.push({i});
            i++;
        }
        else {
            temp = s1.top();
            // int sz = temp.size();
            for(auto ele : temp) {
                arrR[ele] = i;
            }
            s1.pop();
            if(!s1.empty())
                for(auto ele : temp) 
                    arrL[ele] = s1.top().front();
            else
                for(auto ele : temp) 
                    arrL[ele] = -1;
        }
    }
    while(!s1.empty()) {
        temp = s1.top();
        // int sz = temp.size();
        for(auto ele : temp) {
            arrR[ele] = -1;
        }
        s1.pop();
        if(!s1.empty())
            for(auto ele : temp) 
                arrL[ele] = s1.top().front();
        else
            for(auto ele : temp) 
                arrL[ele] = -1;
    }
    for(int i = 0; i < N; i++) {
        cout << arrL[i] << ' ' << arrR[i] << endl;
    }
    return 0;
}