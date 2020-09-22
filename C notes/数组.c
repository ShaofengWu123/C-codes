#include <stdio.h>

void printnumset(int set[], int len);
void printnumset2(int set[][5], int len, int lenlen);

int main() {
	int set1[10];//数组定义（元素值没有初始化）
	int set2[] = { [0] = 1,2,[5] = 5, };//集成初始化且定位
	int set3[] = { 2,4,6,8,10, };//集成初始化
	int set4[10] = { 1,3, };//集成初始化，规定元素个数，没有声明数值的元素用0补全

	printf("set1元素个数:%d\n", (sizeof(set1) / sizeof(set1[0])));//输出数组的元素个数

	printnumset(set2, sizeof(set2) / sizeof(set2[0]));

	printnumset(set4, sizeof(set4) / sizeof(set4[0]));


	int set5[][5] = {
		{1,3,5,7,9},
		{2,4,6,8,10},
		{11,13,15,17,19},
	};//初始化时在最后留一个逗号,good style
	int set6[3][3] = {
		1,2,3,4,5,6,7,8,9,
	};//依次填入

	int a1 = sizeof(set5) / sizeof(set5[0]);
	int a2 = sizeof(set5[0]) / sizeof(set5[0][0]);
	printnumset2(set5 , a1 , a2);


	return 0;
}


void printnumset(int set[], int len) {//不仅要传入数组，还要单独传入数组的长度
	for (int i = 0; i < len; i++) {

		printf("\t%d", set[i]);

	}
	printf("\n");
}

void printnumset2(int set[][5], int len , int lenlen){
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < lenlen; j++)
		{
			printf("\t%d  ", set[i][j]);
		}
		printf("\n");
	}

}