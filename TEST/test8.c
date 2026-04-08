//Ã°ÅÝÅÅÐòº¯Êý
#include <stdio.h>
void Sort(int a[],int n);
int main()
{
    int a[9] = {3,5,37,15,44,26,36,47,13};
    Sort(a,9);
    for (int i = 0;i < 9;i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}

void Sort(int a[],int n)
{
    for (int i = 0;i < n-1;i++)
    {
        for (int j = 0;j < n-i-1;j++)
        {
            if (a[j] > a[j+1])
            {
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}