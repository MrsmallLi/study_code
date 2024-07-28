/*************************************************************************
	> File Name: 1.vistor.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 26 Jun 2024 03:29:05 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

class B;
class C;
class D;
class E;

class A {
public :
    class IVisitor {
    public :
        virtual void visit(A *) = 0;
        virtual void visit(B *) = 0;
        virtual void visit(C *) = 0;
        virtual void visit(D *) = 0;
        virtual void visit(E *) = 0;
    };
    virtual void Accept(IVisitor *vis) {
        vis->visit(this);
    }
    virtual ~A() {}
};

class B : public A {
public :
    void Accept(IVisitor *vis) override {
        vis->visit(this);
    }
};

class D : public A{
public :
    void Accept(IVisitor *vis) override {
        vis->visit(this);
    }
};

class C : public A{
public :
    void Accept(IVisitor *vis) override {
        vis->visit(this);
    }
};

class E : public A{
public :
    void Accept(IVisitor *vis) override {
        vis->visit(this);
    }
};

class OutputVisitor : public A::IVisitor {
    virtual void visit(A *obj) {
        cout << "this is a class A object" << endl;
    }
    virtual void visit(B *obj) {
        cout << "this is a class B object" << endl;
    }
    virtual void visit(C *obj) {
        cout << "this is a class C object" << endl;
    }
    virtual void visit(D *obj) {
        cout << "this is a class D object" << endl;
    }
    virtual void visit(E *obj) {
        cout << "this is a class E object" << endl;
    }
};



int main() {
    A *arr[10];
    for (int i = 0; i < 10; i++) {
        switch (rand() % 4) {
            case 0 : arr[i] = new B(); break;
            case 1 : arr[i] = new D(); break;
            case 2 : arr[i] = new C(); break;
            case 3 : arr[i] = new E(); break;
        }
    }
    OutputVisitor vis;
    for (int i = 0; i < 10; i++) {
        arr[i]->Accept(&vis);
    }
    return 0;
}
