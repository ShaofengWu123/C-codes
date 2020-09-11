# include <stdio.h>


int sum(int begin, int end);

int main() {
	printf("%d\n", sum(1, 10));

	int i, j;
	printf("%d ",(i=1,j=2));
	return 0;
}

int sum(int begin, int end) {
	int a = 0;
	for (int s = 0, i = begin; i <= end; i++) {
		s += i;
		a = s;
	}
	//s和i是局部变量，这个时候再调用会报错，编译器认为s和i未声明
	return a;
}

