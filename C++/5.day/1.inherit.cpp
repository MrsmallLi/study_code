/*************************************************************************
	> File Name: 1.inherit.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 24 Apr 2024 04:33:52 PM CST
 ************************************************************************/

#include <iostream>
#include <string>
using namespace std;

class Animal {
public :
    void say_name() {
        cout << name << endl;
    }
    void set_name(string name) {
        this->name = name;
        return ;
    }
private :
string name;
};

class Cat : public Animal {
public :
    Cat() { set_name("Cat"); }
};

class Dog : public Animal {
public :
    Dog() { set_name("Dog"); }
};

class Snake : public Animal {
public :
    Snake() { set_name("Snake"); }
};



int main() {
    Cat c1;
    Dog d1;
    Snake s1;
    //继承了父类中的函数和属性
    //那么就可以调用父类中的函数
    c1.say_name();
    d1.say_name();
    s1.say_name();

    return 0;
}
