/*************************************************************************
	> File Name: 274.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 28 Mar 2024 03:06:01 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

class Solution {
public:

    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int n = citations.size();
        int min = 0, h = 0;
        for (int i = n - 1; i >= 0; i--) {
            min = citations[i]; 
            if (citations[i] >= h + 1) h++;
        }
        return h;
    }
};
