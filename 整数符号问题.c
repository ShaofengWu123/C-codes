#include <stdio.h>
int main() {
	unsigned int a = 0;
	printf("%d\n",sizeof(a));
	int b = 0;
	printf("%d\n", sizeof(b));
	int counter = 0;
	printf("%u\n", --a);//输出的时候要用%u
	while (++b >0) {
		;
	}
	printf("%d\n", b - 1);

	do { 
		counter++;
		b = b / 2;
	} while (b / 2 != 0);
	printf("计算机位数%d\n", counter+1);//事实上反映的是编译器位数

	
	char a1 = -1;
	int a2 = -1;
	printf("a1 = %u , a2 = %u\n", a1, a2);//为什么对于char型变量，结果和int型一样呢？
	//原因是：printf在传入变量时，所有长度小于int的变量（char和short）都被当做int传入，因此a1由1111 1111（一个字节）被补全为1111 1111 1111 1111（四个字节）
	//以上的例子反映了不管一个变量是什么类型，在计算机内部表示是固定的，最后关键在于怎么看这个变量。printf()把char视作int，输出时又要求是%u，因此结果是unsigned int的最大值（32位）

	double ff = 1E-10;
	printf("%.15f\n%f\n", ff,ff);//不指定小数点后保留位数，默认所有数字保留共7位，因此会看到0.000000

	if (49 == '1') {//思考一下，这里的条件是什么意思?
	
		printf("OK\n");
	
	}

	int i;
	scanf("%d",&i);//思考一下，输入49会得到什么？输入1又会得到什么？对于python，结果一样吗（可以试一下这行代码print('%s %s' %(49,'49'))）？
	printf("%c\n", i);
	
	int distance;
	distance = 'A' - 'a';
	printf("%c\n", 'a' + distance);//大小写转变
    
	printf("%d", (short)32768);//结果是-32768，原因是1000 0000 0000 0000被保留下来，其为-32768的补码。这里还可以思考一下对于1000...000形式的补码怎么求真值。
	return 0;

	
}

