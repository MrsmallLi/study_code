/*************************************************************************
	> File Name: 3.bigint.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 24 Apr 2024 06:23:57 PM CST
 ************************************************************************/

#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <cstdio>
#include <deque>
using namespace std;

#define test(a) {\
    cout << #a << " = " << (a) << endl;\
}

class Bigint;
ostream &operator<<(ostream &out, const Bigint &a);

class Bigint : public vector<int>{
public :
    Bigint(const int &x = 0) {
        push_back(x < 0 ? -1 : 1);
        push_back(fabs(x));
        proccess_digit();
        return ;
    }
    Bigint(string &s) {
        push_back(s[0] == '-' ? -1 : 1);
        int n = at(0) > 0 ? 0 : 1;
        for (int i = s.length() - 1; i >= n; i--)  {
            push_back(s[i] - '0');
        }
    }
    Bigint(const Bigint &) = default;
    Bigint &operator=(const Bigint &b) {
        clear();
        for (int i = 0; i < b.size(); i++) push_back(b[i]);
        return *this;
    }
    Bigint &operator+=(const Bigint &b) {
        Bigint temp(*this);
        if (temp[0] * b[0] < 0){
            Bigint b1(b);
            if (temp.compare_with(b)) b1 = temp, temp = b;
            temp.subduction(b1);
        }
        else temp.add(b);
        *this = temp;
        return *this;
    }
    void add(const Bigint &b) {
        for (int i = 1; i < b.size(); i++) {
            if (i == size()) push_back(0);
            at(i) += b[i];
        }
        proccess_digit();
        return ;
    }
    Bigint operator+(const Bigint &b) {
        Bigint temp(*this);
        temp += b;
        temp.proccess_digit();
        return temp;
    }
    Bigint &operator*=(const Bigint &b) {
        Bigint temp;
        temp[0] = at(0) * b[0];
        for (int i = 1; i < b.size(); i++) {
            for (int j = 1; j < size(); j++) {
                if (i + j - 1 == temp.size()) temp.push_back(0);
                temp[i + j - 1] += b[i] * at(j);
            }
        }
        temp.proccess_digit();
        *this = temp;
        return *this;
    }
    void push_front(int x) {
        proccess_digit();
        push_back(0);
        for (int i = size() - 1; i >= 1; i--) at(i) = at(i - 1);
        at(1) = x;
        return ;
    }
    Bigint operator*(const Bigint &b) {
        Bigint temp(*this);
        temp *= b;
        return temp;
    }
    bool compare_with(const Bigint &b) {
        if (size() != b.size()) return size() < b.size();
        for (int i = b.size() - 1; i >= 1; i--) {
            if (at(i) == b[i]) continue;
            return b[i] > at(i);
        }
        return false;
    }
    Bigint &operator-=(const Bigint &b) {
        Bigint temp(*this);
        if (temp[0] < 0 && b[0] > 0)  temp.add(b);
        else if (temp[0] > 0 && b[0] < 0) {
            Bigint b1(b);
            b1[0] = 1;
            temp.add(b1);
        }
        else  {
            Bigint b1 = b;
            int flag = 1;
            if (compare_with(b)) b1 = temp, temp = b, flag = 0;
            if (flag) {
                temp[0] = temp[0] > 0 ? 1 : -1;
            }
            else temp[0] = temp[0] > 0 ? -1 : 1;
            temp.subduction(b1);
        }
        *this = temp;
        return *this;
    }
    //两个大整数相减，并且必须是大的减小的
    void subduction(const Bigint &b) {
        for (int i = 1; i < b.size(); i++) {
            at(i) -= b[i];
        }
        unproccess_digit();
        return ;
    }
    Bigint operator-(const Bigint &b) {
        Bigint temp(*this);
        temp -= b;
        temp.proccess_digit();
        return temp;
    }
    // a /= b实现
    Bigint &operator/=(const Bigint &b) {
        Bigint num(at(size() - 1));
        Bigint ans;
        //判断符号
        ans[0] = at(0) * b[0];
        //如果除数比被除数大那么结果为0
        if (compare_with(b)) ans = 0;
        else {
            //进行模拟除法竖式
            for (int i = size() - 2; i >= 1; i--) {
                while (i >= 1 && num.compare_with(b))  {
                    num.proccess_digit();
                    num.push_front(at(i)), i--;
                }
                i++;
                int n = 0;
                while (!num.compare_with(b)) {
                    n += 1;
                    num.subduction(b);
                }
                ans.push_front(n);
                ans.proccess_digit();
            }
        }
        *this = ans;
        return *this;
    }
    // a / b 的实现
    Bigint operator/(const Bigint &b) {
        Bigint temp(*this);
        temp /= b;
        temp.proccess_digit();
        return temp;
    }
    // 加乘除的进位和去除前置0
    void proccess_digit() {
        for (int i = 1; i < size(); i++) {
            if (at(i) < 10) continue;
            if (i + 1 == size()) push_back(0);
            at(i + 1) += at(i) / 10;
            at(i) %= 10;
        }
        while (size() > 2 && at(size() - 1) == 0) pop_back();
        return ;
    }
    //减的进行补数，当前位数如果小于0进行借位
    void unproccess_digit() {
        for (int i = 1; i < size(); i++) {
            if (at(i) >= 0) continue;
            int n = 0;
            while (at(i) < 0) at(i) += 10, n++;
            at(i + 1) -= n;
        }
        while (size() > 2 && at(size() - 1) == 0) pop_back();
        return ;
    }
};

ostream &operator<<(ostream &out, const Bigint &a) {
    if (a[0] < 0) cout << "-";
    for (int i = a.size() - 1; i >= 1; i--) {
        cout << a[i];
    }
    return out;
}

namespace test1 {

int main() {
    string n, m;
    while (cin >> n >> m) {
        Bigint a(n), b(m);
        test(a);
        test(b);
        test(a / b);
        cout << "=================" << endl;
        test(a);
        test(b);
        test(a /= b);
        cout << "=================" << endl;
        test(a);
        test(b);
        a.push_front(1);
    }
    return 0;
}
}

int main() {
    test1::main();
    return 0;
}


