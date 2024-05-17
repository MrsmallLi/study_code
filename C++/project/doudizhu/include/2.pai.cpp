/*************************************************************************
	> File Name: 2.pai.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 04 May 2024 09:12:06 AM CST
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

#define MAX_N 18
string name[MAX_N + 5] = {
    "", "", "", "3", "4", "5", "6", "7", "8", "9", "10",
    "J", "Q", "K", "Ace", "2", "joker", "JOKER"
};

class PAI {
public :
    static vector<PAI *> getPai(int *);
    virtual ostream& output() = 0;
};

class PASS : public PAI {
public :
    ostream &output() override {
        cout << " PASS";
        return cout;
    }
    static vector<PAI *> get(int *arr) {
        vector<PAI *> ret;
        ret.push_back(new PASS());
        return ret;
    }
private :

};

class DAN : public PAI {
public :   
    DAN(int x) : x(x) {}
    ostream& output() override {
        cout << "DAN " << name[x];
        return cout;
    }
    static vector<PAI *> get(int *arr) {
        vector<PAI *> ret;
        for (int i = 3; i < MAX_N; i++) {
            if (arr[i] == 0) continue;
            ret.push_back(new DAN(i));
        }

        return ret;
    }
private :
    int x;
};

class DUIZI : public PAI {
public :
    DUIZI(int x) : x(x) {}
    ostream& output() override {
        cout << "DUIZI " << name[x] << " ";
        return cout;
    }   
    static vector<PAI *> get(int *arr) {
        vector<PAI *> ret;
        for (int i = 3; i < MAX_N; i++) {
            if (arr[i] < 2) continue;
            ret.push_back(new DUIZI(i));
        }
        return ret;
    }
private : 
    int x;
};

class SHUNZI : public PAI {
public :   
    SHUNZI(int x, int len) : x(x), len(len) {}
    ostream& output() override {
        cout << "SHUNZI ";
        for (int i = 0; i < x + len;) {
            cout << name[i] << " ";
        }
        return cout;
    }
    static vector<PAI *> get(int *arr) {
        vector<PAI *> ret;
        for (int l = 5; l <= 12; l++) {
            for (int i = 3, I = 14 - l + 1; i <= I; i++) {
                int flag = 1;
                for (int j = i; j < i + l; j++) {
                    if (arr[j]) continue;
                    flag = 0;
                    break;
                }
                if (flag == 1) ret.push_back(new SHUNZI(i, l));
            }
        }
        return ret;
    }
private :
    int x, len;
};

class SANDAI : public PAI {
public : 
    SANDAI(int x, PAI *dai) : x(x), dai(dai) {}
    ostream &output() override {
        cout << "SAN " << name[x] << " DAI ";
        dai->output();
        return cout;
    }
    static vector<PAI *>get(int *arr) {
        vector<PAI *> ret;
        for (int i = 3; i < MAX_N; i++) {
            if (arr[i] < 3) continue;
            ret.push_back(new SANDAI(i, new PASS()));
            for (int j = 3; j < MAX_N; j++)  {
                if (arr[j] == 0 || i == j) continue;
                ret.push_back(new SANDAI(i, new DAN(j)));
                if (arr[j] >= 2) ret.push_back(new SANDAI(i, new DUIZI(j)));
            }
        }
        return ret;
    }
private :
    int x;
    PAI *dai;

};

class ZHADAN : public PAI {
public :
    ZHADAN(int x) : x(x) {}
    ostream &output() {
        return cout << "ZHA " << name[x];
    }
    static vector<PAI *> get(int *arr) {
        vector<PAI *> ret;
        for (int i = 3; i < MAX_N; i++) {
            if (arr[i] < 4) continue;
            ret.push_back(new ZHADAN(i));
        }
        return ret;
    }
private :
    int x;
};

class WANGZHA : public PAI{
public :
    ostream &output() override {
        return cout << "WANGZHA";
    }
    static vector<PAI *> get(int *arr) {
        vector<PAI *> ret;
        if (arr[16] && arr[17]) ret.push_back(new WANGZHA());
        return ret;
    }
private :
};

vector<PAI *> PAI::getPai(int *arr) {
    vector<PAI *> temp;
    vector<PAI *> temp1 = DAN::get(arr);
    vector<PAI *> temp2 = DUIZI::get(arr);
    vector<PAI *> temp3 = SHUNZI::get(arr);
    vector<PAI *> temp4 = SANDAI::get(arr);
    vector<PAI *> temp5 = ZHADAN::get(arr);
    vector<PAI *> temp6 = WANGZHA::get(arr);
    vector<PAI *> temp7 = PASS::get(arr);
    for (auto x : temp1) temp.push_back(x);
    for (auto x : temp2) temp.push_back(x);
    for (auto x : temp3) temp.push_back(x);
    for (auto x : temp4) temp.push_back(x);
    for (auto x : temp5) temp.push_back(x);
    for (auto x : temp6) temp.push_back(x);
    for (auto x : temp7) temp.push_back(x);
    return temp;
}

int main() {
    int arr[MAX_N + 5] = {0};
    int x;
    while (cin >> x) {
        if (x == 0) break;
        arr[x] += 1;
    }
    vector<PAI *> temp = PAI::getPai(arr);
    for (auto x : temp) {
        x->output() << endl;
    }
    return 0;
}
