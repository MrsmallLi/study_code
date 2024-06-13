/*************************************************************************
	> File Name: test.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 12 Jun 2024 11:07:46 PM CST
 ************************************************************************/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <stack>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <ctime>
using namespace std;

#define MAX_NUM 100

void test(vector<int> v){
    for (int i=1;i<v.size(); i++) {
        if(v[i]<v[i-1]){
            cout<<"FAIL"<<endl;
            return;
        }
    }
    cout<<"OK"<<endl;
    return;
}

void quick_sort(int *arr,int l,int r){
    if(r <= l)return;
    int x=l,y=r,z=arr[r];
    while(x<y){//指针交替
        while(x<y&&arr[x]<z)x++;
        while(x<y&&arr[y]>=z)y--;
        if(x<y)swap(arr[x],arr[y]);
    }
    swap(arr[x],arr[r]);
    quick_sort(arr, l, x-1);
    quick_sort(arr, x+1, r);
    return;
}
    
int main(){
    srand(time(0));
    vector<int> v(MAX_NUM);
    for (auto &x:v) {
        x=rand()%1000;
    }
        

    quick_sort(&v[0], 0, MAX_NUM-1);
    test(v);
    for (auto x:v) {
        cout<<x<<" ";
    }
    cout<<endl;
    return 0;

}


