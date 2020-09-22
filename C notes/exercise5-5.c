/*/本题要求实现一个统计整数中指定数字的个数的简单函数。

函数接口定义：
int CountDigit(int number, int digit);
其中number是不超过长整型的整数，digit为[0, 9]区间内的整数。函数CountDigit应返回number中digit出现的次数。
#include <stdio.h>

int CountDigit(int number, int digit);*/

int main()
{
    int number, digit;

    scanf("%d %d", &number, &digit);
    printf("Number of digit %d in %d: %d\n", digit, number, CountDigit(number, digit));

    return 0;
}

//你的函数嵌在这里
int CountDigit(int number, int digit) {
    int count = 0;
    if (number == 0) {
        if (digit == 0) { count = 1; }//要多考虑边界情况，0等特殊情况
    }
    else {
        if (number < 0) { number = -number; }
        int left;
        while (number) {
            left = number % 10;
            if (left == digit) { count++; }
            number = number / 10;
        }
    }
    return count;
}




