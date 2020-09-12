/*本题要求实现一个函数，用下列公式求cos(x)的近似值，精确到最后一项的绝对值小于e：

cos(x) = x0/ 0!−x2/ 2!+ x​4/ 4!−x6/ 6!+ ⋯

函数接口定义：
double funcos(double e, double x);
其中用户传入的参数为误差上限e和自变量x；函数funcos应返回用给定公式计算出来、并且满足误差要求的cos(x)的近似值。输入输出均在双精度范围内。*/

#include <stdio.h>
#include <math.h>

double funcos(double e, double x);

int main()
{
    double e, x;

    scanf("%lf %lf", &e, &x);
    printf("cos(%.2f) = %.6f\n", x, funcos(e, x));

    return 0;
}

//代码嵌在这里
double funcos(double e, double x) {
    int count = 0;
    int k = 1;
    double fact = 1;/*经常忘记的点：数据溢出！首先不要惯性思维认为double就是用来表示小数的，double能表达的数据范围能从很小的数到
                              很大的数。而int(2^-n~2^n-1，其他同理，这里的int是带符号的)，long，long long能表达的范围远小于float和double。尤其
                              是在做阶乘这种容易产生很大的数的时候要用double防止数据溢出！*/
    double last = pow(x, 0);
    double result = last;
    if (last < e) { ; }
    else {
        while (last > e) {
            count = count + 2;
            for (int i = 1; i <= count; i++) {
                fact *= i;
            }
            last = pow(x, count) / fact;
            k = -k;
            result += k * last;
            fact = 1;
        }
    }
    return result;
}