#include <stdio.h>
int main() {
    int lower, upper, F;
    double C;
    scanf("%d %d", &lower, &upper);
    if ((lower <= upper) && (upper <= 100) && (lower > 0)) {
        printf("fahr celsius\n");
        for (F = lower; F <= upper; F += 2) {
            C = 5 * (F - 32) / 9.0;//思考：如果用9会怎么样？ 会导致结果错误，因为表达式右边是整型，不是想要的结果。要注意的是强制类型转换是没有用的，
                                               //因为这样仅仅是把4字节int补0成为8字节double
            printf("%d%6.1f\n", F, C);
        }
    }
    else {
        printf("Invalid.");
    }

    return 0;
}