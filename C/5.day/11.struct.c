/*************************************************************************
	> File Name: 11.struct.c
	> Author: 
	> Mail: 
	> Created Time: Mon 25 Mar 2024 03:34:52 PM CST
 ************************************************************************/

#include <stdio.h>
#include <string.h>

//定义结构体需要用struct关键字
typedef struct person {
    char name[20];
    int age;
    char gender;
    float height;
} person;//在前面加上typedef,就可以在最后定义别名,在下方定义结构体变量时，就可以用别名来定义

void output(struct person *p) {
    printf("use pointer p (%s, %d, %c, %f)\n", 
           p->name, 
           p->age, 
           p->gender, 
           p->height);
    return ;
}
//这个函数的作用是将结构体变量所占空间，转换为buff字符串来可见
//第一个参数用来转换的buff字符串
//第二个参数是结构体起始变量地址
//第三个参数是那个结构体变量的起始地址
//第四个参数是这个结构体变量的结束地址
//第五个参数替换的字符
void set_buff(char *buff, void *head, void *begin, void *end, char ch) {
    //循环判断条件, 当起始位置等于结束位置时结束
    while (begin != end) {
        //这里变量的起始位置减去结构体起始的位置可以得到索引下标
        buff[begin - head] = ch;
        begin += 1;
    }
    return ;
}

void output_person() {
    //开person结构体个大小的字符串
    int n = sizeof(struct person), len = 0;
    char buf[n];
    //初始化字符串内容为.
    for (int i = 0; i < n; i++) buf[i] = '.';
    //打印对应位置索引
    for (int i = 0; i < n; i++) {
        len += printf("%3d", i);
    }
    printf("\n");
    //间隔符
    for (int i = 0; i < len; i++) printf("-");
    printf("\n");
    //定义一个结构体变量
    struct person hug;
    //name有20个字节大小所以从起始位置到结尾有20,并用'n'表示所占位置
    set_buff(buf, hug.name, hug.name, 20 + (void *)hug.name, 'n');
    set_buff(buf, hug.name, &hug.age, 4 + (void *)&hug.age, 'a');
    set_buff(buf, hug.name, &hug.gender, 1 + (void *)&hug.gender, 'g');
    set_buff(buf, hug.name, &hug.height, 4 + (void *)&hug.height, 'h');
    for (int i = 0; i < n; i++) {
        printf("%3c", buf[i]);
    }
    printf("\n");
    return ;
}

int main() {
    //定义结构体变量, 必须在前面加上struct关键字
    //并初始化结构体中的变量
    struct person hug = {"zhang san", 18, 'm', 2.1};
    //利用结构体别名来定义结构体变量
    person su = {"Su", 25, 'm', 1.6};
    //hug.name这种以.的方式进行访问结构体中的变量叫做直接访问
    printf("(%s, %d, %c, %f)\n", hug.name, hug.age, hug.gender, hug.height);
    //通过结构体指针访问结构体变量的方式叫做间接访问
    output(&hug);
    output(&su);
    //查看person结构体占用的字节数
    printf("sizeof(struct person) =%lu\n", sizeof(struct person));
    //执行一个方法，标记每个结构体变量的在这32个字节中的位置
     output_person();
    return 0;
}
