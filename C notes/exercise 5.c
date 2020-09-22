//����Ҫ���д���򣬼���ѧ���ǵ�ƽ���ɼ�����ͳ�Ƽ��񣨳ɼ�������60�֣�����������Ŀ��֤����������������ͷ�Χ�ڡ�

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
        //int a[n];//C99 only������Visual studio2019���С�Ҫ��malloc��̬����ռ�
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