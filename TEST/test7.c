//利用函数计算矩形的面积
#include <stdio.h>
double getArea(double length, double width);
int main()
{
    double area1 = getArea(5.0, 3.0);
    double area2 = getArea(7.2, 3.5);
    if (area1 > area2)
    {
        printf("area1 更大n");
    }
    else if (area2 > area1)
    {
        printf("area2 更大\n");
    }
    else
    {
        printf("area1 = area2\n");
    }
    return 0;
}
double getArea(double length, double width)
{
    double area =length * width;
    return area;
}