#include <stdio.h>
#include <stdlib.h>

void move(int* a[], int n, int m);

int main() {
    int m, n=3;//m是右移次数
    scanf("%d", &m);//编译器问题，这里直接取n=3。某些编译器执行C99可以用变量代替数组长度,使用下面这段代码即可。
    /* int * a[n];
    for (int i = 0; i < n; i++) {
        a[i] = (int*)malloc(sizeof(int));
    }*/
    int* a1 = (int*)malloc(sizeof(int));//注意：这里这样分配内存与a[3][3]有区别，a[3][3]会直接以a为头，连续分配36字节的内存空间，而这样分配的空间可以认为
                                                         //矩阵的每一行是分开的，三个在数组连续内存上存放的指针分别指向这三行
    int* a2 = (int*)malloc(sizeof(int));
    int* a3 = (int*)malloc(sizeof(int));
    int* a[3] = { a1,a2,a3 };
    /*for (int i = 0; i < n; i++) {
        a[i] = (int*)malloc(sizeof(int));
    }*/
    //初始化矩阵
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    move(a, n, m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}

void move(int* a[], int n, int m) {/*函数传入的永远是一个指针，对于多维数组也是一样，只会传入数组开始的内存地址，因此有以下两种情况
                                                   1.如果前面a定义为二维数组，那么传入时a指向的数组内容不明（实际上debug会发现数组只包含一个很小的地址，相当于
                                                   没有定义），原因是编译器只知道a是多少，不知道把a当做指向 存放指向整型数据指针 的数组的指针时这个数组里内容是什么，
                                                   于是 自动补成一个很小的指针。因此函数内a[i][j]的访问是非法的。
                                                   编译器会提示间接等级不一样，这个时候传入的a是int*，而函数形参是int **。如果一定要这样传入，也能通过编译，但是要注意
                                                   由于数组所有的元素是连续存放在内存里的，而函数只知道a是多少。循环时换行只需要a+i*12（一行占了12字节）
                                                   
                                                   2.如果前面a定义为int*a[]，即指向整型指针的数组，那么a[i][j]的访问就是有意义的，a[i]相当于存放在a里索引为i的整型指针，
                                                       a[i][j]相当于访问这个指针+j的位置，因此是合法的。
                                                      
                                                   总结：在创建二维数组时就把二维数组当做指针数组创建 ，传入的时候类型写成 elemtype* array[]与定义对应，这样在函数内
                                                   用a[i][j]访问合法。这个例子也看出数组和指针不能等同起来。数组不管多少维，传入的时候a代表的指针类型是最小元素的指针
                                                   类型，例如这个例子中int a[3][3]，传入函数的时候指针是int*型；而int*a[3]，传入的时候是int**型。

                                                   另外，根据做题时的状况来看，不同编译器创建a[n][n]，n是变量，这样的a类型不明确，因此a+i表达的意思会有歧义。
                                                   因此还是采用上面所说的定义二维数组的方法最好。
                                                   */                                                    
    int temp = 0;
    m = m % n;
    for (int count = 1; count <= m; count++) {
        for (int i = 0; i < n; i ++) {
            temp = a[i][n - 1];
            for (int j = n - 1; j > 0; j--) {

                a[i][j] = a[i][j - 1];
            }
            a[i][0] = temp;
        }
        /*用来debug，每向右移动一次输出一下
        for (int i = 0; i < n*n; i+=n) {
            for (int j = 0; j < n; j++) {
                printf("%d ", *(a+i+j));
            }
            printf("\n\n");
        }*/
    }
}
