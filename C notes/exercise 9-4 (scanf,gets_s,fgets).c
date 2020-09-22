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
        //gets_s(newbook->name, 31);//fgets��gets_s�����Իس���Ϊ��β�ģ���˶�����������һ�е����ݡ���������fgets���ļ��ж�ȡ�����һ�ѡ�\n������������
                                                           //�ַ�����һ���֣����ԴӼ��̶�ȡ��ʱ���ļ���������stdin���ַ����鳤��Ҫ���ַ�����2��ԭ���ǽ�β������'\n'��'\0'����
                                                           //gets_s������'\n'�����ֻ��Ҫ��1�������������ʱ����Ҫ���У��ַ����Դ�����  
                                                             
        //scanf("%s",newbook->name); scanf()�����ո��Ʊ���Լ��س��ͽ�����ζ�ȡ�����Ұ����һ���ո��Ʊ�����߻س����ڻ����У���һ��
                                                            //��������������getchar��gets_s��fgets���ȡ��������е��ַ������¶�ȡ����
        scanf("%lf", &(newbook->price)); temp = getchar();//��ˣ���scanf���������뺯�����ʹ��ʱ����scanf���һ��getchar���̵���ĩβ���ַ��������̵�����'\n'
        
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