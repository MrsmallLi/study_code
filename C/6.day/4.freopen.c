/*************************************************************************
	> File Name: 4.freopen.c
	> Author: 
	> Mail: 
	> Created Time: Tue 26 Mar 2024 03:35:52 PM CST
 ************************************************************************/

#include<stdio.h>


int main() {
    //参数一需要输出的新文件名
    //参数二以打开文件的什么模式
    //参数三需要重新定向的文件指针
    freopen("output.txt", "w", stdout); //r代表读文件，w代表写文件
    freopen("input.txt", "r", stdin); //r代表读文件，w代表写文件
    printf("hello freopen yes\n");
    char s[1000] = {0};
    //当读入到文件结尾时，循环结束
    while (scanf("%[^\n]", s) != EOF) {
        //getchar()从标准输入流中读取一个字符
        //这里为什么要使用到getchar()
        //因为在使用scanf时
        //里面的字符匹配集是非\n就读取
        //那么在最后遇到\n的时候结束读取
        //最后输入流中会存留一个\n
        //然后scanf一直不读取
        //最后造成了while死循环
        //所以在这需要使用一个getchar()来对\n进行处理掉
        getchar();

        printf("%s | hello world\n", s);
    }
    return 0;
}
