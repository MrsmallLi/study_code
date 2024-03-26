/*************************************************************************
	> File Name: 15.color.c
	> Author: 
	> Mail: 
	> Created Time: Mon 25 Mar 2024 10:01:13 PM CST
 ************************************************************************/

#include<stdio.h>

//对于这份代码，主要的是宏定义和枚举类型的运用
//大部分都是宏定义的内容，所以对于代码不懂，可以再回看关于宏定义的内容

#ifdef plana
//利用宏定义进行封装collor工具
#define COLLOR(msg, code) "\033[1;" #code "m" msg "\033[0m"
#define RED(msg) COLLOR(msg, 31)
#define GREEN(msg) COLLOR(msg, 32)
#define YELLOW(msg) COLLOR(msg, 33)
#define BLUE(msg) COLLOR(msg, 34)



int main() {
    //格式为\033[格式控制然后用;进行分隔跟上一个m,然后m后跟上需要打印的内容
    //最后\033[0m表示讲字体格式和颜色进行初始化
    //不然后面的字体都会变为你改变的颜色和格式
    printf("\033[1;32;43mhello world\n\033[0m");
    //使用宏定义进行输出带有演示的字体
    printf(RED("hello world\n"));
    printf(GREEN("hello world\n"));
    printf(YELLOW("hello world\n"));
    printf(BLUE("hello world\n"));

    return 0;
}


#else 

//利用枚举类型进行封装color工具
enum COLOR_CODE {
    RED =31,
    GREEN,
    YELLOW,
    BLUE
};

//利用宏定义封装输出信息
#define COLOR_SET "\033[1;%dm"
#define COLOR_END "\033[0m"


int main() {
    printf(COLOR_SET "hello color plan b\n" COLOR_END, RED);
    printf(COLOR_SET "hello color plan b\n" COLOR_END, GREEN);
    printf(COLOR_SET "hello color plan b\n" COLOR_END, YELLOW);
    printf(COLOR_SET "hello color plan b\n" COLOR_END, BLUE);
    //如果不懂下面的代码，可以再回看关于宏定义的内容
    printf(
        COLOR_SET "hello "
        COLOR_SET "color "
        COLOR_SET "plan "
        COLOR_SET "b"
        "\n"
        COLOR_END,
        RED,
        GREEN,
        YELLOW,
        BLUE
        );
    return 0;
}

#endif 

