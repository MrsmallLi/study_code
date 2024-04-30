/*************************************************************************
	> File Name: 1.virtual_funcion.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 29 Apr 2024 06:08:57 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

class Animal{
public :
    virtual void say() = 0;
};

class Cat : public Animal{
public :
    void say() override {
        cout << "Class Cat" << endl;
    }
};

class Dog : public Animal{
public :
    void say() override {
        cout << "Class Dog" << endl;
    }
};

class Bat : public Animal{
public :
    void say() override {
        cout << "Class Bat" << endl;
    }
};

int main() {
    


    return 0;
}
