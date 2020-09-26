#include <stdio.h>

//函数里的int &a是引用类型参数，表示直接操作实参，会改变实参的值，传入参数的时候传入实参即可，不用传入实参的指针。vs似乎不支持这种写法。
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
//typedef void f_point(int* p);第二种声明是不可以的，要明确指出f_point的类型是函数指针，因为不能让一个函数指针(add)等于另一个函数(pf)
//typedef void (*f_point)(int a);


int main() {
//引用类型参数
//	int a = 0,b=1;
//	f(a, b);
//	printf("a:%d  b:%d",a,b);


//回调函数
	int a[5] = { 0,11,222,3333,44444, };

	f_point pf = &add;//&完全可以省略，函数名与函数指针等价add的类型和上面声明的函数指针类型别名 的参数类型不完全一样没关系，
	                              //会用add的参数类型覆盖掉。最好写成一样的，如果不清楚是什么就省略不写  即typedef void (*f_point)( );
	//与 void (*pf)(int *p) = add 等价，如果没有进行typedef起省略的别名那么就这样定义变量。
	

	travers(a, 5, pf);
	travers(a, 5, printsome);
	return 0;
}

//函数名即为函数的指针，在这里作为参数传递
void travers(int a[], int n, void (*somefunction)(int a)) {//这里声明的回调函数指针的参数类型与传入的实际的回调函数指针对应的参数类型不一样没关系，会覆盖掉
	for (int i = 0; i < n; i++) {//只要在travers函数内部给somefunction这个指针传入的参数类型是对的就能得到正确结果。
		somefunction(&a[i]);//用 函数指针(参数) 的形式与直接调用函数是等价的
	}
}

void travers2(int a[], int n, void somefunction(int a)) {//省略*也是没有问题的，因为函数名与函数指针等价
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