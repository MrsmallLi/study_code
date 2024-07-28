/*************************************************************************
	> File Name: 1.pthead.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 30 Jun 2024 08:52:27 PM CST
 ************************************************************************/

#include <iostream>
#include <stdlib.h>
#include <pthread.h>
using namespace std;

struct person {
    char name[20];
    int age;
};

void *thread_run(void *arg) {
    int *age = (int *)arg;
    cout << "good is " << *age << endl;
    return NULL;
}

int main() {
    pthread_t tid;
    int age = 18;
    pthread_create(&tid, NULL, thread_run, &age);
    return 0;
}
