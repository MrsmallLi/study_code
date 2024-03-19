/*************************************************************************
	> File Name: 3.why_mush_have_function.c
	> Author: 
	> Mail: 
	> Created Time: Mon 18 Mar 2024 12:07:41 PM CST
 ************************************************************************/

#include <stdio.h>

//start范围开始，end为范围结束，d为公差
int function_sum(int start, int end, int d) {
    int n = (end - start) / d + 1;//求项数
    int num = start + (n - 1) * d;//求末项
    int sum = (start + num) * n / 2;//求和
    return sum;
}


int main() {
    //求等差数列的和
    //求1-100,公差为1的和
    //等差数列求和公式 sum = (首项 + 末项) * 项数 / 2;
    int sum1 = (1 + 100) * 100 / 2;
    //求1-100,公差为2的和
    int n2 = (100 - 1) / 2 + 1;//求项数
    int num2 = 1 + (n2 - 1) * 2;//求末项
    int sum2 = (1 + num2) * n2 / 2;//求和
    //求30-34534,公差为17的和
    int n3 = (34534 - 30) / 17 + 1;//求项数
    int num3 = 30 + (n3 - 1) * 17;//求末项
    int sum3 = (30 + num3) * n3 / 2;//求和
    printf("%d %d %d\n", sum1, sum2, sum3);
    //通过发现，我每次要去求等差数列的和都需要用3行代码去实现,特别繁琐，重复的代码也多;
    //现在就可以去用函数去封装起来,直接调用函数来实现这个过程
    //现在掉调用函数来求等差数列的和
    printf("%d ", function_sum(1, 100, 1));
    printf("%d ", function_sum(1, 100, 2));
    printf("%d\n", function_sum(30, 34534, 17));

    return 0;
}
