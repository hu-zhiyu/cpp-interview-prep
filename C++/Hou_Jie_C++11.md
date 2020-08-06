# C++2.0 新特性
### variadic templates
* printf()的参数数量不定，就是用 variadic templates 实现的
* 示例
```c
void print() {
    // function body，递归基
}
template<typename T, typename... Types>
void print(const T& firstArg, const Types&... args) {  // ...就是一个所谓的pack (包)
    cout << firstArg << endl;
    print(args...);  // 以递归的形式调用自身
}
```
* 泛化版本, 可以与上面的示例并存
```c
template<typename... Types>
void print(const Types&... args) {
    // function body
}
```
* tuple
```c
template<typename... Values> class tuple;
template<> class tuple<> {};
template<typename Head, typename... Tail>
class tuple<Head, Tail...> : private tuple<Tail...> // 可以很方便的完成recursive inheritance
{
    typedef tuple<Tail...> inherited;
public:
    tuple() {}
    tuple(Head v, Tail... vtail) : m_head(v), inherited(vtail...) { }  // initialization list
    typename Head::type head() { return m_head; }
    inherited& tail() { return *this; }  // return后，转型为inherited
protected:
    Head m_head;
}
```
### nullptr 和 std::nullptr_t
```c
* typedef decltype(nullptr) nullptr_t; //defined in <cstddef>
```
### automatic type deduction with auto
* Especially useful when the type is a pretty long and/or complicated expression
* 示例
```c
vector<string> v;
auto pos = v.begin();  // pos has type vector<string>::iterator
auto I = [](int x) -> bool {  // I has the type of a lambda, taking an int and returning a bool
    /* ... */
};
```
### uniform initialization
* Before C++11, initialization could happen with parentheses, braces, and/or assignment operators.
* For this reason, C++11 introduced uniform initialization, which means that for any initialization, you can use one common syntax, that is uning braces.
* 编译器看到 {t1, t2, ..., tn} 时，便做出一个initializer_list\<T>，它关联到一个array\<T, n>。调用函数(例如ctor)时，该array内的元素可被编译器分解逐一传给函数。但若函数参数是个initializer_list\<T>，调用者却不能给予数个T参数然后以为它们会被自动转为一个initializer_list\<T>传入
### initializer list
* std::initializer_list<>
* 其背后是一个array, initializer_list内部的成员变量只有一个指向array的iterator和一个表明大小的size_t
* The initializer_list object refers to the elements of this array without containing them: copy an initializer_list object produces another object referring to the same underlying elements, not to new copies of them (reference semantics).
* 很多容器和算法都已经支持initializer_list作为参数
### explicit for ctors taking more than one argument
* explicit for ctors taking one argument (before C++11): 防止编译器进行隐式类型转换
```c
struct Complex {
    int real, imag;
    explicit Complex(int re, int im = 0) : real(re), imag(im) { }
    Complex operator+(const Complex & x) {
        return Complex((real + x.real), (imag + x.imag));
    }
 }
 Complex c1(12,5);
 Complex c2 = c1 + 5;  // Error, no match for 'operator+'
```
* C++11 之后，支持多个参数的explicit ctor
### range for
* 示例
```c
for (decl : coll) {
    /* statement */
}
```
### = default, = delete
* 如果你自行定义了一个ctor，那么编译器就不会再给你一个default ctor；如果你强制加上= default，就可以重新获得并使用default ctor
```c
class Zoo {
public:
    Zoo(int i1, int i2) : d1(i1), d2(i2) { }
    // Big-Five
    Zoo(const Zoo&) = delete;
    Zoo(const Zoo&&) = default;
    Zoo& operator=(const Zoo&) = default;
    Zoo& operator=(const Zoo&&) = delete;
    virtual ~Zoo() {}
private:
    int d1, d2;
}
```
* = default不能用于Big-Five之外的函数，编译报错；= delete可以用于任何函数身上
### No-Copy and Private-Copy
* no-copy示例
```c
struct NoCopy {
    NoCopy() = default;
    NoCopy(const NoCopy&) = delete;  // no copy
    NoCopy & operator=(const NoCopy&) = delete;  // no assignment
    ~NoCopy() = default;
    // other members
}
```
* private-copy示例 (boost::noncopyable)
```c
class NoCopy {  // 只有friend和类内的member才能访问copy ctor和copy assignment
private:
    PrivateCopy(const PrivateCopy&);
    PrivateCopy & operator=(const PrivateCopy&);
    // other members
public:
    PrivateCopy() = default;
    ~PrivateCopy();
}
```