#include <stdio.h>

//�������int &a���������Ͳ�������ʾֱ�Ӳ���ʵ�Σ���ı�ʵ�ε�ֵ�����������ʱ����ʵ�μ��ɣ����ô���ʵ�ε�ָ�롣vs�ƺ���֧������д����
//void f(int& a, int& b) {
//	int temp = 0;
//	temp = a;
//	a = b;
//	b = temp;
//}

void travers(int a[], int n, void (*somefunction)(int a));
void add(int *p);
void printsome(int* p);

typedef void (*f_point)(int *p);
//typedef void f_point(int* p);�ڶ��������ǲ����Եģ�Ҫ��ȷָ��f_point�������Ǻ���ָ�룬��Ϊ������һ������ָ��(add)������һ������(pf)
//typedef void (*f_point)(int a);


int main() {
//�������Ͳ���
//	int a = 0,b=1;
//	f(a, b);
//	printf("a:%d  b:%d",a,b);


//�ص�����
	int a[5] = { 0,11,222,3333,44444, };

	f_point pf = &add;//&��ȫ����ʡ�ԣ��������뺯��ָ��ȼ�add�����ͺ����������ĺ���ָ�����ͱ��� �Ĳ������Ͳ���ȫһ��û��ϵ��
	                              //����add�Ĳ������͸��ǵ������д��һ���ģ�����������ʲô��ʡ�Բ�д  ��typedef void (*f_point)( );
	//�� void (*pf)(int *p) = add �ȼۣ����û�н���typedef��ʡ�Եı�����ô���������������
	

	travers(a, 5, pf);
	travers(a, 5, printsome);
	return 0;
}

//��������Ϊ������ָ�룬��������Ϊ��������
void travers(int a[], int n, void (*somefunction)(int a)) {//���������Ļص�����ָ��Ĳ��������봫���ʵ�ʵĻص�����ָ���Ӧ�Ĳ������Ͳ�һ��û��ϵ���Ḳ�ǵ�
	for (int i = 0; i < n; i++) {//ֻҪ��travers�����ڲ���somefunction���ָ�봫��Ĳ��������ǶԵľ��ܵõ���ȷ�����
		somefunction(&a[i]);//�� ����ָ��(����) ����ʽ��ֱ�ӵ��ú����ǵȼ۵�
	}
}

void travers2(int a[], int n, void somefunction(int a)) {//ʡ��*Ҳ��û������ģ���Ϊ�������뺯��ָ��ȼ�
	for (int i = 0; i < n; i++) {
		somefunction(&a[i]);
	}
}

void add(int *p) {
	*p += 1;
}

void printsome(int* p) {
	printf("%d ",*p);
}