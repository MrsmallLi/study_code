/*************************************************************************
	> File Name: 8.string.c
	> Author: 
	> Mail: 
	> Created Time: Thu 21 Mar 2024 06:40:16 PM CST
 ************************************************************************/

#include<stdio.h>
#include <string.h>


int main() {
    char str1[10] = "abc";//只能在定义字符时使用
    printf("str1 = %s\n", str1);
    //str1 = "def"这样是不行的
    strcpy(str1, "def");
    printf("str1 = %s\n", str1);
    char str2[] = "hello\0 world";
    //用strlen判断str2的长度
    //通过执行结果发现，strlen是统计到\0字符为止
    //打印字符串也打印到\0字符结束
    printf("strlen(str2) = %lu\n", strlen(str2));
    printf("str2 = %s\n", str2) ;
    //通过发现\0也占用位置,str2的长度为13位
    printf("sizeof(str2) = %lu\n", sizeof(str2));
    str2[5] = 'a';
    printf("str2 = %s\n", str2) ;//通过修改后发现，没有\0，可以打印完str2
    char str3[] = "abcdef", str4[] = "abc";
    //执行结果为100
    //因为strcmp通过比较，str3和str4发现前3位相同
    //第4位分别为'd'和'\0', 不相同返回的就是'd' - '\0'的值
    //'d'对应的ASCLL值是100，\0对应的是0,那么结果就是100
    printf("strcmp(str3, str4) = %d\n", strcmp(str3, str4));
    str3[3] = '\0';// abc\0ef
    //通过这个比较发现，strcmp比较也是在\0结束
    printf("strcmp(str3, str4) = %d\n", strcmp(str3, str4));

    int arr[10];
    for (int i = 0; i < 10; i++) {
        arr[i] = i * i;
    }
    for (int i = 0; i < 10 ; i++) {
        i && printf(" ");
        printf("%d", arr[i]);
    }
    printf("\n");
    //第一个参数放置地址
    //第二个参数放置初始化的值
    //第三个参数放置数组的字节大小
    memset(arr, 0, sizeof(int) * 10);
    for (int i = 0; i < 10 ; i++) {
        i && printf(" ");
        printf("%d", arr[i]);
    }
    printf("\n");
    //全赋值为-1
    memset(arr, -1, sizeof(int) * 10);
    for (int i = 0; i < 10 ; i++) {
        i && printf(" ");
        printf("%d", arr[i]);
    }
    printf("\n");
    //全赋值为2
    memset(arr, 2, sizeof(int) * 10);
    for (int i = 0; i < 10 ; i++) {
        i && printf(" ");
        printf("%d", arr[i]);
    }
    printf("\n");
    //通过执行发现，结果和预想的不一样，因为memset是通过对每个字节赋值
    //对一个元素进行分析用二进制表示，int 类型有4字节,一个字节8位
    //00000010 00000010 00000010 00000010
    //拿结果就是2 + 2 ^ 9 + 2 ^ 17 + 2 ^ 25 = 33686018
    //和输出的结果是一样的
    return 0;
}


