#include <stdio.h>

int main()
{
    int price = 0 ;
    int price2 = 0 ;
    const int PRICE3 = 100;
    
    printf("请输入商品价格:\n");
    scanf("%d", &price);/*do not add /n in scanf() or you may get mistakes*/
    /*fflush(stdin);*/
    printf("请输入付给的金额:");
    scanf("%d", &price2) ;

    printf("change = %d\n", price2 - price);

    int main = 1;
    printf("%d", main);

    int __a = 2;
    printf("%d", __a);

    int cal = 10 / 3.0 * 3;
    printf("%d\n", cal);/*different from python: print(cal)*/

    int a = 0;
    printf("%d", a =100);


    return 0;
}