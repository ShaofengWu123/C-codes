/*给定四种水果，分别是苹果（apple）、梨（pear）、桔子（orange）、葡萄（grape），单价分别对应为3.00元 / 公斤、2.50元 / 公斤、4.10元 / 公斤、10.20元 / 公斤。

首先在屏幕上显示以下菜单：

[1] apple
[2] pear
[3] orange
[4] grape
[0] exit
用户可以输入编号1~4查询对应水果的单价。当连续查询次数超过5次时，程序应自动退出查询；不到5次而用户输入0即退出；输入其他编号，显示价格为0。

输入格式 :
输入在一行中给出用户连续输入的若干个编号。

输出格式 :
首先在屏幕上显示菜单。然后对应用户的每个输入，在一行中按格式“price = 价格”输出查询结果，其中价格保留两位小数。当用户连续查询次数超过5次、或主动输入0时，程序结束。*/

#include <stdio.h>

int main() {
    int choice;
    int counter = 1;
    double a[] = { 3.00,2.50,4.10,10.20 };
    printf("[1] apple\n");
    printf("[2] pear\n");
    printf("[3] orange\n");
    printf("[4] grape\n");
    printf("[0] exit\n");
    while ((choice != 0) && (counter <= 5)) {
        scanf("%d", &choice);//注意逻辑关系，是先读取输入一次还是先进入循环？考虑好了以后再根据选择（都可以试一下）多考虑一下极端情况，
                                             //例如直接退出，上来就是非法字符等。
        if (choice == 0) { ; }
        else if ((choice < 0) || (choice > 4)) { printf("price = 0.00\n"); }
        else { printf("price = %.2f\n", a[choice - 1]); }
        counter++;
    }

    return 0;
}