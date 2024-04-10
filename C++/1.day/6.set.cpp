/*************************************************************************
	> File Name: 6.set.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 09 Apr 2024 12:13:53 PM CST
 ************************************************************************/

#include <iostream>
#include <set>
#include <ctime>
using namespace std;

void output(set<int> s) {
    //用set<int>迭代器对象进行定义 i对象,然后进行遍历set里的元素
    for (set<int>::iterator i = s.begin(); i != s.end(); i++) {
        i != s.begin() && cout << " ";
        //把迭代器看为指针，那么要对指针进行取值就是利用*
        cout << *i;
    }
    cout << endl;
    return ;
}

int main() {
    srand(time(0));
    set<int> s;
    for (int i = 0; i < 10; i++) {
        i && cout << " ";
        int val = rand() % 100;
        //添加元素进s
        s.insert(val);
        cout << val;
    }
    cout << endl;
    //通过输出发现，set将插入进的元素进行了排序
    output(s);
    for (int i = 0; i < 10; i++) {
        int val = rand() % 100;
        //s.find返回是迭代器,理解为指针
        //如果没有找到他就返回一个指针指向最后一个元素的后一个位置,也就是s.end();
        //那么没有找到就返回是s.end()的位置，那就通过这样去判断找没找到
        if (s.find(val) == s.end()) {
            cout << val << "is not find in set" << endl;
            continue;
        }
        cout << "find " << val << " in set" << endl;
        //找到了并删除
        cout << "erase" << val << " at set" << endl;
        s.erase(val);
    }
    return 0;
}
