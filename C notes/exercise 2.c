#include <stdio.h>

double fact(int x);

int main() {
    int n, m,test;
    double result;
    scanf("%d %d", &m, &n);
    if ((m > n) || (m <= 0) || (n <= 0)) { ; }
    else {
      
        result = fact(n) / (fact(m) * fact(n - m));
        test = (int)result;
        printf("result = %d", (int)result);//这里要进行强制类型转换，如果不进行转换，%d对编码形式的double保留4字节会导致结果错误
    }

    return 0;
}

double fact(int x) {
    double result = 1;
    for (int i = 1; i <= x; i++) {
        result *= i;
    }
    return result;
}