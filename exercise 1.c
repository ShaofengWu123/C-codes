#include <stdio.h>
int main() {
    int lower, upper, F;
    double C;
    scanf("%d %d", &lower, &upper);
    if ((lower <= upper) && (upper <= 100) && (lower > 0)) {
        printf("fahr celsius\n");
        for (F = lower; F <= upper; F += 2) {
            C = 5 * (F - 32) / 9.0;//˼���������9����ô���� �ᵼ�½��������Ϊ���ʽ�ұ������ͣ�������Ҫ�Ľ����Ҫע�����ǿ������ת����û���õģ�
                                               //��Ϊ���������ǰ�4�ֽ�int��0��Ϊ8�ֽ�double
            printf("%d%6.1f\n", F, C);
        }
    }
    else {
        printf("Invalid.");
    }

    return 0;
}