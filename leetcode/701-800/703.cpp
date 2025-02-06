/*************************************************************************
	> File Name: 703.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 24 May 2024 10:56:34 PM CST
 ************************************************************************/

#include "./my_include.h"
using namespace std;

class KthLargest {
public:
    priority_queue<int, std::vector<int>, std::greater<int>> q;
    int cnt;
    KthLargest(int k, vector<int>& nums) {
        cnt = k;
        for (int i = 0; i < nums.size(); i++)  {
            if (q.size() == k) {
                if (q.top() < nums[i]) {
                    q.pop();
                    q.push(nums[i]);
                }
            } else {
                q.push(nums[i]);
            }
        }
    }

    int add(int val) {
        if (q.size() < cnt) {
            q.push(val);
        }
        else if (q.top() < val)  {
            q.pop();
            q.push(val);
        }
        return q.top();
    }
};

