#include <stdio.h>
#include <stdlib.h>

double fnume(int n);
double fdeno(int n);
int num(int n, double* nume, double* deno);

int main() {
    int N;
    double* nume, * deno;
    nume = (double*)malloc(sizeof(double));
    deno = (double*)malloc(sizeof(double));
    double sum = 0;
    scanf("%d", &N);
    
    for (int i = 1; i <= N; i++) {
        sum += fnume(i) / fdeno(i);
    }
    printf("线性递归结果：%.2f\n", sum);
       
    sum = 0;
    for (int i = 1; i <= N; i++) {
        *nume = 2;
        *deno = 1;
        num(i, nume, deno);
        sum += (*nume) / (*deno);
    }
    printf("尾递归结果：%.2f\n", sum);
    return 0;
}

double fnume(int n) {
    double numerator;
    if (n == 1) { numerator = 2; }
    else { numerator = fnume(n - 1) + fdeno(n - 1); }
    return numerator;
}
double fdeno(int n) {
    double denominator;
    if (n == 1) { denominator = 1; }
    else { denominator = fnume(n - 1); }
    return denominator;
}

int num(int n, double* nume, double* deno) {
    double temp = 0;
    if (n == 1) { return 0; }
    else {
        temp = *nume;
        *nume = *nume + *deno;
        *deno = temp;
        return num(n - 1, nume, deno);

    }
}

