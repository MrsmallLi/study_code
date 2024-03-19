/*************************************************************************
	> File Name: 7.goto_switch.c
	> Author: 
	> Mail: 
	> Created Time: Thu 14 Mar 2024 02:41:40 PM CST
 ************************************************************************/

#include <stdio.h>


int main() {
    //输入数字1-3，然后输出对应的英文
    int n;
    scanf("%d", &n);
    //和if—else 语句同样的实现方法
    n == 1 && ({goto lab_1; 1; });
    n == 2 && ({goto lab_2; 1; });
    n == 3 && ({goto lab_3; 1; });
    goto error;
lab_1:
    printf("One\n");
    //这里为什么要goto end
    //如果没有goto end,就会往下继续执行 lab_2
    //所以需要跳转到结束
    goto end;
lab_2:
    printf("Two\n");
    goto end;
lab_3:
    printf("Tree\n");
    goto end;
error:
    printf("input error\n");
end:
    return 0;
}
