#include <stdio.h>

int main() {
	char c;
	int l = 0, b = 0, d = 0, o = 0;
	//scanf("%10s",s);
	//printf("%s", s);
	for (int i = 0; i < 10; i++) {
		c = getchar();//getchar()函数不像scanf()以空格、回车结束，而是得到一个一个的字符
		// 'a'-'z' -> 97-122 ;'A'-'Z') -> 66-91
		if ((c >= 'a' && c <= 'z')||(c >= 'A' && c <= 'Z')) { l++; }
		else if (c >= '0' && c <= '9') { d++; }
		else if (c == ' ' || c == '\n') { b++; }//要注意\n回车换行和\r回车的区别。
		else { o++; }
	}

	printf("letter = %d, blank = %d, digit = %d, other = %d",l,b,d,o);

	return 0;
}