/*************************************************************************
	> File Name: test.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 08 Feb 2025 04:14:01 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

/*************************************************************************
	> File Name: 5.E.cpp
	> Author:
	> Mail:
	> Created Time: 六  2/ 8 14:56:01 2025
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class BigInt : public vector<int>
{
public :
    BigInt(){}
    BigInt(string s)
    {
        for(int i = s.size() - 1; i >= 0; i--)
        {
            this->push_back(s[i] - '0');
        }
        porccess_digit();
        return ;
    }

    void operator-=(BigInt &a)
    {
        for(int i = 0; i < a.size(); i++)
        {
            if(at(i) < a[i])
            {
                at(i + 1) -= 1;
                at(i) += 10;
                at(i) -= a[i];
            }
            else
            {
                at(i) -= a[i];
            }
        }
        porccess_digit();
        return ;
    }

    void porccess_digit()
    {
        for(int i = 0; i < size(); i++)
        {
            if(at(i) < 10) continue;
            if(i + 1 == size()) this->push_back(0);
            at(i + 1) += at(i) / 10;
            at(i) %= 10;
        }
        while(size() > 1 && at(size() - 1) == 0) this->pop_back();
        return ;
    }
};

ostream &operator<<(ostream &out, BigInt &a)
{
    for(int i = a.size() - 1; i >= 0; i--)
    {
        out << a[i];
    }
    return out;
}

void solve()
{
    string s1, s2;
    cin >> s1 >> s2;
    if(s1.size() == s2.size() && s1 == s2)
    {
        cout << 0 << endl;
    }
    else if(s1.size() > s2.size() || (s1.size() == s2.size() && s1 > s2))
    {
        BigInt a, b;
        a = s1;
        b = s2;
        a -= b;
        cout << a << endl;
    }
    else
    {
        BigInt a, b;
        a = s1;
        b = s2;
        b -= a;
        cout << '-' << b << endl;
    }
    return ;
}


int main()
{
    solve();
    return 0;
}
