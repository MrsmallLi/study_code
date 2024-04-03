/*************************************************************************
	> File Name: 4.student_system.c
	> Author: 
	> Mail: 
	> Created Time: Tue 02 Apr 2024 03:57:22 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//定义一个字符串常量用来存储刚刚创建的需要进行读取的文件
const char *file_name = "student_data.txt";


typedef struct Student {
    char name[20];
    int age;
    int class;
    double height;
} Student;

#define MAX_N 10000
//创建学生数组, 用来存每个学生的信息
Student stu_arr[MAX_N + 5];
//记录有多少个学生
int stu_cnt;

//初始化学生数组,开始执行程序然后从文件中读取所有学生信息
//从文件中读取数据
int read_from_file(Student *arr) {
    int i = 0;
    FILE *fp = fopen(file_name, "r");
    //判断是否打开成功
    if (fp == NULL) return 0;
    //循环读取每一行学生数据, 先读入学生的姓名
    while (fscanf(fp, "%s", arr[i].name) != EOF) {
        //然后挨个读取学生的每个信息
        fscanf(fp, "%d%d%lf", 
               &arr[i].age, 
               &arr[i].class, 
               &arr[i].height
              );
        //对于学生ID对应的就是数组中的索引位置
        i++;
    }
    //记得关闭
    fclose(fp);
    return i;
}

//向文件中写入数据
void output_to_file(Student *arr, int n) {
    //因为是在文件末尾追加写入，所以需要用a模式打开文件
    FILE *fp = fopen(file_name, "a");
    for (int i = 0; i < n; i++) {
        fprintf(fp, "%s %d %d %.2lf\n",
                arr[i].name,
                arr[i].age,
                arr[i].class,
                arr[i].height);
    }
    //记得关闭使用的文件指针
    fclose(fp);
    return ;
}


void restor_data_to_file(Student *arr, int n) {
    //在修改学生信息时，如何把修改的数据交换原先的数据
    //那就通过先清空文件原先的内容
    //然后再通过数组向文件中写入
    //这里就通过w打开文件模式进行清空文件
    FILE *fp = fopen(file_name, "w");
    //用完关闭
    fclose(fp);
    //将新的数组内容进行输出到文件中
    output_to_file(arr, n);
    return ;
}


//利用枚举类型进行减小记忆负担
//这样在阅读代码时更容易理解
enum NO_TYPE {
    LIST = 1,
    ADD,
    MODIFY,
    DELETE,
    QUIT
};


//实现交互页面
int usage() {
    int no;
    //记录文件中有多少个学生
    //并且文件中所有学生的信息已经读入在创建的学生结构体数组中
    stu_cnt = read_from_file(stu_arr);
    do {
        printf("%d. list students\n", LIST);//列出所有学生信息
        printf("%d. add a new stdents\n", ADD);//添加一个学生信息
        printf("%d. list modify a students\n", MODIFY);//修改学生信息
        printf("%d. delete a students\n", DELETE);//删除一个学生信息
        printf("%d. quit system\n", QUIT);//退出系统
        printf("mysql>");
        scanf("%d", &no);
        if (no < 1 || no > 5) printf("intput error\n");
    } while(no < 1 || no > 5);//这里的do_while循环的作用为了让输入的值在系统可匹配范围内
    return no;
}

//实现列出学生信息
//实现功能1.list students
void list_students() {
    //用len记住打印表头的字符数
    int len = 0;
    len = printf("%4s|%10s|%4s|%6s|%7s|\n", 
           "id",
           "name",
           "age",
           "class",
           "height") ;
    //输出打印表头相同字符长度的分割线
    while (--len) printf("=");
    putchar(10);
    //输出学生学信息
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

//实现并封装添加一个学生信息功能
void add_to_student() {
    //输出对应功能要求的提示
    printf("add new item : (name, age, class, height)\n");
    printf("mysql > ");
    //将学生信息读入到学生数组中
    scanf("%s%d%d%lf",
          stu_arr[stu_cnt].name,
          &stu_arr[stu_cnt].age,
          &stu_arr[stu_cnt].class,
          &stu_arr[stu_cnt].height
    );
    //为什么传入参数是stu_arr + stu_cnt
    //为了保证刚刚添加的数据在文件末尾进行写入
    output_to_file(stu_arr + stu_cnt, 1);
    stu_cnt++;//添加一个学生，人数+1
    printf("add a new student success\n");
    return ;
}

//实现并封装修改一个学生信息
void modify_a_student() {
    //如果没有学生那就无法删除
    if (!stu_cnt) {
        printf("there haven't student\n");
        return ;
    }
    //1.列出所有学生信息
    list_students();
    int id;
    //2.输入id
    //判断输入id是否存在，如果不存在将一直输入
    do {
        printf("modify id : ");
        scanf("%d", &id);
    } while (id < 0 || id >= stu_cnt);
    //3.输出提示信息
    printf("modify item : (name, age, class, height)\n");
    //4.输入修改后学生信息
    printf("mysql >");
    scanf("%s%d%d%lf",
          stu_arr[id].name,
          &stu_arr[id].age,
          &stu_arr[id].class,
          &stu_arr[id].height
    );
    restor_data_to_file(stu_arr, stu_cnt);
    return ;
}

void delete_a_student() {
    //1.列出学生列表
    list_students();
    //2.输入需要删除学生id
    //输入id和修改学生信息逻辑相同
    int id; 
    do {
        printf("delete id : ");
        scanf("%d", &id);
    } while (id < 0 || id >= stu_cnt);
    //3.确认是否删除
    char c;
    do {
        printf("confirm (y / n) :");
        scanf("%c", &c);
    } while (c != 'y' && c != 'n');
    if (c == 'n') return ;//不确认删除，那就结束该功能
    //通过删除位置后面的信息从前往后依次覆盖
    //比如现在id = 2, 那么id = 3的信息覆盖id = 2的信息，以此类推
    //最后位置后面没有信息就不用覆盖了
    for (int i = id; i < stu_cnt - 1; i++) {
        stu_arr[i] = stu_arr[i + 1];
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
