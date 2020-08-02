### 转换函数 (conversion function)
* 示例
```c
operator typename() const {
    /*
    function body
    */
}
```
### non-explicit-one-argument ctor
### explicit-one-argument ctor
* 在C++中，explicit关键字用来修饰类的构造函数，被修饰的构造函数的类，不能发生相应的隐式类型转换，只能以显示的方式进行类型转换。
### point-like classes
#### 1. 关于智能指针
* 示例
```c
template<class T>
class shared_ptr {
public:
    T& operator*() const {
        return *px;
    }
    T* operator->() const {
        return px;
    }
    shared_ptr(T* p) : px(p) {}
private:
    T* px;
    long* pn;
...
}
``` 
#### 2. 关于迭代器
* 示例
```c
reference operator*() const {
    return (*node).data;
}
pointer operator->() const {
    return &(operator*());
}
```
### 所谓仿函数 (function-like classes)
* 仿函数，即重载函数调用操作符的类，其对象常称为函数对象 (function object)，即它们是行为类似函数的对象。
* 标准库中，仿函数会继承自一些奇特的基类 (unary_function, binary_function)，这些基类没有成员对象和成员函数，只有一些typedef。
### namespace 经验谈
* 多用namespace隔离不同的命名空间
### 类模板 (class template)
### 函数模板 (function template)
### 成员模板 (member template)
* 一个类 (无论是普通类还是类模板)可以包含本身是模板的成员函数，这种成员被称为成员模板。
### 模板特化 (specialization)
* 示例
```c
// 泛化 or 全特化
template <class Key>
struct hash {};
```
```c
// 特化
template<>
struct hash<char> {
    size_t operator()(char x) const { return x;}
};

template<>
struct hash<int> {
    size_t operator()(int x) const { return x;}
};

template<>
struct hash<long> {
    size_t operator()(long x) const { return x;}
};
```
### 模板偏特化 (partial specialization)
* “个数”的偏
```c
template<typename T, typename Alloc=...>
class vector {...};

// 将 T 绑定为 bool
template<typename Alloc=...>
class vector<bool, Alloc> {...};
```
* “范围”的偏
```c
tempalte <typename T>
class C {...};

// 上面的模板中 T 可以为任意类型，但这里要求 U* 为指针类型
template <typename U>
class C<U*> {...};
```
### 模板模板参数 (template template parameter)
* 示例1
```c
template<typename T,
         template<typename T>
            class Container
        >
class XCls {
private:
    Container<T> c;  // 这里的 T 为上面的第一个模板参数
public:
    ...
};
```
```c
template<typename T>
using Lst = list<T, allocator<T>>;  // C++11
```
```c
XCls<string, list> mylst1;  // 错误用法，容器可能要接收多个模板参数
XCls<string, Lst> mylst2;  // 正确用法
```
* 示例2
```c
template<typename T,
         template<typename T>
            class SmartPtr
        >
class XCls {
private:
    SmartPtr<T> sp;
public:
    XCls() : sp(new T) { }
};
```
```c
XCls<string, shared_ptr> p1;  // 正确
XCls<double, unique_ptr> p2;  // 错误
XCls<int, weak_ptr> p3;  // 错误
XCls<long, auto_ptr> p4;  // 正确
```
### 数量不定的模板参数 (variadic templates, since C++11)
* 示例
```c
void print() {
    // function body
}
template<typename T, typename... Types>
void print(const T& firstArg, const Types&... args) {  // ...就是一个所谓的pack (包)
    cout << firstArg << endl;
    print(args...);
}
```
* Inside variadic templates, sizeof...(args) yields the number of arguments.
### auto关键字 (since C++11)
### range-based for (since C++11)
* 示例
```c
for (decl : coll) {
    statement
}
```
### reference
* reference -> “代表”，pointer -> “指向”
* reference底层实际上是使用pointer实现的
* object和reference的大小相同，地址也相同 (实际是假象)
* Java中所有变量都是reference
* 以下被视为 "same signature" (signature指的是函数名及其参数，以及参数列表后修饰函数本身的const), 所以二者不能同时存在
```c
double imag(const double& im) { ... }
double imag(const double  im) { ... }  // ambiguity
```
### 继承 (inheritance)和组合 (composition)关系下的构造和析构
* 构造由内而外，析构由外而内，先构造的后析构
```c
Derived::Derived(...) : Base() {...}
Derived::~Derived(...) {... ~Based()}
```