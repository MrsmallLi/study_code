/*************************************************************************
	> File Name: 2.my_shared_ptr.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 21 May 2024 01:20:46 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

class A {
public :
    A() : x(0), y(0){
        cout << "defalut constructor" << endl;
    }
    ~A() {
        cout << "destructor" << endl;
    }
    int x, y;
};

class shared_ptr {
public :
    shared_ptr() : a(nullptr) { count += 1; }
    shared_ptr(A *a) : a(a) { count += 1; }
    shared_ptr(const shared_ptr &ptr) {
        this->a = ptr.a;
        count += 1;
    }
    int use_count() {
        return count;
    }
    A &operator*() {
        return *(this->a);
    }
    shared_ptr &operator=(shared_ptr *ptr) {
        if (!ptr) {
            count -= 1;
        }
        if (!count) delete a;
        return *ptr;
    }
    A *a;
    static int count;
};

int shared_ptr::count = 0;

shared_ptr make_shared() {
    return shared_ptr(new A());
}

ostream& operator<<(ostream &out, const A &a) {
    cout << a.x << " " << a.y;
    return out;
}

int main() {
    shared_ptr p = make_shared();
    cout << *p << endl;
    p.a->x = 3;
    p.a->y = 4;
    cout << *p << endl;
    cout << "p.use_count = " << p.use_count() << endl;
    shared_ptr q = p;
    cout << "p.use_count = " << p.use_count() << endl;
    cout << "q.use_count = " << q.use_count() << endl;
    p = nullptr;
    cout << "q.use_count = " << q.use_count() << endl;
    q = nullptr;
    return 0;
}
