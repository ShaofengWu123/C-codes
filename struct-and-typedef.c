#include <stdio.h>

struct date {
	int year;
	int month;
	int day;
}day1 = { 2020,1,1, }, * pday1 = &day1,day2;//����date�ṹ��ͬʱ����date�ṹʵ���ָ��date�ṹʵ���ָ�롣

struct {
	int x;
	int y;
}p1 = {1,1};//���������ṹ������������ṹ��һ��ʵ�塣ͨ��������ʱʹ��һ���ṹ��֮����ʹ�õ������

typedef struct student{
	char* name;
	int age;
	int gender;
}STUDENT;//����student�ṹ��ͬʱ������ṹһ������STUDENT������ṹҲ���������ġ�

int main(){
	day2 = (struct date){ 2020,2,2 };//ֱ�Ӹ�ֵ
	struct date day3 = { 2020,3,3 };
	struct date day4 = { .year = 2020,.month = 4 };
	printf("day1: %d %d %d\n", 
		day1.year,
		(*pday1).month,
		pday1->day);//���ַ��ʽṹʵ���Ա�����ķ���
	printf("day2: %d %d %d\n",
		day2.year,
		day2.month,
		day2.day);

	STUDENT david = {"David",22,1};//����typedef��struct student���Ա��滻��STUDENT��
	printf("name:%s\n", david.name);

	typedef int Length;//��int�滻��Length

	typedef char* Strings [10] ;//�������������滻����ʱ�������ŵ��������ڵ�λ�ã���������ȼ��� char* str[10]����ʾstr��һ������10���ַ���������
	Strings str = { "ABC" ,"abc"};
	printf("%s",str[0]);

	return 0;
}