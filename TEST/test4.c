// 回文数
#include <stdio.h>

int main () {
    int n, a = 0, b, c;
    printf("请输入一个整数：");
    scanf("%d",&n);
    c = n;

    // 翻转
    while(n != 0) {
        b = n % 10; // 取余
        a = a * 10 + b; // 翻转
        n = n / 10; // 缩小
    }
    // 判段
    if(a == c) {
        printf("%d 是回文数\n",c);
    } else {
        printf("%d 不是回文数\n",c);
    }
    return 0;
}