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
	//s��i�Ǿֲ����������ʱ���ٵ��ûᱨ����������Ϊs��iδ����
	return a;
}

