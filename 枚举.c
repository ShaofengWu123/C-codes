#include <stdio.h>
enum color  {red,yellow,blue,colornums };

void f(enum color a);

int main() {
	enum color t = red;
	scanf("%d",&t);

	f(t);//����red��blue�Լ�����enum�����һ��->û���á����ʵ����ö�����;���int��������������Լ��ڲ����㶼��������������
	enum color newcolor = 4;//ö�����;���������ֱ�Ӹ�����ֵҲû���⣨ĳЩ���������ܲ��У�������ö�����͸�ö�����͸�ֵ��
	return 0;
}

void f(enum color a) {
	//if ((a >= red) && (a < colornums)) {
		printf("%d", a);
	//}
	//else { printf("Invalid!"); }
}