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
	printf("最大值和最小值是 %d %d\n",max,min);

	//指针减法的含义
	int a1 = 1; int a2 = 2;
	int* q;
	char* r;
	q = &a1; r = &a2;
	printf("q= %p r=%p q-r=%d\n", q, r, q - r);
	
	//看一下能申请到多少内存
	int* pwait;
	int cnt = 0;
	while ((pwait = (int *)malloc(100*1024*1024))) {//注意：这里malloc申请内存后不还给系统是很不好的习惯，正常p = malloc要对应一个free(p)
		cnt++;
	}
	printf("能申请到的内存%d00MB\n", cnt);

	//字符串指针定义和数组定义
	char* pchar;
	char* pchar2 = "Good!";
	char* pchar3 = "Good!";
	pchar = (char*)malloc(5);
	*pchar = "Hello!";
	printf("%p  %p  %p\n",pchar,pchar2,pchar3);
	pchar[0] = "B";//未引发异常，原因是malloc分配的空间不在代码区。
	//pchar2[0] = "B";引发异常，原因是pchar2对应的字符串位于代码区，是只读的。

	char* s = "ABC";
	char* t;
	t = s;
	printf("%p %p", s, t);

	return 0;
}

int maxandmin(int const * p, int* pmax, int* pmin, int n) {//int const * p声明表明函数内不允许通过*p更改原数组的值；pmax和pmin两个指针用于携带多个返回值
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

	return flag;//返回程序运行状态的flag
}