/*************************************************************************
	> File Name: 380.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 28 Mar 2024 03:17:32 PM CST
 ************************************************************************/

#include "./my_include.h"
using namespace std;

#define P(a) (a ? "True" : "False")

class RandomizedSet {
public:
    RandomizedSet() {
        srand(time(0));
    }

    bool insert(int val) {
        auto it = mp.find(val);
        if (it != mp.end()) return false; 
        nums.push_back(val);
        mp[val] = nums.size() - 1;
        return true;
    }

    bool remove(int val) {
        auto it = mp.find(val);
        if (it == mp.end()) return false; 
        nums[mp[val]] = nums.back();
        mp[nums.back()] = mp[val];
        mp.erase(val);
        nums.pop_back();
        return true;
    }

    int getRandom() {
        int n = nums.size();
        return nums[rand() % n];
    }

private :
    unordered_map<int, int> mp;
    vector<int> nums;
};


int main() {
    RandomizedSet r;
    cout << P(r.insert(1)) << endl;
    cout << P(r.insert(0)) << endl;
    cout << P(r.remove(1)) << endl;
    cout << P(r.insert(2)) << endl;
    cout << P(r.remove(0)) << endl;
    cout << r.getRandom() << endl;
    return 0;
}
