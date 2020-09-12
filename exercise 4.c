#include <stdio.h>
int main() {
    int factor = -1;
    double n, S = 0;
    scanf("%lf", &n);
    if (n <= 0) { ; }
    else {
        for (double i = 1; i <= n; i++) {
            factor *= (-1);
            S += factor * (i) / (2*i - 1);//一定要记住所有的乘法都要使用*
        }
    }
    printf("%.3f", S);

    return 0;
}