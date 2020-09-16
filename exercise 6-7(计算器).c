#include <stdio.h>
#include <stdlib.h>

typedef struct unit {
    char s;
    struct unit* next;
}UNIT;//����Ԫ�����ڰ����ַ�Ϊ��λ�ķ�ʽ��Ŷ�������ʽ��

int is_legal(char s) {
    int flag = 0;
    if ((s == '+') || (s == '-') || (s == '*') || (s == '/') || (s == '=')||(s >= '0' && s <= '9')) { flag = 1; }
    return flag;
}//�ж��ǲ��ǺϷ��ķ��ţ��������ֺͼӼ��˳����ںţ�

int is_symbol(char s) {
    int flag = 0;
    if (s == '+' || s == '-' || s == '*' || s == '/'|| s== '=') { flag = 1; }
    return flag;
}//�ж��ǲ��ǲ������ţ������Ӽ��˳����ںţ�

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
    } while (str != '=');//��ʼ������

    //for (UNIT* a = head; a; a = a->next) {
    //   printf("%c", a->s);
    
   // }
    //printf("\n");//������������Ƿ���ȷ��ʼ����������������ı��������ڵ��Դ��롣

    /*����˼·����p1��p2����ָ���ƶ�����ȡ����
    1.p1 p2λ��head
    2.p2�ƶ���ֱ������������
    3.�ֲ�����p3��p1(���p1���ǲ�����)����p1->next(���p1�ǲ�����)��ʼ�ƶ������ƶ������а�p1��p2֮������ִ�Ž�num_temp
    4.����p1->s��ʲô������num_temp�Ӽ��˳���result�ϡ�ע�����Ҫ���������жϣ��д���exitflag����1
    5.p1 = p2�����ж�p1->s�ǲ��ǵ���=���������ô�˳���������ǴӲ���2��ʼ�ظ�
    6.ѭ����ɺ����exitflag������1(��p1->next == NULL)��˵����ʽ��ͷ��ѭ��û���쳣�˳������������ɡ�
    7.��Ŀû��Ҫ��ʶ��1=1�����ķǷ����룬�����Ҫʶ��ֻ��Ҫif(!exitlfag&&p1->next)���������˵��ѭ�������˳���p1��һ����Ԫ����NULL������ʽ=���滹��
    ���֣������ʽ�ǷǷ��ġ�
    */
    UNIT* p1 = head,*p2 = head,*p3;
    int exitflag = 0;
    for (; (p1->s) != '='; p2 = p2->next) {//p2ָ���������ֻҪ����p2��ָsΪ���������ͼ��㵽��һ��������(p1��)֮�����ֵ�ֵ������temp_num
        int temp_num = 0;

        if (is_legal(p2->s)) {//�ж�p2�������Ƿ�Ϸ������Ϸ���ʾ�����˳�
            if (is_symbol(p2->s)) {//�ж�p2�������ǲ��ǲ����������ǲ���������ôʲôҲ�����������������ǲ�����������temp_num����ʶ��p1����ʲô
                if (is_symbol(p1->s)){ p3 = p1->next; }
                else { p3 = p1; }
                while (p3 != p2) {//����temp_num
                    temp_num = temp_num * 10 + (p3->s) - 48;
                    p3 = p3->next;
                }

                if (is_symbol(p1->s)) {//ʶ��p1���ǲ��ǲ�����������˵����ʱtemp_numǰû�з���
                    if ((p1->s) == '+') { result += temp_num; }
                    else if ((p1->s) == '-') { result -= temp_num; }
                    else if ((p1->s) == '*') { result *= temp_num; }
                    else if ((p1->s) == '/') {
                        if (temp_num == 0) { exitflag = 1; }
                        else { result /= temp_num; }
                    }
                }
                else { result += temp_num; }

                p1 = p2;//��p1�Ƶ�p2������ʱp2һ���ǲ�������

            }
            else { ; }
        }

        else { exitflag = 1; }


        if (exitflag) {
                printf("ERROR"); break;
            }
        }

    //if (!exitflag && p2->next){ printf("ERROR"); }//�ж�1=1�����ķǷ�����
    if (!exitflag) {
        printf("%d", result);
    }

    return 0;
}