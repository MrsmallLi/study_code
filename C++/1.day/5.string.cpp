/*************************************************************************
	> File Name: 5.string.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 09 Apr 2024 10:36:02 AM CST
 ************************************************************************/

#include <iostream>
#include <string>
using namespace std;

int main() {
    //定义一个字符串，并初始化
    string str = "nihao nihao";
    cout << "str = " << str << endl;
    //访问位置1的字符并赋值给字符c
    char c = str[1];
    cout << "c = " << c << endl;
    string str2 = "hello";
    //使用等号进行字符串拷贝赋值
    str = str2;
    cout << "str = " << str << endl;
    str += " world";
    cout << "str = " << str << endl;
    cout << "str len = " << str.length() << endl;
    cout << "str is emtpy " << boolalpha << str.empty() << endl;
    int ind = 4;
    cout << "str[" << ind << "] = " << str.at(ind) << endl;
    cout << "str.front() = " << str.front() << endl;
    cout << "str.back() = " << str.back() << endl;
    cout << "str.find(l) = " << str.find("l") << endl;
    cout << "str.rfind(l) = " << str.rfind("l") << endl;
    //在字符串最后的位置加上" nihao"
    str.insert(str.length() - 1, " nihao");
    cout << "str = " << str << endl;
    //将刚刚插入的" nihao"删除
    str.erase(str.length() - 7, 6);
    cout << "str = " << str << endl;
    //从0位置开始替换6个字符，并替换为ni hao
    str.replace(0, 6, "ni hao");
    cout << "str = " << str << endl;
    cout << "*str.begin() = " << *str.begin() << endl;
    return 0;
}
