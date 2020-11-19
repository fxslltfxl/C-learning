#include <iostream>
#include <boost/type_index.hpp>
#include <vector>

using namespace std;
using boost::typeindex::type_id_with_cvr;

//// 左右指测试代码
//template<typename T>
//void PrintType(T&& param)
//{
//    // 利用Boost库打印模板推导出来的 T 类型
//    cout << "T type：" << type_id_with_cvr<T>().pretty_name() << endl;
//    // 利用Boost库打印形参的类型
//    cout << "param type:" << type_id_with_cvr<decltype(param)>().pretty_name() << endl;
//}
//
//std::string TestAuto(int& i) {
//    cout << "int& i" << i << endl;
//}
//
//std::string TestAuto(int&& i) {
//    cout << "int&& i" << i << endl;
//}
//
//int main(int argc, char *argv[])
//{
////    关于有的人会问，我传入的是一个左值a,并不是一个左值引用，为什么编译器会推导出T 为int &呢。
////    首先，模板函数参数为 T&& param,也就是说，不管T是什么类型，T&&的最终结果必然是一个引用类型。
////    如果T是int, 那么T&& 就是 int &&；如果T为 int &，那么 T &&(int& &&) 就是&，如果T为&&,那么T &&(&& &&) 就是&&。
////    很明显，接受左值的话，T只能推导为int &。
////    int a = 0;                              // 左值
////    PrintType(a);                           // 传入左值
////
////    /* */
////    int &lvalue_refence_a = a;              // 左值引用
////    PrintType(lvalue_refence_a);            // 传入左值引用
////
////    /* */
////    PrintType(int(2));                      // 传入右值
//
//
//    int x = 42;
//    int& a = x;
//    int&& b = 42;
//    auto&& c = a; // int&
//    auto&& d = b; // int&
//    auto&& e = std::move(b); // int&&
//
//    TestAuto(c);
//    TestAuto(d);
//    TestAuto(std::move(e));
//
//    auto test = nullptr;
//}



// 接收左值的函数 f()
//template<typename T>
//void f(T &)
//{
//    cout << "f(T &)" << endl;
//}
//
//// todo 接收右值的函数f()
//template<typename T>
//void f(T &&)
//{
//    cout << "f(T &&)" << endl;
//}
//
//// 万能引用，转发接收到的参数 param
//template<typename T>
//void PrintType(T&& param)
//{
//    f(std::forward<T>(param));  // 将参数param转发给函数 void f()
//}
//// 函数内部，对形参的直接使用，都是按照左值进行的。
//int main(int argc, char *argv[])
//{
//    int a = 0;
//    PrintType(a);//传入左值
//    PrintType(int(0));//传入右值
//}

//// vector 通常保证强异常安全性，如果元素类型没有提供一个保证不抛异常的移动构造函
//// 数，vector 通常会使用拷贝构造函数。因此，对于拷贝代价较高的自定义元素类型，我们 应当定义移动构造函数，并标其为 noexcept，或只在容器中放置对象的智能指针
//class Obj1 {
//public:
//    Obj1() {
//        cout << "Obj1()\n"; }
//    Obj1(const Obj1&)
//    {
//        cout << "Obj1(const Obj1&)\n"; }
//    Obj1(Obj1&&)
//    {
//        cout << "Obj1(Obj1&&)\n"; }
//};
//class Obj2 {
//public:
//    Obj2() {
//        cout << "Obj2()\n"; }
//    Obj2(const Obj2&)
//    {
//        cout << "Obj2(const Obj2&)\n"; }
//    Obj2(Obj2&&) noexcept
//    {
//        cout << "Obj2(Obj2&&)\n"; }
//};
//int main() {
//    vector<Obj1> v1;
//    v1.reserve(2);
//    v1.emplace_back();
//    v1.emplace_back();
//    v1.emplace_back();
//    vector<Obj2> v2;
//    v2.reserve(2);
//    v2.emplace_back();
//    v2.emplace_back();
//    v2.emplace_back();
//
//
//    string_view stringView = "111";
//}
#include <functional>  // std::greater
#include <iostream>
//#include <memory>
#include <queue>
#include <vector>

using namespace std;

#include <tuple>

#include <complex> // std::complex
#include <iostream> // std::cout/endl #include <unordered_map> // std::unordered_map
#include <unordered_set> // std::unordered_set
#include <unordered_map> // std::unordered_set

template<typename T>
struct hash<complex<T>> {
    size_t
    operator()(const complex<T>& v) const
    noexcept {
        hash<T> h;
        return h(v.real()) + h(v.imag());
    }
};

//// 容器测试代码
//int main() {
//    priority_queue<pair<int, int>, vector<pair<int, int>>> q;
//    q.push({1, 1});
//    q.push({2, 2});
//    q.push({0, 3});
//    q.push({9, 4});
//    while (!q.empty()) {
//        cout << "q.pop()" << endl;
//    }
//    multimap<string, int> mmp{
//            {"one",   1},
//            {"two",   2},
//            {"three", 3},
//            {"four",  4}
//    };
//    mmp.insert({"four", -4});
//    multimap<string, int>::iterator
//            lower, upper;
//    std::tie(lower, upper) = mmp.equal_range("four");
//    auto upper1 = (--upper);
//    upper1->second;


//    unordered_set<int> s{
//            1, 1, 2, 3, 5, 8, 13, 21
//    };
//    unordered_map<complex<double>,
//            double>
//            umc{{{1.0, 1.0}, 1.4142}, {{3.0, 4.0}, 5.0}};


//    std::vector<int> v = {1, 2, 3, 4, 5, 6, 78, 9, 0};
//
//    for (const int i: v) {
//        cout << "i:" << i << endl;
//    }
//
//    for (vector<int>::iterator it = v.begin(), end = v.end(); it != end; ++it) {
//
//    }
//}
/// 后置返回值类型声明
auto test() -> decltype(auto) {
    auto& res_id((string&) "111");
    return res_id;
}

std::vector<int64_t> alerts_;

//// auto decltype
//int main() {
//    cout << "value:" << test() << endl;
//
//    alerts_.push_back(1);
//    alerts_.push_back(1);
//    alerts_.push_back(1);
//    alerts_.push_back(1);
//    alerts_.clear();
//    alerts_.shrink_to_fit();
//    auto bak_alerts = alerts_;
//    for (auto alert_ptr : bak_alerts) {
//        cout << alert_ptr << endl;
//    }
//}


///
#include <stdlib.h>


/// Can copy and move and RVO
//class A {
//public:
//    A() { cout << "Create A\n"; }
//
//    ~A() { cout << "Destroy A\n"; }
//
//    A(const A&) { cout << "Copy A\n"; }
//
//    A(A&&) { cout << "Move A\n"; }
//};
//
//A getA_duang() {
//    A a1;
//    A a2;
//    if (rand() > 42) {
//        return a1;
//    } else {
//        return a2;
//    }
//}
//
//int main() {
//    auto a = getA_duang();
//}

/// Template basic knowledge first
template<typename T>
void func(T& t) { //通用模板函数
    cout << "In generic version template " << t << endl;
}

template<typename T>
void func(T* t) { //指针版本
    cout << "In pointer version template " << *t << endl;
}

void func(string* s) { //普通函数
    cout << "In normal function " << *s << endl;
}


int main() {
    int i = 10;
    func(i); //调用通用版本，其他函数或者无法实例化或者不匹配
    func(&i); //调用指针版本，通用版本虽然也可以用，但是编译器选择最特殊的版本
    string s = "abc";
    func(&s); //调用普通函数，通用版本和特殊版本虽然也都可以用，但是编译器选择最特化的版本
    func<>(&s); //调用指针版本，通过<>告诉编译器我们需要用template而不是普通函数
}
