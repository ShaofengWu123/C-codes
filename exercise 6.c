#include <stdio.h>

int main() {
	char c;
	int l = 0, b = 0, d = 0, o = 0;
	//scanf("%10s",s);
	//printf("%s", s);
	for (int i = 0; i < 10; i++) {
		c = getchar();//getchar()��������scanf()�Կո񡢻س����������ǵõ�һ��һ�����ַ�
		// 'a'-'z' -> 97-122 ;'A'-'Z') -> 66-91
		if ((c >= 'a' && c <= 'z')||(c >= 'A' && c <= 'Z')) { l++; }
		else if (c >= '0' && c <= '9') { d++; }
		else if (c == ' ' || c == '\n') { b++; }//Ҫע��\n�س����к�\r�س�������
		else { o++; }
	}

	printf("letter = %d, blank = %d, digit = %d, other = %d",l,b,d,o);

	return 0;
}