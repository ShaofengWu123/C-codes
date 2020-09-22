#include <stdio.h>

struct date {
	int year;
	int month;
	int day;
}day1 = { 2020,1,1, }, * pday1 = &day1,day2;//定义date结构的同时定义date结构实体和指向date结构实体的指针。

struct {
	int x;
	int y;
}p1 = {1,1};//定义无名结构，并定义这个结构的一个实体。通常用于临时使用一个结构，之后不再使用的情况。

typedef struct student{
	char* name;
	int age;
	int gender;
}STUDENT;//定义student结构的同时给这个结构一个别名STUDENT，这个结构也可以无名的。typedef用于给复杂的类型一个简单的别名

//typedef给复杂类型别名
#define MAX_LEN 10//简单的文本替换，发生在预编译阶段
typedef A[MAX_LEN];//类型别名，定义指定类型的变量，发生在编译阶段。

typedef int* IP;
IP ip1, ip2;//ip1和ip2的类型分别是什么？-》都是int*，也就是说typedef把几个复合类型封装起来成了一个类型，并用一个简单的名字表示。#define没有这个功能

typedef int (*ptrf)(int a[]);
ptrf f_pointer;//定义变量的时候，把变量放到别名的位置看一看，就能知道这个变量是什么类型

int main(){
	day2 = (struct date){ 2020,2,2 };//直接赋值
	struct date day3 = { 2020,3,3 };
	struct date day4 = { .year = 2020,.month = 4 };
	printf("day1: %d %d %d\n", 
		day1.year,
		(*pday1).month,
		pday1->day);//三种访问结构实体成员变量的方法
	printf("day2: %d %d %d\n",
		day2.year,
		day2.month,
		day2.day);

	STUDENT david = {"David",22,1};//经过typedef，struct student可以被替换成STUDENT。
	printf("name:%s\n", david.name);

	typedef int Length;//把int替换成Length

	typedef char* Strings [10] ;//复杂声明可以替换。这时变量被放到别名所在的位置，例如这里等价于 char* str[10]，表示str是一个包含10个字符串的数组
	Strings str = { "ABC" ,"abc"};
	printf("%s",str[0]);

	return 0;
}