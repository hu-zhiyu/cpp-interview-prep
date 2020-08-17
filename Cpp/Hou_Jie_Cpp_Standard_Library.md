# C++ STL 体系结构与内核分析 -- 从平地到万丈高楼
### STL体系结构
* STL六大部件: 容器，分配器，算法，迭代器，适配器，仿函数
* 示例
```c
# include <vector>
# include <algorithm>
# include <functional>
# include <iostream>
using namespace std;
int main() {
    int ia[6] = {1,2,3,4,5,6};
    vector<int, allocator<int>> vi(ia, ia + 6);  // vector: container, allocator<int>: allocator
    cout << count_if(vi.begin(), vi.end(),  // count_if: algorithm, vi.begin(): iterator
                     not1(bind2nd(less<int>(), 40)));  // not1: function adapter(negator), bind2nd: function adapter(binder), less<int>: function object
    return 0;
}
```
### 容器的结构与分类
* sequence containers: array, vector, deque, list, forward_list
* associative containers: set/multiset, map/multimap (impl: RB tree)
* unordered containers: unordered set/multiset, unordered map/multimap (impl: separate chaining)
### OOP (面向对象编程) vs. GP (泛型编程)
* OOP 企图将 data 和 method 关联在一起，GP 却是将 data 和 method 分开
* 采用GP：container 和 algorithm 可各自闭门造车，其间以 iterator 沟通即可，algorithm 通过 iterator 确定操作范围，并通过 iterator 取用 container 元素
* 为什么 list 不能使用 ::sort() 排序？因为 ::sort() 中要使用随机访问迭代器来进行排序
