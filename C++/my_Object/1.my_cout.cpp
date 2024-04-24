/*************************************************************************
	> File Name: my_cout.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 23 Apr 2024 05:50:10 PM CST
 ************************************************************************/

#include <iostream>
#include <iomanip>
#include <string>

namespace my {
    class setprecision {
    public :
        setprecision(int n) : n(n) {}
        bool operator==(int n) {
            return this->n == n;
        }
        int operator()() {
            return this->n;
        }
        int n;
    };

    class ostream {
    public :
        ostream() : __sp(-1) {}
        ////////为了兼容const类型使用，所以需要对方法进行const限定
        //为了可以连续进行输出，所以需要返回值是ostream&，如果不理解可以再回头去理解左值右值
        ostream &operator<<(const char *s) {
            printf("%s", s);
            return *this; 
        }
        ostream &operator<<(const int &x) {
            printf("%d", x);
            return *this; 
        }
        ostream &operator<<(const double &f) {
            //系统对于cout输出浮点类型时使用的是%g占位符
            char format[20] = {0};
            if (__sp == -1) sprintf(format, "%%g");
            else sprintf(format, "%%.%dg", __sp());
            printf(format, f);
            return *this; 
        }
        ostream &operator<<(const setprecision &s) {
            this->__sp = s;
            return *this;
        }
        ostream &operator<<(const std::string &str) {
            for (int i = 0; str[i]; i++) printf("%c", str[i]);
            return *this;
        }
        setprecision __sp;
    };
    ostream cout;
    //实际的endl不是这样实现的
    //只是我们在这里这样去实现比较简单
    const char *endl = "\n";
}



int main() {
    std::cout << "hello world" << std::endl;
    my::cout << "hello world" << my::endl;
    int n = 123;
    std::cout << "n = " << n << std::endl;
    my::cout << "n = " << n << my::endl;
    double a = 1.23, b = 1.2345, c = 0.0012345, d = 1234.56; 
    std::cout << "a = " << a << std::endl;
    my::cout << "a = " << a << my::endl;
    std::cout << "b = " << b << std::endl;
    my::cout << "b = " << b << my::endl;

    //实现cout设置精度
    //setprecision就是保留几位有效数字
    std::cout << "std::cout : " << std::endl;
    std::cout << std::setprecision(3) << b << std::endl;
    std::cout << std::setprecision(3) << c << std::endl;
    std::cout << std::setprecision(3) << d << std::endl;
    std::cout << "my::cout : " << std::endl;
    my::cout << my::setprecision(3) << b << my::endl;
    my::cout << my::setprecision(3) << c << my::endl;
    my::cout << my::setprecision(3) << d << my::endl;

    //setprecision在设置之后，那么后续使用std::cout输出也是设置后的精度
    std::cout << c << std::endl;
    my::cout << c << my::endl;

    std::string str = "hello";
    std::cout << str << std::endl; 
    my::cout << str << my::endl; 

    return 0; 
}
