#include <stdio.h>
enum color  {red,yellow,blue,colornums };

void f(enum color a);

int main() {
	enum color t = red;
	scanf("%d",&t);

	f(t);//输入red，blue以及不在enum里的试一下->没有用。因此实际上枚举类型就是int，输入输出都是以及内部计算都是用整数来做的
	enum color newcolor = 4;//枚举类型就是整数，直接赋整数值也没问题（某些编译器可能不行，必须用枚举类型给枚举类型赋值）
	return 0;
}

void f(enum color a) {
	//if ((a >= red) && (a < colornums)) {
		printf("%d", a);
	//}
	//else { printf("Invalid!"); }
}