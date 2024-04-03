/*************************************************************************
	> File Name: 4.student_system.c
	> Author: 
	> Mail: 
	> Created Time: Tue 02 Apr 2024 03:57:22 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//对于优化后的系统，需要用打开一个新的文本
//对于文件写入的格式不同,所以需要打开新的文本
const char *file_name = "new_student_data.txt";
//设置一个对于学生信息输出的标准
#define output_format  "%10s%4d%4d%7.2lf"


typedef struct Student {
    //添加一个变量，用来记录当前学生信息在文件中文件指针的位置
    long offset;
    char name[20];
    int age;
    int class;
    double height;
} Student;

#define MAX_N 10000
Student stu_arr[MAX_N + 5];
int stu_cnt;

//优化1
//在文件中读入数据进行初始化学生数组时，进行对文件指针位置的初始化
int read_from_file(Student *arr) {
    int i = 0;
    FILE *fp = fopen(file_name, "r");
    if (fp == NULL) return 0;
    while (1) {
        //通过ftell获取当前文件指针的位置
        long offset = ftell(fp);
        //这里while换成if判断，所以需要将!= 改为==
        if (fscanf(fp, "%s", arr[i].name) == EOF) break;
        fscanf(fp, "%d%d%lf", 
                &arr[i].age, 
                &arr[i].class, 
                &arr[i].height
        );
        //对该行学生信息的文件指针位置进行初始化
        //初始化值为该行学生信息的开头
        arr[i].offset = offset;
        //现在文件指针位置是指向换行符
        //那么需要处理换行符,用函数fgetc
        fgetc(fp);
        //fgetc的作用是读取文件中的一个字符，而读取位置就是文件指针的位置
        //那么读取后文件指针就会移动到下一个字符的位置
        //对应在我们这个文件中，就是下个学生信息的开头
        i++;
    }
    fclose(fp);
    return i;
}
//优化2
//维护添加新学生信息时，进行对新学生信息在文件中的指针位置
int output_to_file(Student *arr, int n) {
    FILE *fp = fopen(file_name, "a");
    //将文件指针位置设置到文件末尾
    fseek(fp, 0, SEEK_END);
    long offset = ftell(fp);
    for (int i = 0; i < n; i++) {
        //添加学生信息时，也要进行格式化控制每条信息的长度
        fprintf(fp, output_format"\n",
                arr[i].name,
                arr[i].age,
                arr[i].class,
                arr[i].height);
    }
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
    FILE *fp = fopen(file_name, "r+");
    //arr->offset 等价于stu_arr[id].offset
    //arr->offset 转换 *(arr).offset
    //而arr是形参他的值是 stu_arr + id
    //那么 arr->offset 等价于 *(stu_arr + id).offset 而*(stu_arr + id) 等价于 stu_arr[id]
    //最后 arr->offset 等价于stu_arr[id].offset
    fseek(fp, arr->offset, SEEK_SET);
    //通过设置的标准输出格式，来进行设置学生信息输出的长度
    //就满足了两行数据相同长度
    fprintf(fp, output_format"\n",
            arr->name,
            arr->age,
            arr->class,
            arr->height
    );
    //打开文件记得关闭
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

//优化4
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
    //代码到这儿，修改学生信息只是在数组中进行操作了
    //而还没有在文件中进行操作
    //我们想要的效果就是进行在当前学生信息的位置进行单条修改
    //restor_data_to_file(stu_arr, stu_cnt);那么在这儿这个函数调用方法就行不通了
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
        //优化3
        //如果进行直接覆盖，那么每个学生信息中的指针位置也会被覆盖
        //所以需要进行记录下来，覆盖后的学生信息的指针位置需要修改为之前学生信息的指针位置
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
