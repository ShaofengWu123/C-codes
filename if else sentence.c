#include <stdio.h>

int main()
{
	const int PASS = 60;
	int score;

	printf("������ɼ�: ");
	scanf("%d", &score);

	printf("������ĳɼ���%d.\n", score);
	if (score < PASS)
		printf("���ź�������ɼ�û�м���");
	else if (score == 66) {
		printf("��ĳɼ������ˣ������Ǹ����������^^");
	}
	else 
		printf("ף���㣬����ɼ������ˡ�");
		printf("�ټ�\n");//Note that this line does not belong to else sentence block unless using a {} to include it.

/*The sentence block below has the same effect with previous sentences.
    else{
        printf("ף���㣬����ɼ������ˡ�");
}
    printf("�ټ�\n");       
*/
	

	return 0;
}
