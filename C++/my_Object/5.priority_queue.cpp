/*************************************************************************
	> File Name: 5.priority_queue.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 28 May 2024 06:56:23 PM CST
 ************************************************************************/

#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;

#define BEGIN(a) namespace a {
#define END(a) }

BEGIN(my)

class IQueue {
public :
    virtual void push(int ) = 0;
    virtual void pop() = 0;
    virtual bool empty() = 0;
    virtual int top() = 0;
    virtual int front() = 0;
    virtual int size() = 0;
    virtual ~IQueue() {}
};


class queue : private std::vector<int>, public IQueue {
public :
    queue() {}
    queue(int x) {}
    queue(const queue &obj) {
        for (int i = 0; i < obj.vector<int>::size(); i++) {
            vector<int>::push_back(obj.at(i));
        }
    }
    void push(int x) override {
        vector<int>::push_back(x);
        return ;
    }
    void pop() override {
        vector<int>::erase(vector<int>::begin());
        return ;
    }
    bool empty() override {
        return vector<int>::empty();
    }
    int front() override {
        if (empty()) {
            printf("Queue is empty\n");
            exit(1);
        }
        return vector<int>::at(0);
    }
    int top() override {
        printf("Don't have top function\n");
        exit(1);
    }
    int size() override {
        return vector<int>::size();
    }
};

class priority_queue : public IQueue, private vector<int> {
public :
    priority_queue() {
        vector<int>::push_back(0);
    }
    priority_queue(const priority_queue &obj) {
        for (int i = 0; i < obj.vector<int>::size(); i++) {
            vector<int>::push_back(obj.at(i));
        }
    }
    void push(int x) override {
        push_back(x);
        int ind = vector<int>::size() - 1;
        int temp = ind >> 1;
        while (temp && vector<int>::at(ind) > vector<int>::at(temp)) {
            std::swap(vector<int>::at(ind), vector<int>::at(temp));
            ind = temp;
            temp >>= 1;
        }
        return ;
    }
    void pop() override {
        vector<int>::erase(vector<int>::begin());
        int ind = 1;
        while (ind <= size() && (ind << 1) <= size()) {
            int temp = ind, l = ind << 1, r = ind << 1 | 1;
            if (vector<int>::at(temp) < vector<int>::at(l)) temp = l;
            if (r <= size() && vector<int>::at(temp) < vector<int>::at(l)) temp = r;
            if (temp == ind) break;
            std::swap(vector<int>::at(temp), vector<int>::at(ind));
            ind = temp;
        }
        return ;
    }
    int top() override {
        return vector<int>::at(1);
    }
    int front() override {
        printf("No function front\n");
        exit(1);
    }
    bool empty() override {
        return vector<int>::empty();
    }
    int size() override {
        return vector<int>::size() - 1;
    }
    void output() {
        for (int i = 1; i < vector<int>::size(); i++) {
            cout << at(i) << " " << endl;
        }
        return ;
    }
};

END(my)

int main() {
    srand(time(0));
    my::queue q;
    #define MAX_N 10
    for (int i = 0; i < MAX_N; i++) q.push(i);
    cout << q.size() << endl;
    cout << q.front() << endl;
    cout << q.empty() << endl;
    q.pop() ;
    cout << q.front() << endl;
    my::priority_queue pq;
    for (int i = 0; i < MAX_N; i++) pq.push(rand() % 100);
    pq.output();
    cout << pq.top() << endl;
    cout << pq.empty() << endl;
    cout << pq.size() << endl;
    pq.pop();
    cout << pq.top() << endl;
    return 0;
}
