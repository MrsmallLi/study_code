/*************************************************************************
	> File Name: 4.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 23 Jan 2025 07:46:31 PM CST
 ************************************************************************/

#include "./my_include.h"
using namespace std;



class Solution {
public:
    double find(vector<int> &nums1, int i, vector<int> &nums2, int j, int k) {
        int n = nums1.size(), m = nums2.size();
        if (k == 1) {
            double a = (i == n ? INT_MAX : nums1[i]);
            double b = (j == m ? INT_MAX : nums2[j]);
            return min(a, b);
        }
        if (i == n) return nums2[k - 1];
        if (j == m) return nums1[k - 1];
        int cnt1 = min(k / 2, n - i);
        int cnt2 = min(k - cnt1, m - j);
        cnt1 = k - cnt2;
        if (nums1[i + cnt1 - 1] <= nums2[j + cnt2 - 1]) {
            return find(nums1, i + cnt1, nums2, j, k - cnt1);
        }
        return find(nums1, i, nums2, j + cnt2, k - cnt2);
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        if ((n + m) % 2) return find(nums1, 0, nums2, 0, (n + m) / 2 + 1);
        double a = find(nums1, 0, nums2, 0, (n + m) / 2);
        double b = find(nums1, 0, nums2, 0, (n + m) / 2 + 1);
        return (a + b) / 2;
    }
};


