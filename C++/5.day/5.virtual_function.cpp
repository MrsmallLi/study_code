/*************************************************************************
	> File Name: 5.virtual_function.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 29 Apr 2024 04:18:34 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

class Animal {
public :
    virtual void say() {
        cout << " Class Animal" << endl;
    }
};

class Cat : public Animal {
public :
    void say() override {
        cout << " Class Cat" << endl;
    }
};

class Dog : public Animal {
public :
    void say() override {
        cout << " Class Dog" << endl;
    }
};

class Bat : public Animal {
public :
    void say() override {
        cout << " Class Bat" << endl;
    }
};
int main() {
    #define MAX_N 10
    srand(time(0));
    Animal *arr[MAX_N + 5];
    for (int i = 0; i < MAX_N; i++) {
        switch (rand() % 3) {
            case 0: arr[i] = new Cat(); break;
            case 1: arr[i] = new Dog(); break;
            case 2: arr[i] = new Bat(); break;
        }
    }
    for (int i = 0; i < MAX_N; i++) {
        arr[i]->say();
    }
    return 0;
}
