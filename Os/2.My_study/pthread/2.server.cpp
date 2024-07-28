/*************************************************************************
	> File Name: 2.server.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 30 Jun 2024 09:13:24 PM CST
 ************************************************************************/

#include <iostream>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdlib.h>
#include <unistd.h>
#include "./3.char.h"
using namespace std;

struct Msg *share_memory = nullptr;


int main() {
    int shmid;
    key_t key = ftok(".", 20231007);
    if (( shmid = shmget(key, sizeof(struct Msg), IPC_CREAT | 0666) ) < 0) {
        perror("shmget");
        exit(1);
    }
    if (( share_memory = (struct Msg *)shmat(shmid, NULL, 0) ) == NULL) {
        perror("shmat");
        exit(1);
    }
    sleep(1);
    return 0;
}
