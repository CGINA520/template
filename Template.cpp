//一、泛型编程
//模板：提高代码复用性，将类型参数化
//使用注意事项：
//使用时必须确定出通用数据类型T，并且可以推导出一致的数据类型

//函数模板
// #include <iostream>
// using namespace std;

// template <typename T> //声明一个模板，T为通用数据类型
// //利用模板实现交换函数
// void mySwap(T &a, T &b)
// {
//     T tmp = a;
//     a = b;
//     b = tmp;
// }

// void test01()
// {
//     int a = 10;
//     int b = 30;
//     // 1、自动类型推导
//     mySwap(a, b);
//     cout << "a= " << a << endl;
//     cout << "b= " << b << endl;
//     // 2、显示指定类型
//     double c = 1.1;
//     double d = 2.2;
//     mySwap<double>(c, d);
//     cout << "c=" << c << endl;
//     cout << "d=" << d << endl;
// }
// int main()
// {
//     test01();
//     system("pause");
//     return 0;
// }

//二、数组排序
// #include <iostream>
// using namespace std;

// //算法：选择排序
// //要求：从大到小

// //交换
// template <typename T>
// void mySort(T &a, T &b)
// {
//     T tmp = a;
//     a = b;
//     b = tmp;
// }
// //排序
// template <typename T>
// void mySort(T arr[], int len)
// {
//     for (int i = 0; i < len; i++)
//     {
//         int max = i;
//         for (int j = i + 1; j < len; j++)
//         {
//             if (arr[max] < arr[j])
//             {
//                 max = j;
//             }
//         }
//         if (max != i)
//         {
//             mySort(arr[max], arr[i]);
//         }
//     }
// }
// template <typename T>
// void printArry(T arr[], int len)
// {
//     for (int i = 0; i < len; i++)
//     {
//         cout << arr[i] << " ";
//     }
//     cout << endl;
// }

// void test01()
// {
//     char arr[] = "abcdef";
//     int length = sizeof(arr) / sizeof(char);
//     mySort(arr, length);
//     printArry(arr, length);
// }
// void test02()
// {
//     int arr[] = {1, 2, 3, 4, 5, 6, 7};
//     int length = sizeof(arr) / sizeof(int);
//     mySort(arr, length);
//     printArry(arr, length);
// }
// int main()
// {
//     test01();
//     test02();
//     system("pause");
//     return 0;
// }

//三、普通函数与模板的调用规则
// #include <iostream>
// using namespace std;

// // 1.普通函数与模板同时可以调用时，优先调用普通函数
// // 2.可以通过空模板参数列表优先调用模板
// // 3.函数模板可以发生重载
// // 4.如果函数模板可以发生更好的匹配，那么选择函数模板

// void Myprint(int a)
// {
//     cout << "普通函数调用" << endl;
// }

// template <typename T>
// void Myprint(T a)
// {
//     cout << "模板调用" << endl;
// }
// //模板重载
// void Myprint(int a, int b, int c)
// {
//     cout << "函数重载模板调用" << endl;
// }

// void test01()
// {
//     int a = 10;
//     char b = 'a';
//     // Myprint(a, 23, 23);
//     Myprint(b);
// }
// int main()
// {
//     test01();
//     system("pause");
//     return 0;
// }

//四、函数模板的局限性
// #include <iostream>
// #include <string>
// using namespace std;

// template <typename T>
// bool Mycomp(T &a, T &b)
// {
//     if (a == b)
//     {
//         return true;
//     }
//     else
//     {
//         return false;
//     }
// }

// class Person
// {
// public:
//     Person(string name, int age)
//     {
//         m_name = name;
//         m_age = age;
//     }
//     string m_name;
//     int m_age;
// };

// //利用具体化Person版本，优先调用Person类
// template <>
// bool Mycomp(Person &a, Person &b)
// {
//     if (a.m_name == b.m_name && a.m_age == b.m_age)
//     {
//         return true;
//     }
//     else
//     {
//         return false;
//     }
// }

// void test01()
// {
//     Person p1("TOM", 28);
//     Person p2("TOM", 8);
//     bool ret = Mycomp(p1, p2);
//     if (ret)
//     {
//         cout << "p1=p2" << endl;
//     }
//     else
//     {
//         cout << "p1!=p2" << endl;
//     }
// }

// int main()
// {
//     test01();
//     system("pause");
//     return 0;
// }

//四、类模板
// #include <iostream>
// #include <string>
// using namespace std;

// template <class NameType, class AgeType>
// class Person
// {
// public:
//     Person(NameType name, AgeType age)
//     {
//         this->m_name = name;
//         this->m_age = age;
//     }
//     void Showdate()
//     {
//         cout << "name: " << this->m_name << endl;
//         cout << "age: " << this->m_age << endl;
//     }
//     NameType m_name;
//     AgeType m_age;
// };

// void test01()
// {
//     Person<string, int> p("张三", 20);
//     p.Showdate();
// }

// int main()
// {
//     test01();
//     system("pause");
//     return 0;
// }

//五、类模板中的成员函数调用
//不是在一开始创建，而是在调用是才创建
// #include <iostream>
// using namespace std;

// class Person1
// {
// public:
//     void show_Person1()
//     {
//         cout << "show_Person1调用" << endl;
//     }
// };

// class Person2
// {
// public:
//     void show_Person2()
//     {
//         cout << "show_Person2调用" << endl;
//     }
// };

// template <class T>
// class Myclass
// {
// public:
//     T obj;
//     void func1()
//     {
//         obj.show_Person1();
//     }
//     void func2()
//     {
//         obj.show_Person2();
//     }
// };

// void test01()
// {
//     Myclass<Person2> m;
//     // m.func1();
//     m.func2();
// }
// int main()
// {
//     test01();
//     system("pause");
//     return 0;
// }

//六、类模板对象作为函数参数
// #include <iostream>
// using namespace std;

// template <class T1, class T2>
// class Person
// {
// public:
//     Person(T1 name, T2 age)
//     {
//         this->m_name = name;
//         this->m_age = age;
//     }
//     void show_person()
//     {
//         cout << "name: " << this->m_name << endl;
//         cout << "age: " << this->m_age << endl;
//     }
//     T1 m_name;
//     T2 m_age;
// };

// // 1.指定传入类型(使用最为广泛)
// void print_person1(Person<string, int> &p)
// {
//     p.show_person();
// }

// void test01()
// {
//     Person<string, int> p("张三", 19);
//     print_person1(p);
// }

// // 2.参数模板化
// template <class T1, class T2>
// void print_person2(Person<T1, T2> &p)
// {
//     p.show_person();
//     cout << "T1的类型: " << typeid(T1).name() << endl;
//     cout << "T2的类型: " << typeid(T2).name() << endl;
// }
// void test02()
// {
//     Person<string, int> p("张三", 18);
//     print_person2(p);
// }

// // 3.整个类模板化
// template <class T>
// void print_person3(T &p)
// {
//     p.show_person();
//     cout << "T的类型: " << typeid(T).name() << endl;
// }
// void test03()
// {
//     Person<string, int> p("张三", 17);
//     print_person3(p);
// }
// int main()
// {
//     test01();
//     cout << "-------------------" << endl;
//     test02();
//     cout << "-------------------" << endl;
//     test03();
//     system("pause");
//     return 0;
// }

//七、类模板与继承
// #include <iostream>
// using namespace std;

// template <class T>
// class Base
// {
//     T m;
// };

// class Son1 : public Base<int>
// {
// };

// //如果想灵活指定父类中T类型，子类也需要变类模板
// template <class T1, class T2>
// class Son2 : public Base<T1>
// {
// public:
//     Son2()
//     {
//         cout << "T1的类型: " << typeid(T1).name() << endl;
//         cout << "T2的类型: " << typeid(T2).name() << endl;
//     }
//     T2 a;
// };
// void test01()
// {
//     Son2<int, char> p2;
// }
// int main()
// {
//     test01();
//     system("pause");
//     return 0;
// }

//八、类模板中成员函数类外实现
#include <iostream>
using namespace std;

template <class T1, class T2>
class Person
{
public:
    Person(T1 name, T2 age);
    void show_person();
    T1 m_name;
    T2 m_age;
};
//构造函数类外实现
template <class T1, class T2>
Person<T1, T2>::Person(T1 name, T2 age)
{
    this->m_name = name;
    this->m_age = age;
}

//普通成员函数类外实现
template <class T1, class T2>
void Person<T1, T2>::show_person()
{
    cout << "name: " << this->m_name << endl;
    cout << "age: " << this->m_age << endl;
}

void test01()
{
    Person<string, int> p("张三", 23);
    p.show_person();
}
int main()
{
    test01();
    system("pause");
    return 0;
}