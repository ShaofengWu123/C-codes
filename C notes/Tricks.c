#include <stdio.h>
int main() {
	//四舍五入如何做 -> %.nf会帮忙四舍五入，如果编译器不支持->a+0.5
	double a;
	scanf("%lf",&a);
	printf("四舍五入保留到小数点后第三位：%.0f", a );//注意，强制类型转换会直接丢掉小数点后的位数

	//问号表达式
	int b = 1;
	printf("%d", b > 0 ? 1 : 0);

	//批量注释     ctrl K &ctrl C
	//批量去注释 ctrl K &ctrl U
	
	return 0;
}