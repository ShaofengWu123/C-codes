#include <stdio.h>
int main() {
	//四舍五入如何做 -> %.nf会帮忙四舍五入(gcc支持)，如果编译器不支持->a+0.5
	double a;
	a = 1.00354;
	printf("四舍五入保留到小数点后第三位：%.3f\n", a );
	//注意，强制类型转换会直接丢掉小数点后的位数
	printf("强制类型转换会直接丢掉小数点后的位数：%d\n", (int)a);

	//问号表达式
	int b = 1;
	printf("%d", b > 0 ? 1 : 0);

	//批量注释     ctrl K &ctrl C
	//批量去注释 ctrl K &ctrl U
	
	return 0;
}