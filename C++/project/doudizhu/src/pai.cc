/*************************************************************************
	> File Name: 2.pai.cc
	> Author: 
	> Mail: 
	> Created Time: Sat 04 May 2024 09:12:06 AM CST
 ************************************************************************/

#include <iostream>
#include <vector>
#include <pai.h>
using namespace std;

#define MAX_N 18

static string name[MAX_N + 5] = {
    "", "", "", "3", "4", "5", "6", "7", "8", "9", "10",
    "J", "Q", "K", "Ace", "2", "joker", "JOKER"
};

PAI::PAI(PAI_TYPE type) : type(type) {}

void PAI::output_arr(int *arr) {
    for (int i = 3; i < MAX_N; i++) {
        if (arr[i] == 0) continue;
        cout << name[i] << "*" << arr[i] << " ";
    }
    cout << endl;
    return ;
}

void PASS::take(int *arr) { return ; }
void PASS::back(int *arr) { return ; }
PASS::PASS() : PAI(PAI_TYPE::PASS_TYPE) {}

ostream &PASS::output() {
        cout << "Pass";
        return cout;
}

vector<PAI *> PASS::get(int *arr) {
    vector<PAI *> ret;
    ret.push_back(new PASS());
    return ret;
}

bool PASS::operator>(PAI *pre) {
    return pre->type != PAI_TYPE::PASS_TYPE;
}

void DAN::take(int *arr) { arr[x] -= 1; return ; }
void DAN::back(int *arr) { arr[x] += 1; return ; }

DAN::DAN(int x) : x(x), PAI(PAI_TYPE::DAN_TYPE) {}
ostream& DAN::output() {
    cout << "Dan " << name[x];
    return cout;
}
vector<PAI *> DAN::get(int *arr) {
    vector<PAI *> ret;
    for (int i = 3; i < MAX_N; i++) {
        if (arr[i] == 0) continue;
        ret.push_back(new DAN(i));
    }
    return ret;
}

bool DAN::operator>(PAI *pre) {
    switch (pre->type) {
        case PAI_TYPE::PASS_TYPE : return true;
        case PAI_TYPE::DAN_TYPE : {
            DAN *pre_ = dynamic_cast<DAN *>(pre);
            return this->x > pre_->x;
        } break;
        default : return false;
    }
    return false;
}

void DUIZI::take(int *arr) { arr[x] -= 2; return ; }
void DUIZI::back(int *arr) { arr[x] += 2; return ; }

DUIZI::DUIZI(int x) : x(x), PAI(PAI_TYPE::DUIZI_TYPE){}
ostream& DUIZI::output() {
    cout << "DuiZi " << name[x] << " ";
    return cout;
}   
vector<PAI *> DUIZI::get(int *arr) {
    vector<PAI *> ret;
    for (int i = 3; i < MAX_N; i++) {
        if (arr[i] < 2) continue;
        ret.push_back(new DUIZI(i));
    }
    return ret;
}

bool DUIZI::operator>(PAI *pre) {
    switch (pre->type) {
        case PAI_TYPE::PASS_TYPE : return true;
        case PAI_TYPE::DUIZI_TYPE : {
            DUIZI *pre_ = dynamic_cast<DUIZI *>(pre);
            return this->x > pre_->x;
        } break;
        default : return false;
    }
    return false;
}

void SHUNZI::take(int *arr) { 
    for (int i = x; i < x + len; i++) arr[i] -= 1;
    return ;
}
void SHUNZI::back(int *arr) { 
    for (int i = x; i < x + len; i++) arr[i] += 1;
    return ;
}

SHUNZI::SHUNZI(int x, int len) : x(x), len(len), PAI(PAI_TYPE::SHUNZI_TYPE){}
ostream& SHUNZI::output() {
    cout << "ShunZi ";
    for (int i = x; i < x + len; i++) {
        cout << name[i] << " ";
    }
    return cout;
}
vector<PAI *> SHUNZI::get(int *arr) {
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

bool SHUNZI::operator>(PAI *pre) {
    switch (pre->type) {
        case PAI_TYPE::PASS_TYPE : return true;
        case PAI_TYPE::SHUNZI_TYPE : {
            SHUNZI *pre_ = dynamic_cast<SHUNZI *>(pre);
            if (this->len != pre_->len) return false;
            return this->x > pre_->x;
        } break;
        default : return false;
    }
    return false;
}

void SANDAI::take(int *arr) {
    arr[x] -= 3;
    dai->take(arr);
    return ;
}

void SANDAI::back(int *arr) {
    arr[x] += 3;
    dai->back(arr);
    return ;
}

SANDAI::SANDAI(int x, PAI *dai) : x(x), dai(dai), PAI(PAI_TYPE::SANDAI_TYPE){}
ostream &SANDAI::output() {
    cout << "San " << name[x] << " Dai ";
    dai->output();
    return cout;
}
vector<PAI *> SANDAI::get(int *arr) {
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

bool SANDAI::operator>(PAI *pre) {
    switch (pre->type) {
        case PAI_TYPE::PASS_TYPE : return true;
        case PAI_TYPE::SANDAI_TYPE : {
            SANDAI *pre_ = dynamic_cast<SANDAI *>(pre);
            if (this->dai->type != pre_->dai->type) return false;
            return this->x > pre_->x;
        } break;
        default : return false;
    }
    return false;
}


void ZHADAN::take(int *arr) { arr[x] -= 4; return ;}
void ZHADAN::back(int *arr) { arr[x] += 4; return ;}

ZHADAN::ZHADAN(int x) : x(x), PAI(PAI_TYPE::ZHADAN_TYPE){}
ostream &ZHADAN::output() {
    return cout << name[x] << " Zha";
}
vector<PAI *> ZHADAN::get(int *arr) {
    vector<PAI *> ret;
    for (int i = 3; i < MAX_N; i++) {
        if (arr[i] < 4) continue;
        ret.push_back(new ZHADAN(i));
    }
    return ret;
}

bool ZHADAN::operator>(PAI *pre) {
    switch (pre->type) {
        case PAI_TYPE::WANGZHA_TYPE : return false;
        case PAI_TYPE::ZHADAN_TYPE : {
            ZHADAN *pre_ = dynamic_cast<ZHADAN *>(pre);
            return this->x > pre_->x;
        } break;
        default : return true;
    }
    return false;
}

WANGZHA::WANGZHA() : PAI(PAI_TYPE::WANGZHA_TYPE) {}
ostream &WANGZHA::output() {
    return cout << "WangZha";
}
vector<PAI *> WANGZHA::get(int *arr) {
    vector<PAI *> ret;
    if (arr[16] && arr[17]) ret.push_back(new WANGZHA());
    return ret;
}

void WANGZHA::take(int *arr) {
    arr[16] -= 1;
    arr[17] -= 1;
    return ;
}

void WANGZHA::back(int *arr) {
    arr[16] += 1;
    arr[17] += 1;
    return ;
}

bool WANGZHA::operator>(PAI *pre) {
    switch (pre->type) {
        case PAI_TYPE::WANGZHA_TYPE : return false;
        default : return true;
    }
    return false;
}


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

vector<PAI *> PAI::getLegalPai(int *arr, PAI *pai) {
    vector<PAI *> temp1 = getPai(arr);
    vector<PAI *> temp;
    for (auto x : temp1) {
        if ((x->operator>(pai))) temp.push_back(x);
        else {
            delete x;
        }
    }
    return temp;
}
