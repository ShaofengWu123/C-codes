#include <stdio.h>

void printnumset(int set[], int len);
void printnumset2(int set[][5], int len, int lenlen);

int main() {
	int set1[10];//���鶨�壨Ԫ��ֵû�г�ʼ����
	int set2[] = { [0] = 1,2,[5] = 5, };//���ɳ�ʼ���Ҷ�λ
	int set3[] = { 2,4,6,8,10, };//���ɳ�ʼ��
	int set4[10] = { 1,3, };//���ɳ�ʼ�����涨Ԫ�ظ�����û��������ֵ��Ԫ����0��ȫ

	printf("set1Ԫ�ظ���:%d\n", (sizeof(set1) / sizeof(set1[0])));//��������Ԫ�ظ���

	printnumset(set2, sizeof(set2) / sizeof(set2[0]));

	printnumset(set4, sizeof(set4) / sizeof(set4[0]));


	int set5[][5] = {
		{1,3,5,7,9},
		{2,4,6,8,10},
		{11,13,15,17,19},
	};//��ʼ��ʱ�������һ������,good style
	int set6[3][3] = {
		1,2,3,4,5,6,7,8,9,
	};//��������

	int a1 = sizeof(set5) / sizeof(set5[0]);
	int a2 = sizeof(set5[0]) / sizeof(set5[0][0]);
	printnumset2(set5 , a1 , a2);


	return 0;
}


void printnumset(int set[], int len) {//����Ҫ�������飬��Ҫ������������ĳ���
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