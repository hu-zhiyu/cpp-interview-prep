#include <iostream>
#include <vector>
#include <stack>

using namespace std;
template<typename T>
class MyQueue {
private:
    stack<T> s1;
    stack<T> s2;
public:
    void add(T ele) {
        s1.push(ele);
    }
    void poll() {
        while(!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
        s2.pop();
        while(!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
    }
    T peek() {
        while(!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
        T temp = s2.top();
        cout << temp << endl;
        while(!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
        return temp;
    }
};

int main() {
    int N, ele;
    cin >> N;
    string cmd;
    MyQueue<int> mq;
    for(int i = 0; i < N; i++) {
        cin >> cmd;
        if(cmd == "add") {
            cin >> ele;
            mq.add(ele);
        }
        else if(cmd == "peek") {
            mq.peek();
        }
        else if(cmd == "poll") {
            mq.poll();
        }
        else {
            throw;
        }
    }
    return 0;
}