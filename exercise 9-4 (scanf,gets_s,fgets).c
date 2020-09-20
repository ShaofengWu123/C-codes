#include <stdio.h>
#include <stdlib.h>

typedef struct _book {
    char name[32];
    double price;
    struct _book* next;
}Book, * pbook;

int main() {
    int n = 0; char temp;
    scanf("%d", &n); temp = getchar();
    Book* head = NULL, * last = NULL;
    for (int i = 0; i < n; i++) {
        Book* newbook = (Book*)malloc(sizeof(Book));
        fgets(newbook->name, 32, stdin);
        //gets_s(newbook->name, 31);//fgets和gets_s都是以回车作为结尾的，因此都可以用来读一行的数据。区别在于fgets从文件中读取，并且会把‘\n’算作读到的
                                                           //字符串的一部分，所以从键盘读取的时候文件名参数用stdin，字符数组长度要比字符串大2（原因是结尾包含了'\n'和'\0'，而
                                                           //gets_s不包括'\n'，因此只需要大1），并且输出的时候不需要换行（字符串自带）。  
                                                             
        //scanf("%s",newbook->name); scanf()碰到空格、制表符以及回车就结束这次读取，并且把最后一个空格、制表符或者回车放在缓存中，下一次
                                                            //有其他函数例如getchar、gets_s、fgets会读取这个缓存中的字符，导致读取出错
        scanf("%lf", &(newbook->price)); temp = getchar();//因此，在scanf和其他输入函数混合使用时，在scanf后跟一个getchar“吞掉”末尾的字符；这里吞掉的是'\n'
        
        newbook->next = NULL;

        if (head == NULL) {
            head = newbook;
            last = head;
        }
        else {
            last->next = newbook;
            last = newbook;
        }
    }

    Book* max = head, * min = head;
    for (Book* p = head; p; p = p->next) {
        if (p->price > max->price) {
            max = p;
        }
    }

    for (Book* p = head; p; p = p->next) {
        if (p->price < min->price) {
            min = p;
        }
    }

    printf("%.2f, %s", max->price, max->name);
    printf("%.2f, %s", min->price, min->name);
    return 0;
}