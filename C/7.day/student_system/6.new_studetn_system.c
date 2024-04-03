/*************************************************************************
	> File Name: 4.student_system.c
	> Author: 
	> Mail: 
	> Created Time: Tue 02 Apr 2024 03:57:22 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//第一步，由于操作的是二进制文件，所以要把文件后缀名改为dat
const char *file_name = "new_student_data.dat";
#define output_format  "%10s%4d%4d%7.2lf"


typedef struct Student {
    long offset;
    char name[20];
    int age;
    int class;
    double height;
} Student;

#define MAX_N 10000
Student stu_arr[MAX_N + 5];
int stu_cnt;

//对文件进行了操作就需要，修改为二进制形式的操作
int read_from_file(Student *arr) {
    int i = 0;
    FILE *fp = fopen(file_name, "rd");//1.修改打开模式
    if (fp == NULL) return 0;
    while (1) {
        long offset = ftell(fp);
        //读取文件,换为fread读取
        //fread的返回值是读取了多少个字节
        if (fread(arr + i, sizeof(Student), 1, fp) == 0) break;
        arr[i].offset = offset;
        //fgetc(fp); 在二进制文件中没有换行符了，所以就没有必要去吞掉换行符了
        i++;
    }
    fclose(fp);
    return i;
}
int output_to_file(Student *arr, int n) {
    FILE *fp = fopen(file_name, "ab");//修改打开模式
    fseek(fp, 0, SEEK_END);
    long offset = ftell(fp);
    //修改写入模式
    fwrite(arr, sizeof(Student), n, fp);
    fclose(fp);
    return offset;
}


void restor_data_to_file(Student *arr, int n) {
    FILE *fp = fopen(file_name, "w");
    fclose(fp);
    output_to_file(arr, n);
    return ;
}

void modify_data_to_file(Student *arr) {
    FILE *fp = fopen(file_name, "rb+");//修改打开模式
    fseek(fp, arr->offset, SEEK_SET);
    //修改写入模式
    fwrite(arr, sizeof(Student), 1, fp);
    fclose(fp);
    return ;
}


enum NO_TYPE {
    LIST = 1,
    ADD,
    MODIFY,
    DELETE,
    QUIT
};


int usage() {
    int no;
    stu_cnt = read_from_file(stu_arr);
    do {
        printf("%d. list students\n", LIST);
        printf("%d. add a new stdents\n", ADD);
        printf("%d. list modify a students\n", MODIFY);
        printf("%d. delete a students\n", DELETE);
        printf("%d. quit system\n", QUIT);
        printf("mysql>");
        scanf("%d", &no);
        if (no < 1 || no > 5) printf("intput error\n");
    } while(no < 1 || no > 5);
    return no;
}

void list_students() {
    int len = 0;
    len = printf("%4s|%10s|%4s|%6s|%7s|\n", 
           "id",
           "name",
           "age",
           "class",
           "height") ;
    while (--len) printf("=");
    putchar(10);
    for (int i = 0; i < stu_cnt; i++) {
    len = printf("%4d|%10s|%4d|%6d|%7.2lf|\n", 
           i,
           stu_arr[i].name,
           stu_arr[i].age,
           stu_arr[i].class,
           stu_arr[i].height) ;
    }
    return ;
}

void add_to_student() {
    printf("add new item : (name, age, class, height)\n");
    printf("mysql > ");
    scanf("%s%d%d%lf",
          stu_arr[stu_cnt].name,
          &stu_arr[stu_cnt].age,
          &stu_arr[stu_cnt].class,
          &stu_arr[stu_cnt].height
    );
    stu_arr[stu_cnt].offset = output_to_file(stu_arr + stu_cnt, 1);
    stu_cnt++;
    printf("add a new student success\n");
    return ;
}

void modify_a_student() {
    if (!stu_cnt) {
        printf("there haven't student\n");
        return ;
    }
    list_students();
    int id;
    do {
        printf("modify id : ");
        scanf("%d", &id);
    } while (id < 0 || id >= stu_cnt);
    printf("modify item : (name, age, class, height)\n");
    printf("mysql >");
    scanf("%s%d%d%lf",
          stu_arr[id].name,
          &stu_arr[id].age,
          &stu_arr[id].class,
          &stu_arr[id].height
    );
    modify_data_to_file(stu_arr + id);
    return ;
}

void delete_a_student() {
    if (stu_cnt == 0) {
        printf("there no have one students\n");
        return ;
    }
    list_students();
    int id; 
    do {
        printf("delete id : ");
        scanf("%d", &id);
    } while (id < 0 || id >= stu_cnt);
    char c;
    do {
        printf("confirm (y / n) :");
        scanf("%c", &c);
    } while (c != 'y' && c != 'n');
    if (c == 'n') return ;
    for (int i = id; i < stu_cnt - 1; i++) {
        long offset = stu_arr[i].offset;
        stu_arr[i] = stu_arr[i + 1];
        stu_arr[i].offset = offset;
    }
    stu_cnt--;
    restor_data_to_file(stu_arr, stu_cnt);
    return ;
}


int main() {
    while  (1) {
        int no = usage();
        switch (no) {
            case LIST:  {
                list_students();
            }; break; 
            case ADD:  {
                add_to_student();
            } break;
            case MODIFY:  {
                modify_a_student();
            } break;
            case DELETE: {
                delete_a_student();
            } break;
            case QUIT: printf("Thanks used\n");exit(0);
            default : printf("error\n"); exit(1);
        }
    }
    return 0;
}
