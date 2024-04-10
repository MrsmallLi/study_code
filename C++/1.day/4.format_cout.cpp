/*************************************************************************
	> File Name: 4.format_cout.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 09 Apr 2024 09:52:01 AM CST
 ************************************************************************/

#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
using namespace std;

int main() {
    char s[] = "hello";
    char s2[] = "nihao";
    memcpy(s, s2, 5);
    string str1;
    str1.assign("hello");
    cout << str1 << endl;
    //输出整形
    int num = 123;
    cout << "num = " << num << endl;

    //输出双精度浮点型
    double f = 3.1415926;
    //setprecision(2) 是将输出保留小数点后两位
    cout << "f = " << f << setprecision(2) << endl;

    //输出布尔类型
    bool isTrue = true;
    //这里使用boolalpha是将输出结果转为字符串类型
    //如果没有boolalpha 那么将会输出 Value : 1
    cout << "Value :" << boolalpha << isTrue << endl;

    //输出字符串
    string str = "hello world";//现在理解str就是像char类型的字符数组
    cout << str << endl;

    //输出科学计数法
    //scientific 表示输出内容用科学计数法输出
    double val = 1.2345678;
    cout << "Scientific notation : " << scientific << val << endl;

    //输出指针地址
    int *p = &num;
    cout << "&num = " << p << endl;

    int n = 96;
    //十六进制
    cout << hex << "hex : " << n << endl;
    //八进制
    cout << oct << "oct : " << n << endl;
    //十进制
    cout << dec << "dec : " << n << endl;
    
    //自定义输出
    int width = 10;
    char c = '*';
    //setw用于设置字段宽度，即输出的字符数。
    //它接受一个整数参数，指定输出的最小宽度。
    //如果输出的内容不够宽，将用空格填充以达到指定的宽度
    cout << setw(width) << n << endl;
    //setfill用于设置填充字符，即在宽度未达到指定值时用于填充的字符。
    //它接受一个字符参数，指定用于填充的字符。
    //例如下面用字符c进行填充，如果没有setfill那么就默认是空格填充
    cout << setw(width) << setfill(c) << n << endl;
    return 0;
}
