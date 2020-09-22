#include <stdio.h>

int main()
{
	const int PASS = 60;
	int score;

	printf("请输入成绩: ");
	scanf("%d", &score);

	printf("你输入的成绩是%d.\n", score);
	if (score < PASS)
		printf("很遗憾，这个成绩没有及格。");
	else if (score == 66) {
		printf("你的成绩及格了，并且是个特殊的数字^^");
	}
	else 
		printf("祝贺你，这个成绩及格了。");
		printf("再见\n");//Note that this line does not belong to else sentence block unless using a {} to include it.

/*The sentence block below has the same effect with previous sentences.
    else{
        printf("祝贺你，这个成绩及格了。");
}
    printf("再见\n");       
*/
	

	return 0;
}
