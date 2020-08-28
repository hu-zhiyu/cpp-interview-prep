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
### vector
### deque / stack / queue
* deque 通过迭代器模拟成连续空间 (实质是分段连续)
* stack 和 queue 都是在内部用 deque 实现的 (也可使用 list，但默认使用的 deque 更快)，stack 和 queue 都不允许遍历，也不提供 iterator
* stack 可以选择 vector 作为底层实现，queue 不能选择 vector 作为底层实现
* stack 和 queue 都不能选择 set 或 map 作为底层实现
### RB-tree
* Red-Black tree 是一种高度平衡的二叉搜索树，其排列规则有利于 search 和 insert
* RB-tree 提供两种 insertion 操作：insert_unique() 和 insert_equal()，前者表示节点的 key 一定在整个树中独一无二，否则插入失效；后者表示节点的 key 可以重复
* 容器 rb_tree (非公开)
```c
template <class Key,
          class Value,
          class KeyOfValue,  // 用于从value取key
          class Compare,
          class Alloc = alloc>
class rb_tree {
protected:
    typedef __rb_tree_node<Value> rb_tree_node;
    ...
public:
    typedef rb_tree_node* link_type;
    ...
protected:
    size_type node_count;  // rb_tree的节点数量
    link_type header;  // header 指向的节点不放元素，方便实现
    Compare key_compare;  // key的大小比较准则，是个function object
    ...
}
```
### set/multiset
* 以红黑树为底层数据结构，因此元素自动排序
* 无法使用 set/multiset 的 iterator 改变元素值，因为 key 有其严谨的排列规则
```c
template <class Key,
          class Compare = less<Key>
          class Alloc = alloc>
class set {
public:
    typedef Key key_type;
    typedef Key value_type;
    typedef Compare key_compare;
    typedef Compare value_compare;
private:
    typedef rb_tree<key_type, value_type, identity<value_type>, key_compare, Alloc> rep_type;
    rep_type t;
public:
    typedef typename rep_type::const_iterator iterator;  // 不能通过iterator改变元素，所以这里为const_iterator
...  // set的所有操作，都是调用底层的t来进行操作，从这个角度看，set可看成一个container adapter
}
```
### map/multimap
* 以红黑树为底层数据结构，因此元素自动排序
* 无法使用 map/multimap 的 iterator 改变元素的 key，但可以用它来改变元素的data
```c
template <class Key,
          class T,
          class Compare = less<Key>,
          class Alloc = alloc>
class map {
public:  
    typedef Key key_type;
    typedef T data_type;
    typedef T mapped_type;
    typedef pair<const Key, T> value_type;
    typedef Compare key_compare;
private:
    typedef rb_tree<key_type, value_type, select1st<value_type>, key_compare, Alloc> rep_type;
    rep_type t;
public:
    typedef typename rep_type::iterator iterator;
...
}
```
* operator[] 是 map 独有的，multimap没有这个操作符
### hashtable
* separate chaining
* 当元素数量大于 bucket 大小时，可以增加 bucket 大小(设定为质数)，然后对每一个元素做 rehash
```c
template <class Value, class Key, class HashFcn,
          class ExtractKey, class EqualKey, class Alloc = alloc>
class hashtable {
public:
    typedef HashFcn hasher;
    typedef EqualKey key_equal;
    typedef size_t size_type;
private:
    hasher hash;
    key_euqal equals;
    ExtractKey get_key;
    typedef __hashtable_node<Value> node;
    vector<node*, Alloc> buckets;
    size_type num_elements;
public:
    size_type bucket_count() const {
        return bucket.size();
    } 
}

template <class Value>
struct __hashtable_node {
    __hashtable_node* next;
    Value val;
}
```
### 各种容器的 iterators 的 iterator_category
```c
struct input_iterator_tag {};
struct output_iterator_tag {};
struct forward_iterator_tag : public input_iterator_tag {};
struct bidirectional_iterator_tag : public forward_iterator_tag {};
struct random_access_iterator_tag : public bidirectional_iterator_tag {};
```
### for_each
```c
template <class InputIterator, class Function>
Function for_each(InputIterator first, InputIterator last, Function f) {
    for(; first != last; ++first) {
        f(*first);
    }
    return f;
}
```
### binary_search
```c
template <class ForwardIterator, class T>
bool binary_search(ForwardIterator first, ForwardIterator last, const T& val) {
    first = std::lower_bound(first, last, val);
    return (first != last && !(val < *first>));
}
```
### 仿函数functor