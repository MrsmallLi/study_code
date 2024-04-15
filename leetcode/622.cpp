/*************************************************************************
	> File Name: 622.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 12 Apr 2024 03:30:51 PM CST
 ************************************************************************/

#include <./my_include.h>
using namespace std;

class MyCircularQueue {
public:
    MyCircularQueue(int k) {
        q.resize(k);
        head = 0, tail = 0;
        count = 0;
        size = k;
    }
    
    bool enQueue(int value) {
        if (isFull()) return false;
        q[tail] = value;
        tail = (tail + 1) % size;
        count++;
        return true;
    }
    
    bool deQueue() {
        if (isEmpty()) return false;
        head = (head + 1) % size;
        count--;
        return true;
    }
    
    int Front() {
        if (isEmpty()) return -1;
        return q[head];
    }
    
    int Rear() {
        if (isEmpty()) return -1;
        return q[(tail - 1 + size) % size];
    }
    
    bool isEmpty() {
        return count == 0;
    }
    
    bool isFull() {
        return count == q.size();
    }
private :
    vector<int> q;
    int head, tail, count, size;
};
