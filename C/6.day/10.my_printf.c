/*************************************************************************
	> File Name: 10.my_printf.c
	> Author: 
	> Mail: 
	> Created Time: Tue 26 Mar 2024 08:49:48 PM CST
 ************************************************************************/

#include <stdio.h>
#include <inttypes.h>
#include <stdarg.h>
#include <math.h>
#include <limits.h>

//这个宏定义是测试printf和my_printf区别
#define TEST(format, args...) {\
    int n1, n2;\
    n1 = printf(format, ##args);\
    n2 = my_printf(format, ##args);\
    printf("n1 = %d, n2 = %d\n", n1, n2);\
}

char get_16_code(int n) {
    //当这一位小于10，在16进制中还是用数字表示
    if (n < 10) return n + '0';
    //当这一位大于10，在16进制中需要用字母表示
    //a 10, b 11, c 12, d 13, e 14, f 15
    return n - 10 + 'a';
}

int my_printf(const char *format, ...) {
    #define PUTC(c) putchar(c), cnt += 1
    va_list args;//args表示变参列表
    va_start(args, format);//变参列表从format参数后面开始
    //cnt代表输出了多少个字符
    int cnt = 0;
    for (int i = 0; format[i]; i++) {//这里中间条件用到了format[i],当format[i] = '\0'时表示循环结束
        //putchar() 是向屏幕上打印一个字符
        switch (format[i]) {
            //如果当前字符是%，那么就需要对下个字符进行特殊处理
            case '%': {
                switch (format[i + 1]) {
                    //当有两个%时，那就需要打印一个%
                    case '%': {
                        PUTC(format[i + 1]);
                        //对于下个位置已经处理所以需要i+1
                        i++;
                    } break;
                    //%后接s那么就是字符串的格式占位符
                    //然后这里就需要用到变参列表的解析
                    case 's': {
                        //获取变参列表的参数,并且该参数的类型为char *类型
                        const char *s = va_arg(args, const char *);
                        //获取到字符串后,进行打印字符串
                        for (int j = 0; s[j]; j++) PUTC(s[j]);
                        //s这个字符被处理掉了，不需要打印了，位置需要往后移
                        i++;
                    } break;
                    //%后接d那么就是整形的格式占位符
                    case 'd': {
                        //获取变参列表的参数,并且该参数的类型为char *类型
                        const int num = va_arg(args, const int);
                        //这里就需要率到如何进行把每一位数字进行输出
                        //因为putchar只能打印单个字符
                        //那么就用数组将数字进行存储起来
                        int8_t arr[20];//int8_t表示只有8位带符号的整形数字,只占8bit位,头文件<inttype.h>
                        //现在进行对num数字每位进行存储在数组中
                        int n = num, ind = 0;
                        if (n < 0) PUTC('-');//n为负数时需要输出负号
                        do {
                            //从个位进行每位存储在数组中
                            arr[ind++] = n % 10;
                            n /= 10;
                        } while(n);//因为n = 0不会进入循环，那么就无法进行输出,所以使用do while循环先执行一次
                        //因为个位在第一位，所以需要倒过来输出
                        for (; ind > 0; ind--) {
                            //ind - 1是因为，当前ind位置是空的，最高位在ind - 1上
                            //当num为负数时需要，将他变为正数进行输出
                            if (num < 0) PUTC(-arr[ind - 1] + '0');
                            else PUTC(arr[ind - 1] + '0');
                        }
                        i++;//与之前的操作同理
                    } break;
                    case 'x': {
                        //因为十六进制输出是不带符号的,所以需要用到无符号整形
                        unsigned int num = va_arg(args, unsigned int);
                        int8_t arr[20], ind = 0;
                        do {
                            //因为需要转换为16进制,所以需要对16进行取余
                            arr[ind++] = num % 16;
                            num /= 16;
                        } while(num);
                        for (; ind > 0; ind--) {
                            //实现一个方法将10进制转为16进制
                            PUTC(get_16_code(arr[ind - 1]));
                        }
                        i++;//同理
                    } break;
                }
            } break;
            default : PUTC(format[i]); break;
        }
    }
    return cnt;
}

int main() {
    //测试printf和my_printf输出hello world
    TEST("hello world\n");
    //对于printf%%输出就是一个%
    //由于printf对%是特殊处理，那么对于my_printf也就需要特殊处理
    TEST("100%%\n");
    TEST("%s\n", "hello world 100 %%");
    int a = 123;
    TEST("a = %d\n", a);
    a = 0;
    TEST("a = %d\n", a);
    a = INT_MAX;
    TEST("a = %d\n", a);
    a = INT_MIN;
    TEST("a = %d\n", a);
    TEST("123 = %x\n", 123);
    TEST("-1 = %x\n", -1);
    TEST("INT_MAX = %x\n", INT_MAX);
    TEST("INT_MIN = %x\n", INT_MIN);
    return 0;
}
