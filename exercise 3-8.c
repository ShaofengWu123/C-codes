/*��������ˮ�����ֱ���ƻ����apple�����棨pear�������ӣ�orange�������ѣ�grape�������۷ֱ��ӦΪ3.00Ԫ / ���2.50Ԫ / ���4.10Ԫ / ���10.20Ԫ / ���

��������Ļ����ʾ���²˵���

[1] apple
[2] pear
[3] orange
[4] grape
[0] exit
�û�����������1~4��ѯ��Ӧˮ���ĵ��ۡ���������ѯ��������5��ʱ������Ӧ�Զ��˳���ѯ������5�ζ��û�����0���˳�������������ţ���ʾ�۸�Ϊ0��

�����ʽ :
������һ���и����û�������������ɸ���š�

�����ʽ :
��������Ļ����ʾ�˵���Ȼ���Ӧ�û���ÿ�����룬��һ���а���ʽ��price = �۸������ѯ��������м۸�����λС�������û�������ѯ��������5�Ρ�����������0ʱ�����������*/

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
        scanf("%d", &choice);//ע���߼���ϵ�����ȶ�ȡ����һ�λ����Ƚ���ѭ�������Ǻ����Ժ��ٸ���ѡ�񣨶�������һ�£��࿼��һ�¼��������
                                             //����ֱ���˳����������ǷǷ��ַ��ȡ�
        if (choice == 0) { ; }
        else if ((choice < 0) || (choice > 4)) { printf("price = 0.00\n"); }
        else { printf("price = %.2f\n", a[choice - 1]); }
        counter++;
    }

    return 0;
}