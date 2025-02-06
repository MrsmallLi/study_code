/*************************************************************************
	> File Name: 380_3.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 26 Jan 2025 07:20:33 PM CST
 ************************************************************************/

#include "./my_include.h"
using namespace std;

class RandomizedSet {
public:
    RandomizedSet() {
        srand(time(0));
    }
    
    bool insert(int val) {
        if (mp.find(val) != mp.end()) return false;
        arr.push_back(val);
        mp[val] = arr.size() - 1;
        return true;
    }
    
    bool remove(int val) {
        if (mp.find(val) == mp.end()) return false;
        mp[arr[arr.size() - 1]] = mp[val];
        swap(arr[mp[val]], arr[arr.size() - 1]);
        arr.pop_back();
        mp.erase(val);
        return true;
    }
    
    int getRandom() {
        return arr[rand() % arr.size()];
    }
private :
    vector<int> arr;
    unordered_map<int, int> mp;
};

