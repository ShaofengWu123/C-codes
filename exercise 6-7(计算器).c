#include <stdio.h>
#include <stdlib.h>

typedef struct unit {
    char s;
    struct unit* next;
}UNIT;//链表单元，用于按照字符为单位的方式存放读到的算式。

int is_legal(char s) {
    int flag = 0;
    if ((s == '+') || (s == '-') || (s == '*') || (s == '/') || (s == '=')||(s >= '0' && s <= '9')) { flag = 1; }
    return flag;
}//判断是不是合法的符号（包括数字和加减乘除等于号）

int is_symbol(char s) {
    int flag = 0;
    if (s == '+' || s == '-' || s == '*' || s == '/'|| s== '=') { flag = 1; }
    return flag;
}//判断是不是操作符号（包括加减乘除等于号）

int main() {
    char str;
    int result = 0;
    UNIT* head = NULL;
    do {
        scanf("%c", &str);
        //create new node
        UNIT* p = (UNIT*)malloc(sizeof(UNIT));
        p->s = str;
        p->next = NULL;
        //find last node
        UNIT* last = head;
        if (last) {
            while (last->next) { last = last->next; }
            //add p to linked-list
            last->next = p;
        }
        else {
            head = p;
        }
    } while (str != '=');//初始化链表

    //for (UNIT* a = head; a; a = a->next) {
    //   printf("%c", a->s);
    
   // }
    //printf("\n");//这里用来检查是否正确初始化链表，包含对链表的遍历，用于调试代码。

    /*基本思路是用p1、p2两个指针移动来读取数字
    1.p1 p2位于head
    2.p2移动，直到遇到操作符
    3.局部变量p3从p1(如果p1不是操作符)或者p1->next(如果p1是操作符)开始移动，在移动过程中把p1和p2之间的数字存放进num_temp
    4.根据p1->s是什么来决定num_temp加减乘除到result上。注意除法要进行特殊判断，有错误exitflag调成1
    5.p1 = p2，并判断p1->s是不是等于=，如果是那么退出，如果不是从步骤2开始重复
    6.循环完成后，如果exitflag不等于1(且p1->next == NULL)，说明算式到头且循环没有异常退出，输出结果即可。
    7.题目没有要求识别1=1这样的非法输入，如果需要识别只需要if(!exitlfag&&p1->next)，如果成立说明循环正常退出且p1下一个单元不是NULL，即算式=后面还有
    数字，因此算式是非法的。
    */
    UNIT* p1 = head,*p2 = head,*p3;
    int exitflag = 0;
    for (; (p1->s) != '='; p2 = p2->next) {//p2指针遍历链表，只要遇到p2所指s为操作符，就计算到上一个操作符(p1处)之间数字的值，存入temp_num
        int temp_num = 0;

        if (is_legal(p2->s)) {//判断p2处符号是否合法，不合法提示程序退出
            if (is_symbol(p2->s)) {//判断p2处符号是不是操作符，不是操作符，那么什么也不做，继续遍历。是操作符，计算temp_num，并识别p1处是什么
                if (is_symbol(p1->s)){ p3 = p1->next; }
                else { p3 = p1; }
                while (p3 != p2) {//计算temp_num
                    temp_num = temp_num * 10 + (p3->s) - 48;
                    p3 = p3->next;
                }

                if (is_symbol(p1->s)) {//识别p1处是不是操作符，不是说明此时temp_num前没有符号
                    if ((p1->s) == '+') { result += temp_num; }
                    else if ((p1->s) == '-') { result -= temp_num; }
                    else if ((p1->s) == '*') { result *= temp_num; }
                    else if ((p1->s) == '/') {
                        if (temp_num == 0) { exitflag = 1; }
                        else { result /= temp_num; }
                    }
                }
                else { result += temp_num; }

                p1 = p2;//把p1移到p2处，此时p2一定是操作符。

            }
            else { ; }
        }

        else { exitflag = 1; }


        if (exitflag) {
                printf("ERROR"); break;
            }
        }

    //if (!exitflag && p2->next){ printf("ERROR"); }//判断1=1这样的非法输入
    if (!exitflag) {
        printf("%d", result);
    }

    return 0;
}