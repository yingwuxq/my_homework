//函数递归训练
#include <stdio.h>
void print(unsigned int n);
int main ()
{
    unsigned  int n = 0;
    printf("请输入一个整数:");
    scanf("%d",&n);
    print(n);
    return 0;
}
void print(unsigned int n)
{
    if (n > 9)
    {
        print(n / 10);
    }
    printf("%d",n % 10);
}