//本题要求实现一个函数，将正整数n转换为二进制后输出。
//
//函数接口定义：
//void dectobin(int n);
//函数dectobin应在一行中打印出二进制的n。建议用递归实现。
//
//裁判测试程序样例：
#include <stdio.h>

void dectobin(int n);

int main()
{
    int n;

    scanf("%d", &n);
    dectobin(n);

    return 0;
}

/* 你的代码将被嵌在这里 */
void dectobin(int n) {
    if (n == 0) { printf("0"); }
    else if (n == 1) { printf("1"); }
    else {
        dectobin(n/2);
        printf("%d",n%2);
    }
}
//无论多少进制，获得每一位数字的方法都是一样的（取余），但是要注意第一次取余获得的是个位的数字，要放在最后输出，所以要先递归调用，再printf，
//这样的话就可以不用static变量记录累加的结果了
