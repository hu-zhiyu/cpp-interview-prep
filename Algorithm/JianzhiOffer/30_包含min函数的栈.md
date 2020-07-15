### 定义栈的数据结构，请在该类型中实现一个能够得到栈的最小元素的 min 函数在该栈中，调用 min、push 及 pop 的时间复杂度都是 O(1)。
示例:  
```c
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.min();  // 返回 -3.
minStack.pop();
minStack.top();  // 返回 0.
minStack.min();  // 返回 -2.
```
```c
class MinStack {
public:
    stack<int> s, min_s;

    MinStack() {
    }
    
    void push(int x) {
        s.push(x);
        if(min_s.empty() || x <= min_s.top()) min_s.push(x);
    }
    
    void pop() {
        if(s.top() == min_s.top()) min_s.pop();
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int min() {
        return min_s.top();
    }
};
```