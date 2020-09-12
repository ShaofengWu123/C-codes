//本题要求编写程序，计算学生们的平均成绩，并统计及格（成绩不低于60分）的人数。题目保证输入与输出均在整型范围内。

#include <stdio.h>
#include <stdlib.h>

double avg(int* a, int n);
int count(int* a, int n);

int main() {
    int n;
    int* a;
    scanf("%d", &n);
    if (n < 0) { ; }
    else {
        //int a[n];//C99 only。对于Visual studio2019不行。要用malloc动态分配空间
        a = malloc(n * sizeof(int));
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        printf("average = %.1f\n", avg(a, n));
        printf("count = %d", count(a, n));
        free(a);
    }


    return 0;
}

double avg(int* a, int n) {
    double result = 0;
    double sum = 0;
    if (n == 0) { result = 0; }
    else {
        for (int i = 0; i < n; i++) {
            sum += a[i];
        }
        result = sum / n;
    }
    return result;
}

int count(int* a, int n) {
    int counter = 0;
    if (n == 0) { ; }
    else {
        for (int i = 0; i < n; i++) {
            if (a[i] >= 60) { counter++; }
        }
    }
    return counter;
}