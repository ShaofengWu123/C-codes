//����Ҫ��ʵ��һ����������������nת��Ϊ�����ƺ������
//
//�����ӿڶ��壺
//void dectobin(int n);
//����dectobinӦ��һ���д�ӡ�������Ƶ�n�������õݹ�ʵ�֡�
//
//���в��Գ���������
#include <stdio.h>

void dectobin(int n);

int main()
{
    int n;

    scanf("%d", &n);
    dectobin(n);

    return 0;
}

/* ��Ĵ��뽫��Ƕ������ */
void dectobin(int n) {
    if (n == 0) { printf("0"); }
    else if (n == 1) { printf("1"); }
    else {
        dectobin(n/2);
        printf("%d",n%2);
    }
}
//���۶��ٽ��ƣ����ÿһλ���ֵķ�������һ���ģ�ȡ�ࣩ������Ҫע���һ��ȡ���õ��Ǹ�λ�����֣�Ҫ����������������Ҫ�ȵݹ���ã���printf��
//�����Ļ��Ϳ��Բ���static������¼�ۼӵĽ����
