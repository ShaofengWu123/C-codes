/*/����Ҫ��ʵ��һ��ͳ��������ָ�����ֵĸ����ļ򵥺�����

�����ӿڶ��壺
int CountDigit(int number, int digit);
����number�ǲ����������͵�������digitΪ[0, 9]�����ڵ�����������CountDigitӦ����number��digit���ֵĴ�����
#include <stdio.h>

int CountDigit(int number, int digit);*/

int main()
{
    int number, digit;

    scanf("%d %d", &number, &digit);
    printf("Number of digit %d in %d: %d\n", digit, number, CountDigit(number, digit));

    return 0;
}

//��ĺ���Ƕ������
int CountDigit(int number, int digit) {
    int count = 0;
    if (number == 0) {
        if (digit == 0) { count = 1; }//Ҫ�࿼�Ǳ߽������0���������
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




