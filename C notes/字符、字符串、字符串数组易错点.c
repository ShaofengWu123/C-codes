//关于字符、字符串、字符串数组一些容易混淆的点
#include <stdio.h>
#include <stdlib.h>

int main() {
	char a = 'a';
	char* s = &a;
	char* colornames[3] = {s,"BD","C", };//char* s[]表示s数组里的元素全都是char*(可以是字符也可以是字符串)，其中字符串可以用字面量初始化

	//char* colornames[3] = { 'a',"BD","C" };这样初始化colornames数组是不对的。虽然char*可以表示字符，但是字符是不能像字符串一样用字面量初始化指针的
																	//即char *s = 'a'是不对的，这样会把'a'的值给s，导致s==97

	//colornames[1][0] = 'b';//修改char* colornames[]中的字符串的元素是非法的，因为此时字符串是指针形式的，处于代码段（只读）
	
	printf("%c\n", *colornames[0]);//输出 a
	printf("%s\n", colornames[1]);//输出 BD。注意两者输出参数的区别，字符串可以直接以指针为参数。 

	return 0;
}