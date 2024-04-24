/*************************************************************************
	> File Name: 6.move_constructor.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 23 Apr 2024 02:52:40 PM CST
 ************************************************************************/

#include <iostream>
#include <cassert>
#include <ctime>
using namespace std;

class Array {
public :
    Array(int n) : n(n), arr(new int[n]) {
        cout << "array default constructor " << arr << endl;
    }
    Array(const Array &a) : n(a.n), arr(new int[n]) {
        cout << "copy array constructor " << arr << endl;
        for (int i = 0; i < n; i++) arr[i] = a[i];
        return ;
    }
    //再函数调用时，如果没有返回值优化
    //那么调用func()函数时，会先默认构造a,
    //默认构造返回值的隐匿对象,这里创建了新的空间
    //然后a拷贝给匿名对象
    //然后又将匿名拷贝给b对象,有创建了新空间
    //而移动构造,直接将第一次a创建的空间直接给匿名对象
    //匿名对象又通过移动构造将创建的空间给b对象，省去了中间创建新空间的步骤和释放空间的步骤
    Array(Array &&a) : n(a.n), arr(a.arr) {
        cout << "move constructor" << arr << endl;
        a.arr = nullptr;
        a.n = 0;
        return ;
    }
    //这里为什么要返回int &
    //因为你在访问该位置时，又可以能会将该位置进行赋值
    //所以需要返回int &
    int &operator[](int ind) const{
        assert(ind >= 0 && ind < n);
        return arr[ind];
    }
    
    void output(const char *frm) {
        for (int i = 0; i < n; i++) {
            printf(frm, i, arr[i]);
        }
    }
    ~Array() {
        if (arr) delete[] arr;
        cout << "array disconstructor " << arr << endl;
        return ;
    }
private :
    int n;
    int *arr;
};

Array func() {
    int n = 7;
    Array a(n);
    for (int i = 0; i < n; i++) {
        a[i] = i;
    }
    return a;
}

int main() {
    srand(time(0));
    int n = 10;
    printf("a = ");
    Array a(n);
    for (int i = 0; i < n; i++) {
        a[i] = rand() % 100;
    }
    a.output("a[%d] = %d\n");
    Array b = func();
    b[0] = 999;
    b.output("b[%d] = %d\n");
    //如果对于a对象不用了，想将a对象所有的东西给c对象
    //那么就可以调用移动构造，使用move函数将a对象传入时变为右值
    Array c(move(a));
    c.output("c[%d] = %d\n");
    return 0;
}
