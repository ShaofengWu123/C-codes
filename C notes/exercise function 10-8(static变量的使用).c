/*����Ҫ��ʵ��һ����������һ���������а�λ˳�������

�����ӿڶ��壺
void printdigits(int n);
����printdigitsӦ��n��ÿһλ���ִӸ�λ����λ˳���ӡ������ÿλ����ռһ�С�

���в��Գ���������*/
#include <stdio.h>

void printdigits(int n);

int main()
{
    int n;

    scanf("%d", &n);
    printdigits(n);

    return 0;
}
/* ��Ĵ��뽫��Ƕ������ */
void printdigits(int n) {
    static counter = 0;//static����ʵ�����������ȫ�ֱ�����staticָ���Ǳ��������򣬵�����������ȫ�ֵġ�static����ֻ���ڵ�һ�ε��ú�����ʱ�����
                                 //��ʼ����֮���ٵ���ʱ�����ʼ����������һ�ε���ʱ��ֵ��   
    int digit = n % 10;
    if (n == 0) {
        if (counter == 0) { printf("0\n"); }
        else { ; }
    }
    else {
        counter++;
        printdigits(n / 10);
        printf("%d\n", digit);
    }

}