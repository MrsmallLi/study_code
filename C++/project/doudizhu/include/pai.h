/*************************************************************************
> File Name: pai.h
	> Author: 
	> Mail: 
	> Created Time: Sat 04 May 2024 10:50:59 AM CST
 ************************************************************************/

#ifndef _PAI_H
#define _PAI_H
#include <vector>
#include <iostream>
using namespace std;

#define MAX_N 18

enum class PAI_TYPE {
    DAN_TYPE,
    DUIZI_TYPE,
    SHUNZI_TYPE,
    SANDAI_TYPE,
    ZHADAN_TYPE,
    WANGZHA_TYPE,
    PASS_TYPE
};

class PAI {
public :
    PAI(PAI_TYPE type);
    static vector<PAI *> getPai(int *);
    static vector<PAI *> getLegalPai(int *, PAI *);
    static void output_arr(int *);
    virtual ostream& output() = 0;
    virtual bool operator>(PAI *pre) = 0;
    virtual void take(int *) = 0;
    virtual void back(int *) = 0;
    virtual ~PAI() = default;
    PAI_TYPE type;
};

class PASS : public PAI {
public :
    PASS();
    ostream &output() override;
    static vector<PAI *> get(int *arr);
    bool operator>(PAI *pre) override;
    void take(int *);
    void back(int *);
};

class DAN : public PAI {
public :
    DAN(int x);
    ostream& output() override;
    bool operator>(PAI *pre) override;
    static vector<PAI *> get(int *arr);
    void take(int *);
    void back(int *);
private :
    int x;
};

class DUIZI : public PAI {
public :
    DUIZI(int x);
    ostream& output() override;
    bool operator>(PAI *pre) override;
    static vector<PAI *> get(int *arr);
    void take(int *);
    void back(int *);
private :
    int x;
};

class SHUNZI : public PAI {
public :
    SHUNZI(int x, int len);
    ostream& output() override;
    bool operator>(PAI *pre) override;
    static vector<PAI *> get(int *arr);
    void take(int *);
    void back(int *);
private :
    int x, len;
};

class SANDAI : public PAI {
public :
    SANDAI(int x, PAI *dai);
    ostream &output() override;
    static vector<PAI *>get(int *arr);
    bool operator>(PAI *pre) override;
    void take(int *);
    void back(int *);
private :
    int x;
    PAI *dai;
};

class ZHADAN : public PAI {
public :
    ZHADAN(int x);
    ostream &output();
    bool operator>(PAI *pre) override;
    static vector<PAI *> get(int *arr);
    void take(int *);
    void back(int *);
private :
    int x;
};

class WANGZHA : public PAI{
public :
    WANGZHA();
    ostream &output() override;
    bool operator>(PAI *pre) override;
    static vector<PAI *> get(int *arr);
    void take(int *);
    void back(int *);
private :
};
#endif
