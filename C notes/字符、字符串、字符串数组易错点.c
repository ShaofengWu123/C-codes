//关于字符、字符串、字符串数组一些容易混淆的点
#include <stdio.h>
#include <stdlib.h>

int main() {
	char a = 'a';
	char* s = &a;
	char* colornames[3] = {s,"BD","C", };//char* s[]表示s数组里的元素全都是char*(可以是字符也可以是字符串)，其中字符串可以用字面量初始化

	//char* colornames[3] = { 'a',"BD","C" };这样初始化colornames数组是不对的,因为数组元素应该是char*类型，而'a'是char，间接等级不同；而字符串字面量事实上就是指针
																	//即char *s = 'a'是不对的，这样会把'a'的值给s，导致s==97

	//colornames[1][0] = 'b';//修改char* colornames[]中的字符串的元素是非法的，因为此时字符串是指针形式的，处于代码段（只读）
	
	printf("%c\n", *colornames[0]);//输出 a
	printf("%s\n", colornames[1]);//输出 BD。注意两者输出参数的区别，字符串可以直接以指针为参数。 


	char* b = "ABC";//char*变量必须初始化，初始化之后是只读的。
	char c[3] = "ABC";//一定要指明大小或者通过初始化隐式指明大小。
	//b=="ABC"?成立，原因是"ABC"字面量实际上就是指针，相当于在比较两个指针是不是相等。
	//c=="ABC"?不成立，原因是"ABC"指针指的位置和c指的位置不同，前者在代码区，后者就在当前内存区域。
	return 0;
}