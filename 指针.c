#include <stdio.h>
#include <stdlib.h>

int maxandmin(int *p , int *pmax, int *pmin, int n);

int main() {
	int a = 1;
	int* pa;
	pa = &a;
	printf("a = %d, pa = %p\n", a , pa);
	pa++;
	printf("*pa = %d , pa = %p\n", *pa ,pa);

	int num[] = { 2,654,2,4234,764,65,756,13,1,85,4,13, };
	int const * p = &num[0];
	int max= num[0] , min = num[0];
	int n = sizeof(num) / sizeof(num[0]);
	maxandmin(p, &max, &min, n);
	//maxandmin(num, &max, &min, n);
	//maxandmin(&num[0], &max, &min, n);
	int* p1 = &num[5];
	printf("p1[-2] = %d\n",p1[-2]);
	printf("���ֵ����Сֵ�� %d %d\n",max,min);

	//ָ������ĺ���
	int a1 = 1; int a2 = 2;
	int* q;
	char* r;
	q = &a1; r = &a2;
	printf("q= %p r=%p q-r=%d\n", q, r, q - r);
	
	//��һ�������뵽�����ڴ�
	int* pwait;
	int cnt = 0;
	while ((pwait = (int *)malloc(100*1024*1024))) {//ע�⣺����malloc�����ڴ�󲻻���ϵͳ�Ǻܲ��õ�ϰ�ߣ�����p = mallocҪ��Ӧһ��free(p)
		cnt++;
	}
	printf("�����뵽���ڴ�%d00MB\n", cnt);

	//�ַ���ָ�붨������鶨��
	char* pchar;
	char* pchar2 = "Good!";
	char* pchar3 = "Good!";
	pchar = (char*)malloc(5);
	*pchar = "Hello!";
	printf("%p  %p  %p\n",pchar,pchar2,pchar3);
	pchar[0] = "B";//δ�����쳣��ԭ����malloc����Ŀռ䲻�ڴ�������
	//pchar2[0] = "B";�����쳣��ԭ����pchar2��Ӧ���ַ���λ�ڴ���������ֻ���ġ�

	char* s = "ABC";
	char* t;
	t = s;
	printf("%p %p", s, t);

	return 0;
}

int maxandmin(int const * p, int* pmax, int* pmin, int n) {//int const * p�������������ڲ�����ͨ��*p����ԭ�����ֵ��pmax��pmin����ָ������Я���������ֵ
	int flag = 0;

	for (int i = 0; i < n; i++) {
		if (p[i] >  *pmax) {
			*pmax = p[i];
		}
	}

	for (int i = 0; i < n; i++) {
		if (p[i] <  *pmin) {
			*pmin = p[i];
		}
		flag = 1;
	}

	return flag;//���س�������״̬��flag
}