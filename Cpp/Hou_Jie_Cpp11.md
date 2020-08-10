# C++2.0 新特性
### variadic templates
* printf()的参数数量不定，就是用 variadic templates 实现的
* 可用于递归调用/递归继承/递归复合
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
    // 上一行如编译出错，可改为
    // auto head() -> decltype(m_head) {return m_head; }
    // or simply
    // Head head() { return m_head; }
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
### alias template
* 示例
```c
template <typename T>
using Vec = std::vector<T, MyAlloc<T>>;
```
### template template parameter
* 见[模板模板参数](https://github.com/hu-zhiyu/cpp-interview-prep/blob/master/Cpp/Hou_Jie_Cpp.md)
* Alias templates are never deduced by template argument deduction when deducing a template template parameter.
### type alias (similar to typedef)
* 示例
```c
// type alias, identical to
// typedef void (*func)(int, int);
using func = void(*)(int, int);
```
### noexcept
* 示例
```c
void foo() noexcept;  // -> void foo() noexcept(true);
```
* noexcept declares that foo() won't throw under a specific condition. If an exception is not handled locally inside foo() -- thus, if foo() throws -- the program is terminated, calling std::terminate(), which by default calls std::abort(). 
* You need to inform C++ (specifically std::vector) that your move constructor and destructor does not throw. Then the move constructor will be called when the vector grows. If the constructor is not noexcept, std::vector can't use it, since then it can't ensure the exception guarantees demanded by the standard. (注意，growable containers (会发生memory reallocation) 只有两种：vector和deque)
```c
class MyString {
private:
    char* _data;
    size_t _len;
public:
    // move ctor
    MyString(MyString&& str) noexcept 
        : _data(str._data), _len(str._len) { /* ... */ }
    // move assignment
    MyString& operator=(MyString&& str) noexcept {
        /* ... */
        return *this;
    }
}
```
### override
* 用在子类的虚函数上: override means that the compiler will check the base class(es) to see if there is a virtual function with this exact signature. And if there is not, the compiler will indicate an error.
### final
* 被final修饰的class不能再被继承，被final修饰的虚函数不能被子类覆写
### decltype
* 示例
```c
map<string, float> coll;
decltype(coll)::value_type elem;
```
* decltype allows the compiler to infer the return type of a function based on an arbitrary expression and makes perfect forwarding more generic.
* One application of decltype is to declare return types. Another is to use it in metaprogramming or to pass the type of a lambda.
* decltype, used to declare return types
```c
template <typename T1, typename T2>
auto add(T1 x, T2, y) -> decltype(x+y);
```
* decltype, used to pass a lambda as hash function or ordering or sorting criterion to associative or unordered containers.
```c
auto cmp = [](const Person & p1, const Person & p2) {
    return p1.lastname() < p2.lastname();
}
std::set<Person, decltype(cmp)> coll(cmp);
```
### lambda
* C++11 introduced lambdas, allowing the definition of inline functionality, which can be used as a parameter or a local object. 
* A lambda is a definition of functionality that can be defined inside statements and expressions. The type of a lambda is an anonymous function object (or functor).
* format
```c
[...](...)mutable throwSpec ->retType {...} // mutable, throwSpec, ->retType are optional 
```
* 示例
```c
int id = 0;
auto f = [id]() mutable {  // id前没有&，是pass-by-value; 如果没有写mutable，则不能修改id
    cout << "id: " << id << endl;
    id++;
};
id = 42;
f();  // id: 0
f();  // id: 1
f();  // id: 2
cout << id << endl; // 42
```
### rvalue references
* Rvalue references are a new reference type introduced in C++0x that help solve the problem of unnecessary copying and enable perfect forwarding. When the right-hand side of an assignment is an rvalue, then the left-hand side object can steal resources from the right-hand side object rather than performing a separate allocation, thus enabling move semantics.
* Lvaule: 可以出现在operator=左侧者; Rvalue: 只能出现在operator=右侧者
* 示例
```c
string s1("hello");
string s2("world");
s1 + s2 = s2;  // 竟然通过编译
cout << "s1:" << s1 << endl;  // s1:hello
cout << "s2:" << s2 << endl;  // s2:world
string() = "world";  // 竟然可以对temp obj赋值
```
### move semantics
### perfect forwarding
* Perfect forwarding allows you to write a single function template that takes n arbitrary arguments and forwards them transparently to another arbitrary function. The nature of the argument (modifiable, const, lvalue or rvalue) is preserved in this forwarding process.
```c
template <typename T1, typename T2>
void functionA(T1&& t1, T2&& t2) {
    functionB(std::forward<T1>(t1), std::forward<T2>(t2));
}
```
