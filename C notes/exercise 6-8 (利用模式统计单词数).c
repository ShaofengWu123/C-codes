#include <stdio.h>
#include <stdlib.h>
#define MAXN 100
int main() {
    char a[maxn];
    fgets(a, maxn, stdin);
    int i = 0; int count = 0; int mod = 0;
    while (a[i] != '\n') {
        if (a[i] == ' ') {
            if (mod) { count++; }//mod=1ʱ��������ǰ�ո�֮ǰ���ַ���������һ������
            while (a[i] == ' ') { i++; }
            mod = 0;//�ո��mod����Ϊ0
        }
        else { mod = 1; i++; }//������ĸ�Σ�mod�趨��1
    }
    if (mod) { count++; }//������ʱ����mod=1״̬����ʱҪ�������һ�����ʡ�
}


