/*************************************************************************
	> File Name: 2.test.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 16 Apr 2024 05:41:10 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;


class People {
public :
    void speak() {
        cout << "my age is "<< age << endl;
        return ;
    }
    void set_age(int x) {
        if (age <= 0 || age > 1000) {
            perror("your age is error\n");
            exit(1);
        }
        age = x;
        return ;
    }
    int get_age() {
        return age;
    }
private :
    int age;
};


int main() {
    People a;
    a.set_age(-100);
    a.speak();
    return 0;
}
