/*************************************************************************
	> File Name: 1.add.c
	> Author: 
	> Mail: 
	> Created Time: Tue 09 Jul 2024 09:26:24 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <sys/file.h>

char num_file[] = "./.num";
char lock_file[] = "./.lock";

struct Num {
    int now;
    int sum;
};

size_t get_num(struct Num *num)  {
    size_t read;
    FILE *f = fopen(num_file, "r");
    if (f == NULL) {
        perror("fopen");
        exit(1);
    }
    if ((read == fread(num, sizeof(struct Num), 1, f)) < 0) {
        exit(1);
    }
    fclose(f);
    return read;
}

size_t set_num(struct Num *num) {
    FILE *f = fopen(num_file, "wb");
    size_t write = fwrite(num, sizeof(struct Num), 1, f);
    printf(" write %ld \n", write);
    fclose(f);
    return write;
}

void do_add(int max, int x) {
    struct Num num;
    while (1) {
        FILE *lock = fopen(lock_file, "w");
        flock(lock->_fileno, LOCK_EX);
        if (get_num(&num) < 0) {
            fclose(lock);
            continue;
        }
        printf("<%d> : %d %d\n", x, num.now, num.sum);
        if (num.now > max) break;
        num.sum += num.now;
        num.now++;
        set_num(&num);
        flock(lock->_fileno, LOCK_UN);
        fclose(lock);
    }
    return ;
}

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage : %s max ins\n", argv[0]);
        return 1;
    }
    
    int x = 0;
    int max = atoi(argv[1]);
    int ins = atoi(argv[2]);
    pid_t pid;
    struct Num num;
    num.now = 0;
    num.sum = 0;
    set_num(&num);
    for (int i = 0; i < ins; i++) {
        if ((pid = fork()) < 0) {
            perror("fork");
            return 1;
        }
        if (pid == 0) {
            x = i;
            break;
        }
    }

    if (pid == 0) {
        do_add(max, x);
        printf("%d is exit\n", x);
        exit(0);
    }
    while (ins) {
        wait(NULL);
        ins--;
    }
    get_num(&num);
    printf("Ans = %d\n", num.sum);
    return 0;
}
