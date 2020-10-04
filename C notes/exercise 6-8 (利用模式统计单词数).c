#include <stdio.h>
#include <stdlib.h>
#define MAXN 100
int main() {
    char a[maxn];
    fgets(a, maxn, stdin);
    int i = 0; int count = 0; int mod = 0;
    while (a[i] != '\n') {
        if (a[i] == ' ') {
            if (mod) { count++; }//mod=1时，表明当前空格之前有字符，可以算一个单词
            while (a[i] == ' ') { i++; }
            mod = 0;//空格段mod保持为0
        }
        else { mod = 1; i++; }//进入字母段，mod设定成1
    }
    if (mod) { count++; }//结束的时候处于mod=1状态，此时要加上最后一个单词。
}


