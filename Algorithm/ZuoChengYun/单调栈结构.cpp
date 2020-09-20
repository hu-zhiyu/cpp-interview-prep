#include <vector>
#include <iostream>
#include <stack>
using namespace std;

int main() {
    int N, temp;
    cin >> N;
    vector<int> arr;
    vector<int> arrL(N, -1);
    vector<int> arrR(N, -1);
    stack<int> s1;
    for(int i = 0; i < N; i++) {
        cin >> temp;
        arr.push_back(temp);
    }
    for(int i = 0; i < N;) {
        if(s1.empty() || arr[s1.top()] < arr[i]) {
            s1.push(i);
            i++;
        }
        else {
            temp = s1.top();
            arrR[temp] = i;
            s1.pop();
            if(!s1.empty())
                arrL[temp] = s1.top();
            else
                arrL[temp] = -1;
        }
    }
    while(!s1.empty()) {
        temp = s1.top();
        arrR[temp] = -1;
        s1.pop();
        if(!s1.empty())
            arrL[temp] = s1.top();
        else
            arrL[temp] = -1;
    }
    for(int i = 0; i < N; i++) {
        cout << arrL[i] << ' ' << arrR[i] << endl;
    }
    return 0;
}