/*************************************************************************
	> File Name: 4.client.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 30 Jun 2024 09:19:06 PM CST
 ************************************************************************/

#include <iostream>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "./3.char.h"
using namespace std;

struct Msg *share_memory = NULL;


int main(int argc, char **argv) {
    int opt;
    char name[20] = {0};
    while ((opt = getopt(argc, argv, "n:")) != -1) {
        switch(opt) {
            case 'n': {
                strcpy(name, optarg);
            } break;
            default : {
                fprintf(stderr, "Usage : %s -n name\n", argv[0]);
                exit(1);
            }
        }
    }
    int shmid;
    key_t key = ftok(".", 20231007);
    if (( shmid = shmget(key, sizeof(struct Msg), IPC_CREAT | 0666) ) < 0) {
        perror("shmget");
        exit(1);
    }
    share_memory = (struct Msg *)shmat(shmid, NULL, 0);

    while (1) {
        scanf("%[^\n]", share_memory->msg);
        getchar();
        sleep(1);
    }
    return 0;
}

