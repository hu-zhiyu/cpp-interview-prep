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