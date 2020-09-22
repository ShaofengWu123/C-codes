#include <stdio.h>

void pyramid(int n);

int main()
{
    int n;

    scanf("%d", &n);
    pyramid(n);

    return 0;
}
void pyramid(int n) {
    int i = 1;
    for (i = 1; i <= n; i++) {
        int j = 1;
        while (j <= n - i) { printf(" "); j++; }//回忆一下for循环第一次循环需不需要判断条件？ 需要
        for (int k = 1; k <= i; k++) { printf("%d ", i); }
        printf("\n");
    }
}