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
        printf("result = %d", (int)result);//����Ҫ����ǿ������ת�������������ת����%d�Ա�����ʽ��double����4�ֽڻᵼ�½������
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