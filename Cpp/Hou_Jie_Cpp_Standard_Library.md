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
### 分配器
* VC6 所附的标准库，其 allocator 实现如下(\<xmemory>)
```c
template<class _Ty>
class allocator {
public:
    typedef _SIZE size_type;
    typedef _PDFT difference_type;
    typedef _Ty _FAEQ *pointer;
    typedef _Ty value_type;
    pointer allocate(size_type _N, const void*) {
        return (_Allocate((difference_type)_N, (pointer)0));
    }
    void deallocate(void _FARQ *_P, size_type) {
        operator delete(_P);
    }
}
// 其中用到的 _Allocate()定义如下:
template<class -Ty> inline
_Ty _FARQ *_Allocate(_PDFT _N, _Ty _FARQ *) {
    if (_N < 0) _N = 0;
    return ((_Ty _FARQ *)operator new((_SIZT)_N * sizeof(_Ty)));
}
```
* allocator 只是以 ::operator new 和 ::operator delete 完成 allocate()和 deallocate()，没有任何特殊设计；::operator new 和 ::operator delete 背后又会去调用 CRT 提供的 malloc() 和 free() 完成内存的分配与释放。
### 迭代器的设计原则和iterator traits的设计与作用
* iterator 必须有能力回答 algorithm 的提问
```c
// iterator 必须要写出的 5 种 typedef
iterator_category
difference_type
value_type
reference
pointer
```
* iterator traits 用以分离 class iterators 和 non-class iterators，是一个中间层的设计，利用 partial specialization 来达到目的
```c
template <class T>
struct iterator_traits {  // 如果 I 是class iterator，进入这里
    typedef typename I::value_type value_type;
}
// 以下为两个偏特化
template <class T>
struct iterator_traits<T*> {  // 如果 I 是 pointer to T，进入这里
    typedef T value_type;
}
template <class T>
struct iterator_traits<const T*> {  // 如果 I 是 pointer to const T，进入这里
    typedef T value_type;  // 注意是 T 而不是 const T
}
// 于是当需要知道 I 的 value_type 时，可以这样写：
template <typename I, ...>
void algorithm(...) {
    typename iterator_traits<T>::value_type v1;  // 通过中间层 iterator_traits 获取到 I 的value_type
}
```

