/*本题要求实现一个函数，对一个整数进行按位顺序输出。

函数接口定义：
void printdigits(int n);
函数printdigits应将n的每一位数字从高位到低位顺序打印出来，每位数字占一行。

裁判测试程序样例：*/
#include <stdio.h>

void printdigits(int n);

int main()
{
    int n;

    scanf("%d", &n);
    printdigits(n);

    return 0;
}
/* 你的代码将被嵌在这里 */
void printdigits(int n) {
    static counter = 0;//static变量实际上是特殊的全局变量。static指的是本地作用域，但是生存期是全局的。static变量只会在第一次调用函数的时候进行
                                 //初始化，之后再调用时不会初始化，保留第一次调用时其值。   
    int digit = n % 10;
    if (n == 0) {
        if (counter == 0) { printf("0\n"); }
        else { ; }
    }
    else {
        counter++;
        printdigits(n / 10);
        printf("%d\n", digit);
    }

}