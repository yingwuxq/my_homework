/洛谷刷题100
//#include <stdio.h>
//int main()
//{
//    int arr[] = {33, 22, 5, 44, 55};
//    int max = arr[0];
//    int len = sizeof(arr) / sizeof(arr[0]);
//    for (int i = 0; i < len; i++)
//    {
//        if (arr[i] > max)
//        {
//            max = arr[i];
//        }
//    }
//    printf("%d", max);
//    return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//int main()
//{
//    //需求：生成10个1~100之间的随机数存入数组中
//    //求出所有数据的和、最大值
//    int arr[10];
//    int max = 0;
//    int sum = 0;
//    int len = sizeof(arr) / sizeof(arr[0]);
//    for (int i = 0; i < len; i++)
//    {
//        arr[i] = rand() % 100 + 1;
//        printf("%d ", arr[i]);
//        sum += arr[i];
//        if (arr[i] > max)
//        {
//            max = arr[i];
//        }
//    }
//    printf("\sum = %d\n", sum);
//    printf("max = %d\n", max);
//    return 0;
//}

//#include <stdio.h>
//#include <time.h>
//#include <stdlib.h>
//void printArr(int arr[], int len);
//int main()
//{
//    //需求：键盘录入5个数据存入数组中1）遍历数组元素 2）反转数组元素 3）再次遍历数组元素
//    int arr[5];
//    int len = sizeof(arr) / sizeof(arr[0]);
//    printf("请输入%d个数据：\n", len);
//    for (int i = 0; i < len; i++)
//    {
//        scanf("%d", &arr[i]);
//    }
//    printf("遍历数组元素：\n");
//    printArr(arr, len);
//    printf("\n反转数组元素：\n");
//    int i = 0;
//    int j = len - 1;
//    while (i < j)
//    {
//        int temp = arr[i];
//        arr[i] = arr[j];
//        arr[j] = temp;
//        i++;
//        j--;
//    }
//    printArr(arr, len);
//    printf("\n随机反转数组元素：\n");
//    srand((unsigned int)time(NULL));
//    for (int i = 0; i < len; i++)
//    {
//        int index = rand() % len;
//        int temp = arr[i];
//        arr[i] = arr[index];
//        arr[index] = temp;
//    }
//    printArr(arr, len);
//    return 0;
//}
//void printArr(int arr[], int len)
//{
//    for (int i = 0; i < len; i++)
//    {
//        printf("%d ", arr[i]);
//    }
//}

//#include <stdio.h>
//int binarySearch(int arr[], int num, int len);
//int main()
//{
//    int arr[] = {11,55 ,45,15,26};
//    int len = sizeof(arr) / sizeof(arr[0]);
//    int num = 15;
//    printf("%d\n", binarySearch(arr, num, len));
//    return 0;
//}
//int binarySearch(int arr[], int num, int len)
//{
//    for(int i = 0; i < len; i++)
//    {
//        if(arr[i] == num)
//            return i;
//    }
//    return -1;
//}

//# include <stdio.h>
//int binarySearch(int arr[], int num, int len);
//int main()
//{
//    int arr[] = {7,12,15,18,22,23,45,56};
//    int len = sizeof(arr) / sizeof(arr[0]);
//    printf("请输入你要查找的数字：\n");
//    int num;
//    scanf("%d", &num);
//    printf("%d\n", binarySearch(arr, num, len));
//}
//int binarySearch(int arr[], int num, int len)
//{
//    int left = 0;
//    int right = len - 1;
//    while(left <= right)
//    {
//        int mid = (left + right) / 2;
//        if(arr[mid] == num)
//            return mid;
//        else if(arr[mid] > num)
//            right = mid - 1;
//        else
//            left = mid + 1;
//    }
//    return -1;
//}


//#include <stdio.h>
//#include <math.h>
//
//int main() {
//    int h, r;
//    double pi = 3.14;
//    double bucket_volume, total_water, buckets_needed;
//
//    scanf("%d %d", &h, &r);
//
//    bucket_volume = pi * r * r * h;
//
//    bucket_volume /= 1000.0;
//
//    total_water = 20.0;
//    buckets_needed = ceil(total_water / bucket_volume);
//
//    printf("%d\n", (int)buckets_needed);
//
//    return 0;
//}


//#include <stdio.h>
//
//int main() {
//    int a, b, c, d;
//    int total_minutes_start, total_minutes_end;
//    int total_minutes_diff;
//    int e, f;
//
//    scanf("%d %d %d %d", &a, &b, &c, &d);
//
//    total_minutes_start = a * 60 + b;
//    total_minutes_end = c * 60 + d;
//
//    total_minutes_diff = total_minutes_end - total_minutes_start;
//
//    e = total_minutes_diff / 60;
//    f = total_minutes_diff % 60;
//
//    printf("%d %d\n", e, f);
//    return 0;
//}


//#include <stdio.h>
//
//int main()
//{
//    int a, b;
//    int total_money_in_jiao;
//    int price_per_pen = 19;
//    int max_pens;
//
//    scanf("%d %d", &a, &b);
//
//    total_money_in_jiao = a * 10 + b;
//
//    max_pens = total_money_in_jiao / price_per_pen;
//
//    printf("%d\n", max_pens);
//    return 0;
//}


//#include <stdio.h>
//
//int main()
// {
//    int m, t, s;
//    int eaten_apples;
//    int remaining_apples;
//    scanf("%d %d %d", &m, &t, &s);
//    if (t == 0)
//    {
//        printf("%d\n", m);
//        return 0;
//    }
//    eaten_apples = s / t;
//    remaining_apples = m - eaten_apples;
//    printf("%d\n", remaining_apples);
//    return 0;
//}


//#include <stdio.h>
//
//int main()
// {
//    int x;
//    scanf("%d", &x);
//    int prop1 = (x % 2 == 0);
//    int prop2 = (x > 4 && x <= 12);
//    int like_A = (prop1 && prop2);
//    int like_Uim = (prop1 || prop2);
//    int like_B = (prop1 != prop2);
//    int like_Zhengmei = !(prop1 || prop2);
//    printf("%d %d %d %d\n", like_A, like_Uim, like_B, like_Zhengmei);
//    return 0;
//}

//#include <stdio.h>
//
//int main()
//{
//    int year;
//    scanf("%d", &year);
//    int is_leap_year = 0;
//    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
//    {
//        is_leap_year = 1;
//    }
//    printf("%d\n", is_leap_year);
//    return 0;
//}

//#include <stdio.h>
//
//int main()
//{
//    int x;
//    scanf("%d", &x);
//    if (x == 0) {
//        printf("Today, I ate 0 apples.\n");
//    } else if (x == 1) {
//        printf("Today, I ate 1 apple.\n");
//    } else {
//        printf("Today, I ate %d apples.\n", x);
//    }
//    return 0;
//}

//#include <stdio.h>
//
//int main()
//{
//    int n;
//    scanf("%d", &n);
//    int local_time = 5 * n;
//    int luogu_time = 11 + 3 * n;
//    if (local_time < luogu_time)
//    {
//        printf("Local\n");
//    }
//    else
//    {
//        printf("Luogu\n");
//    }
//    return 0;
//}

//#include <stdio.h>
//#include <math.h>
//
//char* format_bmi(double bmi)
//{
//    static char result[20];
//    sprintf(result, "%.6g", bmi);
//    return result;
//}
//
//int main()
//{
//    double m, h;
//    scanf("%lf %lf", &m, &h);
//    double bmi = m / (h * h);
//    if (bmi < 18.5)
//    {
//        printf("Underweight\n");
//    }
//    else if (bmi >= 18.5 && bmi < 24)
//    {
//        printf("Normal\n");
//    }
//    else
//    {
//        printf("%s\n", format_bmi(bmi));
//        printf("Overweight\n");
//    }
//    return 0;
//}

//#include <stdio.h>
//int main()
//{
//    int a, b, c;
//    scanf("%d %d %d", &a, &b, &c);
//    if (a > b)
//    {
//        int temp = a;
//        a = b;
//        b = temp;
//    }
//    if (a > c)
//    {
//        int temp = a;
//        a = c;
//        c = temp;
//    }
//    if (b > c)
//    {
//        int temp = b;
//        b = c;
//        c = temp;
//    }
//    printf("%d %d %d\n", a, b, c);
//    return 0;
//}

//#include <stdio.h>
//int is_leap_year(int year);
//int main()
//{
//    int year,month;
//    scanf("%d %d", &year, &month);
//    int arr[] = {0,21,28,31,30,31,30,31,31,30,31,30,31};
//    if(is_leap_year(year) && month == 2)
//    {
//        arr[2] = 29;
//    }
//    printf("%d\n", arr[month]);
//    return 0;
//}
//
//int is_leap_year(int year)
//{
//    if((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
//    {
//        return 1;
//    }
//    return 0;
//}

//用高精度算出S= 1! +2！+3！+...+n！(n<= 50)
//#include <stdio.h>
//#include <string.h>
//
//#define MAX_DIGITS 1000  // 高精度数字的最大位数
//
//// 高精度加法
//void add(int *a, int *b, int *result) {
//    int carry = 0;
//    for (int i = 0; i < MAX_DIGITS || carry; i++) {
//        int sum = a[i] + b[i] + carry;
//        result[i] = sum % 10;
//        carry = sum / 10;
//    }
//}
//
//// 高精度乘法
//void multiply(int *a, int num, int *result) {
//    int carry = 0;
//    for (int i = 0; i < MAX_DIGITS || carry; i++) {
//        int product = a[i] * num + carry;
//        result[i] = product % 10;
//        carry = product / 10;
//    }
//}
//
//// 打印高精度数字
//void print_number(int *num) {
//    int i;
//    for (i = MAX_DIGITS - 1; i > 0 && num[i] == 0; i--);
//    for (; i >= 0; i--) {
//        printf("%d", num[i]);
//    }
//    printf("\n");
//}
//
//int main() {
//    int n;
//    printf("请输入 n (n <= 50): ");
//    scanf("%d", &n);
//
//    int factorial[MAX_DIGITS] = {1};  // 初始化阶乘为 1
//    int sum[MAX_DIGITS] = {0};        // 初始化和为 0
//
//    for (int i = 1; i <= n; i++) {
//        // 计算 i!
//        int temp[MAX_DIGITS] = {0};
//        multiply(factorial, i, temp);
//        memcpy(factorial, temp, sizeof(temp));
//
//        // 将 i! 加到 sum 中
//        add(sum, factorial, sum);
//    }
//
//    printf("S = ");
//    print_number(sum);
//
//    return 0;
//}

//#include <stdio.h>
//
//int main()
//{
//    int maxUnhappyDay = 0;
//    int maxUnhappyTime = -1;
//    int schoolHours, extraHours;
//    for (int day = 1; day <= 7; day++)
//    {
//        scanf("%d %d", &schoolHours, &extraHours);
//        int totalHours = schoolHours + extraHours;
//        if (totalHours > 8)
//        {
//            if (totalHours > maxUnhappyTime)
//            {
//                maxUnhappyTime = totalHours;
//                maxUnhappyDay = day;
//            }
//        }
//    }
//    if (maxUnhappyDay == 0)
//    {
//        printf("0\n");
//    }
//    else
//    {
//        printf("%d\n", maxUnhappyDay);
//    }
//    return 0;
//}

//#include <stdio.h>
//
//int main()
//{
//    int totalUsage;
//    double cost = 0.0;
//    scanf("%d", &totalUsage);
//    if (totalUsage <= 150)
//    {
//        cost = totalUsage * 0.4463;
//    }
//    else if (totalUsage <= 400)
//    {
//        cost = 150 * 0.4463 + (totalUsage - 150) * 0.4663;
//    }
//    else
//    {
//        cost = 150 * 0.4463 + 250 * 0.4663 + (totalUsage - 400) * 0.5663;
//    }
//    printf("%.1f\n", cost);
//    return 0;
//}

//#include <stdio.h>
//
//int main()
//{
//    int x, n;
//    int full_weeks, remaining_days;
//    int total_distance = 0;
//    scanf("%d %d", &x, &n);
//    full_weeks = n / 7;
//    remaining_days = n % 7;
//    total_distance += full_weeks * 5 * 250;
//    for (int i = 0; i < remaining_days; i++)
//    {
//        int current_day = (x + i - 1) % 7 + 1;
//        if (current_day <= 5)
//        {
//            total_distance += 250;
//        }
//    }
//    printf("%d\n", total_distance);
//    return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//
//int gcd(int a, int b);
//void simplify_fraction(int *numerator, int *denominator);
//
//int main()
//{
//    int a, b, c;
//    scanf("%d %d %d", &a, &b, &c);
//    int max_side = (a > b) ? ((a > c) ? a : c) : ((b > c) ? b : c);
//    int min_side = (a < b) ? ((a < c) ? a : c) : ((b < c) ? b : c);
//    int other_side = (a != max_side && a != min_side) ? a : ((b != max_side && b != min_side) ? b : c);
//    int numerator = min_side;
//    int denominator = max_side;
//    simplify_fraction(&numerator, &denominator);
//    printf("%d/%d\n", numerator, denominator);
//    return 0;
//}
//
//int gcd(int a, int b)
//{
//    if (b == 0)
//    {
//        return a;
//    }
//    return gcd(b, a % b);
//}
//void simplify_fraction(int *numerator, int *denominator)
//{
//    int divisor = gcd(*numerator, *denominator);
//    *numerator /= divisor;
//    *denominator /= divisor;
//}

//#include <stdio.h>
//
//int main()
//{
//    int m, t, s;
//    scanf("%d %d %d", &m, &t, &s);
//
//    if (t == 0) {
//        printf("0\n");
//    } else {
//        int eaten_apples = s / t;
//        int remaining_apples = m - eaten_apples;
//
//        if (remaining_apples < 0) {
//            remaining_apples = 0;
//        }
//        printf("%d\n", remaining_apples);
//    }
//    return 0;
//}

//#include <stdio.h>
//#include <string.h>
//
//int main() {
//    int a, b, c;
//    char order[4];
//
//    scanf("%d %d %d", &a, &b, &c);
//    scanf("%s", order);
//
//    if (a > b) {
//        int temp = a;
//        a = b;
//        b = temp;
//    }
//    if (b > c) {
//        int temp = b;
//        b = c;
//        c = temp;
//    }
//    if (a > b) {
//        int temp = a;
//        a = b;
//        b = temp;
//    }
//
//    for (int i = 0; i < 3; i++) {
//        if (order[i] == 'A') {
//            printf("%d ", a);
//        } else if (order[i] == 'B') {
//            printf("%d ", b);
//        } else if (order[i] == 'C') {
//            printf("%d ", c);
//        }
//    }
//
//    printf("\n");
//
//    return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//
//int main()
//{
//    //1.输入范围
//    int a,b,i,j,reverse;
//    reverse=0;
//    printf("Please input a,b(5<=a<b<=1000,000,000):");
//    scanf("%d%d",&a,&b);
//    //2.判断
//    for(i=a;i<b;i++)
//    {
//        int t=i;
//        while(t!=0)
//        {
//            int temp=t%10;
//            t=t/10;
//            reverse=reverse*10+temp;
//        }
//        if(reverse==i)
//        {
//            for(j=2;j<i;j++)
//            {
//                if(i%j==0)
//                    break;
//            }
//            if(j==i)
//                printf("%d\n",j);
//        }
//    }
//    return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//
//// 计算向上取整
//int ceil_div(int a, int b) {
//    return (a + b - 1) / b;
//}
//
//int main() {
//    int n;
//    int min_cost = 10000000; // 初始化最小花费为一个很大的数
//    scanf("%d", &n);
//    for (int i = 0; i < 3; i++) {
//        int quantity, price;
//        scanf("%d %d", &quantity, &price);
//        // 计算需要购买的包装数量
//        int num_packages = ceil_div(n, quantity);
//        // 计算总花费
//        int total_cost = num_packages * price;
//        // 更新最小花费
//        if (total_cost < min_cost) {
//            min_cost = total_cost;
//        }
//    }
//    printf("%d\n", min_cost);
//    return 0;
//}

//#include <stdio.h>
//int main()
//{
//    int n;
//    scanf("%d", &n);
//    int min = 1000000000;
//    for (int i = 0;i < n; i++){
//        int a;
//        scanf("%d", &a);
//        if (a < min){
//            min = a;
//        }
//    }
//    printf("%d\n", min);
//    return 0;
//}

//#include <stdio.h>
//int main()
//{
//    int n,k;
//    scanf("%d %d", &n, &k);
//    int sum1 = 0, sum2 = 0;
//    int count1 = 0, count2 = 0;
//    for (int i = 1;i <= n; i++){
//        if (i % k == 0){
//            sum1 += i;
//            count1++;
//        }else{
//            sum2 += i;
//            count2++;
//        }
//    }
//    double avg1 = (double)sum1 / count1;
//    double avg2 = (double)sum2 / count2;
//    printf("%.1lf %.1lf\n", avg1, avg2);
//    return 0;
//}

//#include <stdio.h>
//int main()
//{
//    int a;
//    scanf("%d", &a);
//    int days = 0;
//    while (a > 1){
//        a /= 2;
//        days++;
//    }
//    printf("%d\n", days + 1);
//    return 0;
//}

//#include <stdio.h>
//int main()
//{
//    int n;
//    scanf("%d", &n);
//    int num = 1;
//    for (int i = 1;i <= n; i++){
//        for (int j = 1;j <= n- i +1; j++){
//            printf("%02d", num);
//            num++;
//        }
//        printf("\n");
//    }
//    return 0;
//}

//#include <stdio.h>
//int main()
//{
//    int n,x;
//    scanf("%d %d", &n, &x);
//    int count = 0;
//    for(int i = 1;i <= n; i++){
//        int num = i;
//        while(num > 0){
//            if(num % 10 == x){
//                count++;
//            }
//            num /= 10;
//        }
//    }
//    printf("%d\n", count);
//    return 0;
//}

//#include <stdio.h>
//int main()
//{
//    int k;
//    scanf("%d", &k);
//    double sum = 0.0;
//    int n = 1;
//    while (sum < k)
//    {
//        sum += 1.0 / n;
//        n++;
//    }
//    printf("%d\n", n - 1);
//    return 0;
//}

//#include <stdio.h>
//
//int main() {
//    int n;
//    scanf("%d", &n);
//    int a[n];
//    for (int i = 0; i < n; i++) {
//        scanf("%d", &a[i]);
//        if (a[i] < 0 || a[i] > 1000) {
//            printf("Invalid input\n");
//            return 1;
//        }
//    }
//    int max_val = a[0];
//    int min_val = a[0];
//
//    for (int i = 1; i < n; i++) {
//        if (a[i] > max_val) {
//            max_val = a[i];
//        }
//        if (a[i] < min_val) {
//            min_val = a[i];
//        }
//    }
//    int range = max_val - min_val;
//    printf("%d\n", range);
//    return 0;
//}

//#include <stdio.h>
//
//int main()
//{
//    int n;
//    scanf("%d", &n);
//    if (n < 1 || n > 9) {
//        printf("Invalid input\n");
//        return 1;
//    }
//    int num = 1;
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < n; j++) {
//            printf("%02d", num++);
//        }
//        printf("\n");
//    }
//    printf("\n");
//
//    num = 1;
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < n - i - 1; j++) {
//            printf("  ");
//        }
//        for (int j = 0; j <= i; j++) {
//            printf("%02d", num++);
//        }
//        printf("\n");
//    }
//    return 0;
//}

//#include <stdio.h>
//int main()
//{
//    int k;
//    scanf("%d", &k);
//    int a = 0,b = 1,c = 1;
//    for(int i = 1;i <= k;i++){
//        a += b;
//        c--;
//        if(c == 0){
//            b++;
//            c = b;
//        }
//    }
//    printf("%d\n", a);
//    return 0;
//}

//#include <stdio.h>
//int main()
//{
//    double s;
//    scanf("%lf", &s);
//    double a = 2.0,b = 0.0;
//    int count = 0;
//    while(b < s){
//        b += a;
//        a *= 0.98;
//        count++;
//    }
//    printf("%d\n", count);
//    return 0;
//}

//#include <stdio.h>
//
//int main()
//{
//    int N;
//    scanf("%d", &N);
//    int is_negative = (N < 0);
//    if (is_negative) {
//        N = -N;
//    }
//    int reversed = 0;
//    while (N > 0) {
//        reversed = reversed * 10 + N % 10;
//        N /= 10;
//    }
//    if (is_negative) {
//        reversed = -reversed;
//    }
//    printf("%d\n", reversed);
//    return 0;
//}

//#include <stdio.h>
//#include <math.h>
//
//int main ()
//{
//    int n;
//    scanf("%d", &n);
//    double a = (1 + sqrt(5)) / 2;
//    double b = (1 - sqrt(5)) / 2;
//    double Fn = (pow(a, n) - pow(b, n)) / sqrt(5);
//    printf("%.2lf\n", Fn);
//    return 0;
//}

//#include <stdio.h>
//#include <math.h>
//int main ()
//{
//    int a,b,c;
//    scanf("%d %d %d", &a, &b, &c);
//    double max,area,circumference;//定义最大边，面积，周长
//    if (a >= b && a >= c){
//        max = a;
//    }else if (b >= a && b >= c){
//        max = b;
//    }else{
//        max = c;
//    }
//    circumference = 2 * M_PI * max;
//    area = M_PI * max * max;
//    printf("最大圆的周长为：%.2f\n", circumference);
//    printf("最大圆的面积为：%.2f\n", area);
//    return 0;
//}

//#include <stdio.h>
//#include <math.h>
//
//int main()
//{
//   double a, b, c, s, area;
//
//   printf("请输入三角形的三边长: ");
//   scanf("%lf %lf %lf", &a, &b, &c);
//
//   if (a + b > c && a + c > b && b + c > a){
//       s = (a + b + c) / 2.0;
//       area = sqrt(s * (s - a) * (s - b) * (s - c));
//       printf("三角形的面积为: %.2f\n", area);
//   }
//   else{
//       printf("输入的三边不能构成三角形。\n");
//   }
//   return 0;
//}

//#include <stdio.h>
//int main()
//{
//    int budget[12];
//    int money = 0;
//    int save_money = 0;
//    int month = 0;
//    for (month = 0; month < 12; month++){
//        scanf("%d\n", &budget[month]);
//    }
//    for (month = 0;month < 12; month++){
//        money += 300;
//        if (money < budget[month]){
//            printf("-%d",month + 1);
//            return 0;
//        }
//        money -= budget[month];
//        int to_save = money / 100 * 100;
//        save_money += to_save;
//        money -= to_save;
//    }
//    int total_save = save_money * 1.2 + money;
//    printf("%d\n", total_save);
//    return 0;
//}

//#include <stdio.h>
//#include <string.h>
//
//int main()
//{
//    char number[10];
//
//    scanf("%s", number);
//
//    char *dot = strchr(number, '.');
//    if (dot == NULL) {
//        return 1;
//    }
//
//    int integerPartLength = dot - number;
//    int decimalPartLength = strlen(dot + 1);
//
//    char reversed[10];
//    int pos = 0;
//
//    for (int i = decimalPartLength - 1; i >= 0; i--) {
//        reversed[pos++] = dot[i + 1]; // +1 to skip the dot
//    }
//
//    reversed[pos++] = '.';
//    for (int i = integerPartLength - 1; i >= 0; i--) {
//        reversed[pos++] = number[i];
//    }
//
//    reversed[pos] = '\0';
//    printf("%s\n", reversed);
//    return 0;
//}

//#include <stdio.h>
//
//int main()
//{
//    int s, v;
//    scanf("%d %d", &s, &v);
//
//    int walkTime = (s + v - 1) / v;
//
//    int totalTime = walkTime + 10;
//
//    int hours = 8;
//    int minutes = 0;
//    minutes -= totalTime;
//    if (minutes < 0) {
//        minutes += 60;
//        hours -= 1;
//    }
//
//    if (hours < 0) {
//        hours += 24;
//    }
//    printf("%02d:%02d\n", hours, minutes);
//    return 0;
//


//#include <stdio.h>
//#include <math.h>
//int main()
//{
//    double s, v;
//    int n, t, a, b;
//    scanf("%lf %lf", &s, &v);
//
//    n = 8 * 60 + 24 * 60;  // 两天总共的分钟数
//    t = ceil(s / v) + 10;  // 向上取整计算行走时间和垃圾分类时间的总和
//    n = n - t;  // 得出剩下的时间
//    if (n >= 24 * 60) {
//        n -= 24 * 60;  // 判断是否在前一天
//    }
//    b = n % 60;  // 得出出发的分钟数
//    a = n / 60;  // 得出出发的小时数
//
//    if (a < 10) {
//        if (b < 10) {
//            printf("0%d:0%d\n", a, b);
//        } else {
//            printf("0%d:%d\n", a, b);
//        }
//    } else {
//        if (b < 10) {
//            printf("%d:0%d\n", a, b);
//        } else {
//            printf("%d:%d\n", a, b);
//        }
//    }
//    return 0;
//}

//#include <stdio.h>
//int main(void)
//{
//    int n;
//    scanf("%d\n", &n);
//    int a[n];
//    for (int i = 0; i < n; i++) {
//        scanf("%d", &a[i]);
//    }
//    int result[n];
//    for (int i = 0; i < n; i++){
//        int count = 0;
//        for (int j = 0; j < i ;j++){
//            if (a[i] > a[j]){
//                count++;
//            }
//        }
//        result[i] = count;
//    }
//    for (int i = 0; i < n; i++){
//        printf("%d ", result[i]);
//        if (i < n - 1){
//            printf("");
//        }
//    }
//    printf("\n");
//    return 0;
//}
// #include <stdio.h>

// #define MAX_SIZE 100  // 数字个数不超过 100

// int main()
// {
//     int numbers[MAX_SIZE];
//     int count = 0;

//     // 读取输入
//     int num;
//     while (scanf("%d", &num) != EOF && num != 0) {
//         numbers[count++] = num;
//     }

//     // 倒序输出
//     for (int i = count - 1; i >= 0; i--) {
//         printf("%d", numbers[i]);
//         if (i > 0) {
//             printf(" ");
//         }
//     }
//     printf("\n");

//     return 0;
// }

//#include <stdio.h>
//#include <math.h>
//
//int main ()
// {
//     int a,b,c;
//     scanf("%d %d %d", &a, &b, &c);
//     double max,area,circumference;//定义最大边，面积，周长
//     if (a >= b && a >= c){
//         max = a;
//     }else if (b >= a && b >= c){
//         max = b;
//     }else{
//         max = c;
//     }
//     circumference = 2 * M_PI * max;
//     area = M_PI * max * max;
//     printf("最大圆的周长为：%.2f\n", circumference);
//     printf("最大圆的面积为：%.2f\n", area);
//     return 0;
// }

//#include <stdio.h>
//void hailstone(int n) {
//    int sequence[100];
//    int index = 0;
//    while (n != 1) {
//        sequence[index++] = n;
//        if (n % 2 == 0) {
//            n /= 2;
//        } else {
//            n = n * 3 + 1;
//        }
//    }
//    sequence[index++] = 1;
//    for (int i = index - 1; i >= 0; i--) {
//        printf("%d ", sequence[i]);
//    }
//    printf("\n");
//}
//int main()
//{
//    int n;
//    scanf("%d", &n);
//    hailstone(n);
//    return 0;
//}

//#include <stdio.h>
//
//void hailstoneConjecture(int n) {
//    int arr[1000000];  // 用于存储变化序列
//    int index = 0;
//
//    while (n!= 1) {
//        arr[index++] = n;
//        if (n % 2 == 0) {
//            n /= 2;
//        } else {
//            n = n * 3 + 1;
//        }
//    }
//    arr[index++] = 1;
//
//    // 倒序输出变化序列
//    for (int i = index - 1; i >= 0; i--) {
//        printf("%d ", arr[i]);
//    }
//    printf("\n");
//}
//
//int main() {
//    int n;
//    scanf("%d", &n);
//    hailstoneConjecture(n);
//    return 0;
//}

//#include <stdio.h>
//int main ()
//{
//    int l,m;
//    scanf("%d %d", &l, &m);
//
//    int remove[l + 1];
//    for (int i = 0; i <= l; i++){
//        remove[i] = 0;
//    }
//    for (int i = 0; i < m; i++){
//        int u,v;
//        scanf("%d %d", &u, &v);
//        for (int j = u; j <= v; j++){
//            remove[j] = 1;
//        }
//    }
//    int count = 0;
//    for (int i = 0;i <= l; i++){
//        if (remove[i] == 0){
//            count++;
//        }
//    }
//    printf("%d\n", count);
//    return 0;
//}


//#include <stdio.h>
//#include <math.h>
//
//int main (){
//    int N;
//    scanf("%d", &N);
//    int arr[N][3];
//    for (int i = 0; i < N; i++){
//        scanf("%d %d %d", &arr[i][0], &arr[i][1], &arr[i][2]);
//    }
//    int count = 0;
//    for(int i = 0; i < N; i++){
//        for(int j = i + 1; j < N; j++){
//            if (abs(arr[i][0] - arr[j][0]) <= 5 &&
//                abs(arr[i][1] - arr[j][1]) <= 5 &&
//                abs(arr[i][2] - arr[j][2]) <= 5){
//                int total1 = arr[i][0] + arr[i][1] + arr[i][2];
//                int total2 = arr[j][0] + arr[j][1] + arr[j][2];
//                if (abs(total1 - total2) <= 10){
//                    count++;
//                }
//            }
//        }
//    }
//    printf("%d\n", count);
//    return 0;
//}

//#include <stdio.h>
//int main (){
//    int w,x,h;
//    scanf("%d %d %d\n", &w, &x, &h);
//    int q;
//    scanf("%d\n", &q);
//    int arr[w + 1][x + 1][h + 1];
//    for (int i = 0; i <= w; i++){
//        for (int j = 0; j <= x; j++){
//            for (int k = 0; k <= h; k++){
//                arr[i][j][k] = 0;
//            }
//        }
//    }
//    for (int i = 0; i < q; i++){
//        int x1,y1,z1,x2,y2,z2;
//        scanf("%d %d %d %d %d %d", &x1, &y1, &z1, &x2, &y2, &z2);
//        for (int j = x1; j <= x2; j++){
//            for (int k = y1; k <= y2; k++){
//                for (int l = z1; l <= z2; l++){
//                    arr[j][k][l] = 1;
//                }
//            }
//        }
//    }
//    int count = 0;
//    for (int i = 1; i <= w; i++){
//        for (int j = 1; j <= x; j++){
//            for (int k = 1; k <= h; k++){
//                if (arr[i][j][k] == 0){
//                    count++;
//                }
//            }
//        }
//    }
//    printf("%d\n", count);
//    return 0;
//}

//#include <stdio.h>
//int main (){
//    int n;
//    scanf("%d", &n);
//    int arr1[7];
//    for (int i = 0; i < 7; i++){
//        scanf("%d", &arr1[i]);
//    }
//    int count[8] = {0};
//    for (int i = 0; i < n; i++){
//        int arr2[7];
//        for (int j = 0; j < 7; j++){
//            scanf("%d", &arr2[j]);
//        }
//        int sum = 0;
//        for (int j = 0; j < 7; j++){
//            for (int k = 0; k < 7; k++){
//                if (arr2[j] == arr1[k]){
//                    sum ++;
//                    break;
//                }
//            }
//        }
//        if (sum >= 1 && sum <= 7){
//            count[7 - sum]++;
//        }
//    }
//    for (int i = 0; i < 7; i++){
//        printf("%d ", count[i]);
//    }
//    return 0;
//}

//#include <stdio.h>
//#include <string.h>
//void countDigits(int num, int *count) {
//   while (num > 0) {
//       int digit = num % 10;
//       count[digit]++;
//       num /= 10;
//   }
//}
//int main() {
//   int M, N;
//   scanf("%d %d", &M, &N);
//   int count[10] = {0};
//   for (int i = M; i <= N; i++) {
//       countDigits(i, count);
//   }
//   for (int i = 0; i < 10; i++) {
//       printf("%d ", count[i]);
//   }
//   printf("\n");
//   return 0;
//}

//#include <stdio.h>
//int main (){
//    int n, m;
//    scanf("%d %d", &n, &m);
//    // 初始化两个变量 h 和 s，初始值为 n
//    double h = n, s = n;
//    // 循环 m 次以更新 h 和 s 的值
//    for (int i = 1; i <= m; ++i) {
//        // 在每次循环中，将 h 的值除以 4,就是每次反弹会减少四分之三的高度
//        h = h / 4;
//        // 如果不是最后一次循环，更新 s 的值，加入一个判段语句，确保最后一次循环时，s 的值不变
//        if (i < m) {
//            // 将 s 的值增加当前 h 值的两倍，每次反弹后距离值就是h的两倍
//            s = s + 2 * h;
//        }
//    }
//    // 打印 s 的值，保留两位小数
//    printf("%.2f\n", s);
//    // 打印 h 的值，保留两位小数
//    printf("%.2f\n", h);
//    return 0;
//}

//#include <stdio.h>
//int main (){
//    int n;
//    scanf("%d", &n);
//    int triangle[20][20];
//    for (int i = 0; i < n; i++){
//        triangle[i][0] = 1;
//        triangle[i][i] = 1;
//    }
//    for (int i = 2; i < n; i++){
//        for (int j = 1; j < i; j++){
//            triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
//        }
//    }
//    for (int i = 0; i < n; i++){
//        for (int j = 0; j <= i; j++){
//            printf("%d ", triangle[i][j]);
//            if (j < i){
//                printf("");
//            }
//        }
//        printf("\n");
//    }
//    return 0;
//}

//#include <stdio.h>
//int main() {
//    int num, reverse = 0;
//    printf("请输入一个正整数 (<100000): ");
//    scanf("%d", &num);
//    while (num != 0) {
//        reverse = reverse * 10 + num % 10;
//        num /= 10;
//    }
//    printf("%d\n", reverse);
//    return 0;
//}

//#include <stdio.h>
//int main() {
//    double e;
//    scanf("%lf", &e);
//    double pi = 1.0;
//    int n = 0;
//    for (n = 1; ; n++) {
//        double term = (2.0 * n / (2.0 * n - 1)) * (2.0 * n / (2.0 * n + 1));
//        pi *= term;
//        double a = pi * 2;
//        if (a >= e) {
//            printf("%.7f %d\n", pi * 2 / term, n - 1);
//            break;
//        }
//    }
//    return 0;
//}

//#include <stdio.h>
//int main (){
//    double x;
//    int n;
//    scanf("%lf %d", &x, &n);
//    double result = 0;
//    double term = x;
//    for (int i = 1; i <= n; i ++){
//        result += term;
//        term = -term * x * x / (2 * i * (2 * i + 1));
//    }
//    printf("%.8f\n", result);
//    return 0;
//}

//#include <stdio.h>
//int main (){
//    double x;
//    int n;
//    scanf("%lf %d", &x, &n);
//    double result = 0.0;
//    double term = 1.0;
//    for (int i = 1; i <= n + 1; i++){
//        result += term;
//        term = -term * x * x / (2 * i * (2 * i - 1));
//    }
//    printf("%.8f\n", result);
//    return 0;
//}

//#include <stdio.h>
//int main() {
//    int N, max, min, num;
//    scanf("%d", &N);
//    scanf("%d", &num);
//    max = num;
//    min = num;
//    for (int i = 1; i < N; i++) {
//        scanf(" %d", &num);
//        if (num > max) {
//            max = num;
//        }
//        if (num < min) {
//            min = num;
//        }
//    }
//    printf("%d %d\n", max, min);
//    return 0;
//}

//#include <stdio.h>
//#include <ctype.h>
//int main (){
//    char s[101];
//    scanf("%s", s);
//    for (int i = 0; s[i] != '\0'; i++){
//        if (islower(s[i])){
//            s[i] = toupper(s[i]);
//        }
//    }
//    printf("%s\n", s);
//    return 0;
//}

//#include <stdio.h>
//int main (){
//    int n;
//    char s[51];
//    scanf("%d", &n);
//    scanf("%s", s);
//    for (int i = 0; s[i] != '\0'; i++){
//        s[i] = ((s[i] - 'a' + n) % 26) + 'a';
//    }
//    printf("%s\n", s);
//    return 0;
//}

//#include <stdio.h>
//#include <ctype.h>
//int main (){
//    char s[101];
//    int count = 0;
//    gets(s, 101, stdin);
//    for (int i = 0; s[i] != '\0'; i++){
//        if (s[i] != ' ' && s[i] != '\n'){
//            count ++;
//        }
//    }
//    printf("%d\n", count);
//    return 0;
//}

//#include <stdio.h>
//#include <stdbool.h>
//bool is_prime(int num) {
//    if (num <= 1) return false;
//    for (int i = 2; i * i <= num; i++) {
//        if (num % i == 0) return false;
//    }
//    return true;
//}
//int main() {
//    char word[101];
//    int count[26] = {0};
//    int maxn = 0, minn = 100;
//    scanf("%s", word);
//    for (int i = 0; word[i] != '\0'; i++) {
//        count[word[i] - 'a']++;
//    }
//    for (int i = 0; i < 26; i++) {
//        if (count[i] > maxn) maxn = count[i];
//        if (count[i] < minn && count[i] > 0) minn = count[i];
//    }
//    int diff = maxn - minn;
//    if (is_prime(diff)) {
//        printf("Lucky Word\n%d\n", diff);
//    } else {
//        printf("No Answer\n0\n");
//    }
//    return 0;
//}


//#include <stdio.h>
//int key_presses[26] = {
//    1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 4, 1, 2, 3, 1, 2, 3, 4
//};
//int main() {
//    char s[201];
//    int total_presses = 0;
//    scanf("%[^\n]", s);
//    for (int i = 0; s[i] != '\0'; i++) {
//        if (s[i] == ' ') {
//            total_presses += 1;
//        } else {
//            total_presses += key_presses[s[i] - 'a'];
//        }
//    }
//    printf("%d\n", total_presses);
//    return 0;
//}

//#include <stdio.h>
//int main() {
//    int N;
//    scanf("%d", &N);
//    int numbers[10000];
//    int count[10000] = {0};
//    for(int i = 0; i < N; i++) {
//        scanf("%d", &numbers[i]);
//        for(int j = 0; j <= i; j++) {
//            if(numbers[j] == numbers[i]) {
//                count[j]++;
//                break;
//            }
//        }
//    }
//    int maxCount = 0;
//    int x = 0;
//    for(int i = 0; i < N; i++) {
//        if(count[i] > maxCount) {
//            maxCount = count[i];
//            x = i;
//        }
//    }
//    printf("%d\n", numbers[x]);
//    return 0;
//}


//#include <stdio.h>
//#define MAXN 2000001
//int lights[MAXN];
//int main() {
//    int n;
//    scanf("%d", &n);
//    while(n--) {
//        double a;
//        int t;
//        scanf("%lf %d", &a, &t);
//        // 直接用乘法累加，避免每次计算floor
//        double curr = a;
//        for(int i = 1; i <= t; i++) {
//            lights[(int)curr]^= 1;  // 使用异或运算
//            curr += a;
//        }
//    }
//    // 找出值为1的位置
//    for(int i = 1; i < MAXN; i++) {
//        if(lights[i]) {
//            printf("%d\n", i);
//            break;
//        }
//    }
//    return 0;
//}

//#include <stdio.h>
//
//int main() {
//    int n, m;
//    int a[3001];
//    scanf("%d %d", &n, &m);
//    for(int i = 0; i < n; i++) {
//        scanf("%d", &a[i]);
//    }
//    if(m == 0) {
//        printf("0\n");
//        return 0;
//    }
//    int sum = 0;
//    for(int i = 0; i < m; i++) {
//        sum += a[i];
//    }
//    int min_sum = sum;
//    for(int i = m; i < n; i++) {
//        sum = sum - a[i-m] + a[i];
//        if(sum < min_sum) {
//            min_sum = sum;
//        }
//    }
//    printf("%d\n", min_sum);
//    return 0;
//}

//#include <stdio.h>
//int main () {
//    int n;
//    int arr[10][10] = {0};
//    scanf("%d", &n);
//    int num = 1;
//    int left = 0, right = n - 1, top = 0, bottom = n - 1;
//    while (num <= n * n) {
//        for (int i = left; i <= right; i++) {
//            arr[top][i] = num++;
//        }
//        top++;
//        for (int i = top; i <= bottom; i++) {
//            arr[i][bottom] = num++;
//        }
//        right--;
//        for (int i = right; i >= left; i--) {
//            arr[bottom][i] = num++;
//        }
//        bottom--;
//        for (int i = bottom; i >= top; i--) {
//            arr[i][left] = num++;
//        }
//        left++;
//    }
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < n; j++) {
//            printf("%3d", arr[i][j]);
//        }
//        printf("\n");
//    }
//    return 0;
//}

//#include <stdio.h>
//int main () {
//    int n,count = 0;
//    int nums[100];
//    scanf("%d",&n);
//    for (int i = 0; i < n; i++) {
//        scanf("%d",&nums[i]);
//    }
//    for (int i = 0; i < n; i++) {
//        int a = nums[i];
//        int found = 0;
//        for (int j = 0; j < n && !found; j++) {
//            if (j == i) continue;
//            for (int k = j + 1; k < n && !found; k++) {
//                if (i == k) continue;
//                if (nums[j] + nums[k] == a) {
//                    found = 1;
//                    count++;
//                }
//            }
//        }
//    }
//    printf("%d\n",count);
//    return 0;
//}

//#include <stdio.h>
//int n, m, k;
//int light[101][101];
//void placeTorch(int x, int y) {
//    light[x][y] = 1;
//    if(x-1 > 0) light[x-1][y] = 1;
//    if(x+1 <= n) light[x+1][y] = 1;
//    if(y-1 > 0) light[x][y-1] = 1;
//    if(y+1 <= n) light[x][y+1] = 1;
//    if(x-1 > 0 && y-1 > 0) light[x-1][y-1] = 1;
//    if(x-1 > 0 && y+1 <= n) light[x-1][y+1] = 1;
//    if(x+1 <= n && y-1 > 0) light[x+1][y-1] = 1;
//    if(x+1 <= n && y+1 <= n) light[x+1][y+1] = 1;
//    if(x-2 > 0) light[x-2][y] = 1;
//    if(x+2 <= n) light[x+2][y] = 1;
//    if(y-2 > 0) light[x][y-2] = 1;
//    if(y+2 <= n) light[x][y+2] = 1;
//}
//// 放置萤石
//void placeGlowstone(int x, int y) {
//    for(int i = x-2; i <= x+2; i++)
//        for(int j = y-2; j <= y+2; j++)
//            if(i > 0 && i <= n && j > 0 && j <= n)
//                light[i][j] = 1;
//}
//int main() {
//    int x, y, count = 0;
//    scanf("%d %d %d", &n, &m, &k);
//    for(int i = 0; i < m; i++) {
//        scanf("%d %d", &x, &y);
//        placeTorch(x, y);
//    }
//    for(int i = 0; i < k; i++) {
//        scanf("%d %d", &x, &y);
//        placeGlowstone(x, y);
//    }
//    for(int i = 1; i <= n; i++)
//        for(int j = 1; j <= n; j++)
//            if(!light[i][j]) count++;
//    printf("%d\n", count);
//    return 0;
//}

//#include <stdio.h>
//int main() {
//    int N, num;
//    char matrix[201][201];
//    int x = 0, y = 0;
//    char current = '0';
//    scanf("%d", &N);
//    while(scanf("%d", &num) == 1) {
//        for(int i = 0; i < num; i++) {
//            matrix[x][y] = current;
//            y++;
//            if(y == N) {
//                y = 0;
//                x++;
//            }
//        }
//        current = (current == '0') ? '1' : '0';
//    }
//    for(int i = 0; i < N; i++) {
//        matrix[i][N] = '\0';
//        printf("%s\n", matrix[i]);
//    }
//    return 0;
//}

//#include <stdio.h>
//#include <string.h>
//#include <ctype.h>
//#define MAXN 1000001
//void toLowerCase(char *str) {
//    for (int i = 0; str[i]; i++) {
//        str[i] = tolower(str[i]);
//    }
//}
//int isLetter(char c) {
//    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
//}
//int main () {
//    char word[11],article[MAXN];
//    char temp[11];
//    int count = 0,firstPos = -1,wordlen,articlelen;
//    scanf("%s",word);
//    getchar();
//    fgets(article, MAXN, stdin);
//    toLowerCase(word);
//    wordlen = strlen(word);
//    articlelen = strlen(article);
//    int i = 0;
//    while (i < articlelen) {
//        while (i < articlelen && !isLetter(article[i])) i++;
//        if (i >= articlelen) break;
//        int j = 0;
//        int start = i;
//        while (i < articlelen && isLetter(article[i])) {
//            temp[j++] = tolower(article[i++]);
//        }
//        temp[j] = '\0';
//        if (j == wordlen && strcmp(temp, word) == 0) {
//            count++;
//            if (firstPos == -1) firstPos = start;
//        }
//    }
//    if (count > 0) {
//        printf("%d %d\n", count, firstPos);
//    } else {
//        printf("-1");
//    }
//    return 0;
//}

//#include <stdio.h>
//int main() {
//    int n, m, q;
//    scanf("%d %d %d", &n, &m, &q);
//    int monkeys[100] = {0};
//    for(int i = 0; i < n; i++) {
//        monkeys[i] = 1;
//    }
//    int count = n;
//    int pos = q - 1;
//    while(count > 1) {
//        int step = m;
//        while(step > 0) {
//            if(monkeys[pos]) {
//                step--;
//                if(step == 0) break;
//            }
//            pos = (pos + 1) % n;
//        }
//        monkeys[pos] = 0;
//        count--;
//        do {
//            pos = (pos + 1) % n;
//        } while(!monkeys[pos] && count > 0);
//    }
//    for(int i = 0; i < n; i++) {
//        if(monkeys[i]) {
//            printf("%d\n", i + 1);
//            break;
//        }
//    }
//    return 0;
//}

//#include <stdio.h>
//#include <math.h>
//double distance(double x1, double y1, double x2, double y2) {
//    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
//}
//int main() {
//    double x1, y1, x2, y2, x3, y3;
//    scanf("%lf %lf", &x1, &y1);
//    scanf("%lf %lf", &x2, &y2);
//    scanf("%lf %lf", &x3, &y3);
//
//    double dis1 = distance(x1, y1, x2, y2);
//    double dis2 = distance(x2, y2, x3, y3);
//    double dis3 = distance(x3, y3, x1, y1);
//
//    double perimeter = dis1 + dis2 + dis3;
//    printf("%.2lf\n", perimeter);
//
//    return 0;
//}


//#include <stdio.h>
//#include <stdbool.h>
//int isPrime(int num) {
//    if (num <= 1)
//        return false;
//    for (int i = 2; i * i <= num; i++) {
//        if (num % i == 0)
//            return 0;
//    }
//    return 1;
//}
//int main() {
//    int n;
//    scanf("%d", &n);
//    int arr[100];
//    for (int i = 0; i < n; i++) {
//        scanf("%d", &arr[i]);
//    }
//    for (int i = 0; i < n; i++) {
//        if (isPrime(arr[i])) {
//            printf("%d ", arr[i]);
//        }
//    }
//    printf("\n");
//    return 0;
//}

//#include <stdio.h>
//#include <stdbool.h>
//bool isLeapYear(int year) {
//    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
//}
//int main() {
//    int x, y;
//    scanf("%d %d", &x, &y);
//    int count = 0;
//    for (int year = x; year <= y; year++) {
//        if (isLeapYear(year)) {
//            count++;
//        }
//    }
//    printf("%d\n", count);
//    for (int year = x; year <= y; year++) {
//        if (isLeapYear(year)) {
//            printf("%d ", year);
//        }
//    }
//    printf("\n");
//    return 0;
//}


//#include <stdio.h>
//#define MAX_M 20
//int main() {
//    int n, m;
//    scanf("%d %d", &n, &m);
//    double maxAvgScore = 0.0;
//    for (int i = 0; i < n; i++) {
//        int scores[MAX_M];
//        for (int j = 0; j < m; j++) {
//            scanf("%d", &scores[j]);
//        }
//        int minScore = scores[0], maxScore = scores[0];
//        double sum = 0.0;
//        for (int j = 0; j < m; j++) {
//            if (scores[j] < minScore) {
//                minScore = scores[j];
//            }
//            if (scores[j] > maxScore) {
//                maxScore = scores[j];
//            }
//            sum += scores[j];
//        }
//        double avgScore = (sum - minScore - maxScore) / (m - 2);
//        if (avgScore > maxAvgScore) {
//            maxAvgScore = avgScore;
//        }
//    }
//    printf("%.2lf\n", maxAvgScore);
//    return 0;
//}

//#include <stdio.h>
//#include <string.h>
//struct Student {
//    char name[9];
//    int chinese;
//    int math;
//    int english;
//    int sum;
//};
//int main () {
//    int n;
//    scanf("%d", &n);
//    struct Student best;
//    best.sum = -1;
//    for (int i = 0; i < n; i++) {
//        struct Student current;
//        scanf("%s %d %d %d", current.name, &current.chinese, &current.math, &current.english);
//        current.sum = current.chinese + current.math + current.english;
//        if (current.sum > best.sum) {
//            best = current;
//        }
//    }
//    printf("%s %d %d %d", best.name, best.chinese, best.math, best.english);
//    return 0;
//}

//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//
//struct Student {
//    char name[9];
//    int chinese;
//    int math;
//    int english;
//    int sum;
//};
//
//int isMatch(struct Student s1, struct Student s2) {
//    if (abs(s1.chinese - s2.chinese) > 5) return 0;
//    if (abs(s1.math - s2.math) > 5) return 0;
//    if (abs(s1.english - s2.english) > 5) return 0;
//    if (abs(s1.sum - s2.sum) > 10) return 0;
//    return 1;
//}
//
//int main() {
//    int n;
//    scanf("%d", &n);
//    struct Student students[10000];
//    for (int i = 0; i < n; i++) {
//        scanf("%s %d %d %d", students[i].name, &students[i].chinese, &students[i].math, &students[i].english);
//        students[i].sum = students[i].chinese + students[i].math + students[i].english;
//    }
//    for (int i = 0; i < n; i++) {
//        for (int j = i + 1; j < n; j++) {
//            if (isMatch(students[i], students[j])) {
//                if (strcmp(students[i].name, students[j].name)) {
//                    printf("%s %s\n", students[i].name, students[j].name);
//                } else {
//                    printf("%s %s\n", students[j].name, students[i].name);
//                }
//            }
//        }
//    }
//    return 0;
//}

//#include <stdio.h>
//
//struct Student {
//    int id;// 学号
//    int academic;// 学业成绩（70%）
//    int quality;// 素质拓展成绩（30%）
//    double composite;// 综合成绩
//};
//
//int getTotal(struct Student s) {
//    return s.academic + s.quality;
//}
//
//int isExcellent(struct Student s) {
//    if (getTotal(s) <= 140) return 0;
//    if (s.academic *7 + s.quality * 3 < 800) return 0;
//    return 1;
//}
//
//int main() {
//    int n;
//    scanf("%d", &n);
//    struct Student students[1000];
//    for (int i = 0; i < n; i++) {
//        scanf("%d %d %d", &students[i].id, &students[i].academic, &students[i].quality);
//        students[i].composite = (students[i].academic * 0.7 + students[i].quality * 0.3);
//    }
//    for (int i = 0; i < n; i++) {
//        if (isExcellent(students[i])) {
//            printf("Excellent\n");
//        } else {
//            printf("Not excellent\n");
//        }
//    }
//    return 0;
//}

//#include <stdio.h>
//#include <math.h>
//
//int isPrime(int n) {
//    if (n <= 1)
//        return 0;
//    for (int i = 2; i * i <= n; i++) {
//        if (n % i == 0) return 0;
//    }
//    return 1;
//}
//
//int findLargePrime(int n) {
//    int sqrtn = sqrt(n);
//    for (int i = 2; i <= sqrtn; i++) {
//        if (n % i == 0) {
//            if (isPrime(i) && isPrime(n / i)) {
//                return (n / i > i) ? n / i : i;
//            }
//        }
//    }
//    return n;
//}
//
//int main () {
//    int n;
//    scanf("%d", &n);
//    int result = findLargePrime(n);
//    printf("%d\n", result);
//    return 0;
//}

//#include <stdio.h>
//
//int isPrime(int n) {
//    if (n <= 1)
//        return 0;
//    for (int i = 2; i * i <= n; i++) {
//        if (n % i == 0) return 0;
//    }
//    return 1;
//}
//
//void findPrimePair(int n) {
//    for (int i = 2; i <= n / 2; i++) {
//        if (isPrime(i) && isPrime(n - i)) {
//            printf("%d=%d+%d\n",n, i, n - i);
//            return;
//        }
//    }
//}
//
//int main () {
//    int N;
//    scanf("%d", &N);
//    for (int i = 4; i <= N; i += 2) {
//        findPrimePair(i);
//    }
//    return 0;
//}

//#include <stdio.h>
//#include <math.h>
//
//int isPrime(int n) {
//    if (n <= 1)
//        return 0;
//    for (int i = 2; i * i <= n; i++) {
//        if (n % i == 0) return 0;
//    }
//    return 1;
//}
//
//int makePalindrome(int len, int val) {
//    int res = val;
//    if(len % 2) val /= 10;
//    while(val) {
//        res = res * 10 + val % 10;
//        val /= 10;
//    }
//    return res;
//}
//
//void solve(int a, int b) {
//    for(int i = 5; i <= 9; i += 2)
//        if(i >= a && i <= b && isPrime(i))
//            printf("%d\n", i);
//    for(int len = 2; len <= 8; len++) {
//        int start = pow(10, (len-1)/2);
//        int end = pow(10, (len+1)/2);
//        for(int i = start; i < end; i++) {
//            int pal = makePalindrome(len, i);
//            if(pal >= a && pal <= b && isPrime(pal))
//                printf("%d\n", pal);
//        }
//    }
//}
//int main () {
//    int a, b;
//    scanf("%d %d", &a, &b);
//    solve(a, b);
//    return 0;
//}

//#include <stdio.h>
//
//int main () {
//    int n;
//    scanf("%d", &n);
//    int peaches = 1;
//    for (int i = 1; i < n; i++) {
//        peaches = (peaches + 1) * 2;
//    }
//    printf("%d\n", peaches);
//    return 0;
//}

//#include <stdio.h>
//
//struct Student {
//    char name[20];
//    int age;
//    int score;
//};
//
//struct Student train(struct Student s) {
//    struct Student new_s = s;
//    new_s.age ++;
//    int new_score = s.score * 1.2;
//    new_s.score = new_score > 600 ? 600 : new_score;
//    return new_s;
//}
//
//int main () {
//    int n;
//    scanf("%d", &n);
//    struct Student students[5];
//    for (int i = 0; i < n; i++) {
//        scanf("%s %d %d", students[i].name, &students[i].age, &students[i].score);
//    }
//    for (int i = 0; i < n; i++) {
//        struct Student new_s = train(students[i]);
//        printf("%s %d %d\n", new_s.name, new_s.age, new_s.score);
//    }
//    return 0;
//}

//#include <stdio.h>
//
//int main() {
//    int x;
//    long long sum = 0;
//    int count = 0;
//    while(scanf("%d", &x) == 1) {
//        sum += x;
//        count++;
//        char c = getchar();
//        if(c == '\n') break;
//    }
//    sum *= (1LL << (count-1));
//    printf("%lld", sum);
//    return 0;
//}

//#include <stdio.h>
//#include <string.h>
//
//int main () {
//    int a = 0, b = 0,c = 0;
//    char s[256];
//    gets(s);
//    int len = strlen(s);
//    for (int i = 0; i < len; i++) {
//        char ch = s[i];
//        if (ch != 'a' && ch != 'b' && ch != 'c') continue;
//        i += 2;
//        char value = s[i + 1];
//        int num;
//        if (value >= '0' && value <= '9') {
//            num = value - '0';
//        } else {
//            switch (value) {
//                case 'a':num = a; break;
//                case 'b':num = b; break;
//                case 'c':num = c; break;
//            }
//        }
//        switch (ch) {
//            case 'a':a = num; break;
//            case 'b':b = num; break;
//            case 'c':c = num; break;
//        }
//        i += 2;
//    }
//    printf("%d %d %d", a, b, c);
//    return 0;
//}

//#include <stdio.h>
//#include <string.h>
//
//int countVK(char *s,int n) {
//    int count = 0;
//    for (int i = 0; i < n - 1; i++) {
//        if (s[i] == 'V' && s[i+1] == 'K') count ++;
//    }
//    return count;
//}
//int main () {
//    int n;
//    char s[105];
//    scanf("%d", &n);
//    scanf("%s", s);
//    int maxCount = countVK(s, n);
//    for (int i = 0; i < n; i++) {
//        char ch = s[i];
//        if (s[i] != 'V') {
//            s[i] = 'V';
//            int count = countVK(s, n);
//            if (count > maxCount) maxCount = count;
//        }
//        s[i] = 'K';
//        if (ch != 'K') {
//            int count = countVK(s, n);
//            if (count > maxCount) maxCount = count;
//        }
//        s[i] = ch;
//    }
//    printf("%d\n", maxCount);
//    return 0;
//}

//#include <stdio.h>
//int main () {
//    int n,term;
//    scanf("%d", &n);
//    long long sum = 0;
//    int a = 2;
//    for(int i = 1; i <= n; i++) {
//        term = term * 10 + a;
//        sum += term;
//    }
//    printf("%lld", sum);
//    return 0;
//}

//#include <stdio.h>
//int main () {
//    int a,b,c;
//    int sum1 = 18,sum2 = 118,sum3 = 20;
//    for (a = 0; a <= sum1; a++) {
//        for (b = 0; b <= sum2; b++) {
//            c = sum1 - a - b;
//            if (8 * a + 6 * b + 6 * c == sum2 && 2 * b + c == sum3) {
//                printf("蜘蛛：%d只，蜻蜓：%d只，蝉：%d只\n", a, b, c);
//            }
//        }
//    }
//    return 0;
//}

//#include <stdio.h>
//int main () {
//    int n;
//    scanf("%d", &n);
//    long long fib[20] = {1, 1};
//    for (int i = 2; i < n; i++) {
//        fib[i] = fib[i-1] + fib[i-2];
//    }
//    printf("%lld", fib[n-1]);
//    return 0;
//}

//#include <stdio.h>
//
//int DigitBit(char str[]) {
//    int bit = 0;
//    for (int i = 0; str[i] != '\0'; i++) {
//        if (str[i] >= '0' && str[i] <= '9') {
//            bit ++;
//        }
//    }
//    return bit;
//}
//
//void DigitCount(char a[]) {
//    int number[10] = {0},i = 0;
//    while (a[i] != '\0') {
//        int k = (int)a[i] - 48;
//        if (k >= 0 && k <= 9) number[k]++;
//        i++;
//    }
//    for(int j = 0; j < 10; j++) {
//        if (number[j] != 0) printf("%d: %d\n",j,number[j]);
//    }
//    return;
//}
//
//int main () {
//    char s[81];
//    printf("Input a number：");
//    scanf("%s", s);
//    printf("%d bits\n", DigitBit(s));
//    DigitCount(s);
//    return 0;
//}

//#include <stdio.h>
//#include <string.h>
//
//void removeDigits(char* num, int n) {
//    int len = strlen(num);
//    char stack[250];
//    int top = 0;
//    int remain = len - n;  // 需要保留的位数
//    // 使用单调栈的思想
//    for (int i = 0; i < len; i++) {
//        // 当栈不为空，且还可以删除数字，且当前数字小于栈顶数字时，删除栈顶
//        while (top > 0 && n > 0 && stack[top-1] > num[i]) {
//            top--;
//            n--;
//        }
//        // 将当前数字入栈
//        if (top < remain) {
//            stack[top++] = num[i];
//        } else {
//            n--;  // 如果栈已满，当前数字必须被删除
//        }
//    }
//    stack[top] = '\0';
//    printf("%s\n", stack);
//}
//
//int main() {
//    char num[250];
//    int n;
//    scanf("%s", num);
//    scanf("%d", &n);
//    removeDigits(num, n);
//    return 0;
//}

//#include <stdio.h>
//#include <string.h>
//
//void removeDigits(char* num, int n) {
//    int len = strlen(num);
//    int remain = len - n;  // 需要保留的位数
//    char result[250];
//    int pos = 0;  // 当前处理到的位置
//    // 每次选择一个数字放入结果中
//    for (int i = 0; i < remain; i++) {
//        char min = '9';
//        int minPos = pos;
//        // 在当前位置到最远可以查找的位置间找最小的数
//        // 最远可以查找的位置 = 原串长度 - 还需要的数字个数
//        int canSearch = len - (remain - i);
//        for (int j = pos; j <= canSearch; j++) {
//            if (num[j] < min) {
//                min = num[j];
//                minPos = j;
//            }
//        }
//        // 将找到的数字放入结果
//        result[i] = min;
//        pos = minPos + 1;
//    }
//    result[remain] = '\0';
//    printf("%s\n", result);
//}
//
//int main() {
//    char num[250];
//    int n;
//    scanf("%s", num);
//    scanf("%d", &n);
//    removeDigits(num, n);
//    return 0;
//

//#include <stdio.h>
//
//int hasUniqueDigits(int num1, int num2, int num3) {
//    int digits[10] = {0};
//    while(num1 > 0) {
//        if(++digits[num1 % 10] > 1) return 0;
//        num1 /= 10;
//    }
//    while(num2 > 0) {
//        if(++digits[num2 % 10] > 1) return 0;
//        num2 /= 10;
//    }
//    while(num3 > 0) {
//        if(++digits[num3 % 10] > 1) return 0;
//        num3 /= 10;
//    }
//    return 1;
//}
//
//int main() {
//    int num1, num2, num3;
//    for(num3 = 100; num3 <= 333; num3++) {
//        num1 = num3 * 3;
//        num2 = num3 * 2;
//        if(num1 >= 300 && num1 <= 999 && num2 >= 200 && num2 <= 666) {
//            if(hasUniqueDigits(num1, num2, num3)) {
//                printf("%d,%d,%d\n", num1, num2, num3);
//            }
//        }
//    }
//    return 0;
//}

//#include <stdio.h>
//#include <string.h>
//
//int main () {
//    char s1[101],s2[101];
//    scanf("%s\n%s", s1, s2);
//    int len1 = strlen(s1);
//    int len2 = strlen(s2);
//    int count = 0;
//    int flag = -1;
//    for (int i = 0; i <= len1 - len2; i++) {
//        int match = 1;
//        for (int j = 0; j < len2; j++) {
//            if (s1[i+j] != s2[j]) {
//                match = 0;
//                break;
//            }
//        }
//        if (match) {
//            count++;
//            flag = i;
//        }
//    }
//    int before = (flag >= 0) ? flag : 0;
//    printf("%d,%d", count, before);
//    return 0;
//}

//#include <stdio.h>
//
//void WriteStr(char *fn, char *str) {
//    FILE *fp;
//    fp = fopen(fn, "w");
//    fputs(str, fp);
//    fclose(fp);
//}
//int main () {
//    WriteStr("t1.dat","start");
//    WriteStr("t1.dat","end");
//    return 0;
//}

//#include <stdio.h>
//struct st {
//    int x;
//    int *y;
//}*p;
//int dt[4] = {10, 20, 30, 40};
//struct st stMatrix[4] = {50, &dt[0], 60, &dt[1], 70, &dt[2], 80, &dt[3]};
//int main () {
//    p = stMatrix;
//    printf("%d,%d\n", ++(p->x), *((p+2)->y));
//    return 0;
//}

//#include <stdio.h>
//#include <math.h>
//int main () {
//    int n = 1, count = 1;
//    double x;
//    double sum, term;
//    printf("Input x:");
//    scanf("%lf", &x);
//    sum = x;
//    term = x;
//    while (fabs(term) >= 1e-5) {
//        term = -term * x * x / (2 * n) / (2 * n + 1);
//        sum += term;
//        n++;
//        count++;
//    }
//    printf("sin(%lf)=%lf\n", x, sum);
//    printf("count=%d\n", count);
//    return 0;
//}

//#include <stdio.h>
//
//int Gcd (int a, int b) {
//    if (a % b == 0) return b;
//    return Gcd(b, a % b);
//}
//
//int main () {
//    int a, b, gcd;
//    scanf("%d %d", &a, &b);
//    gcd = Gcd(a, b);
//    printf("%d,%d\n", a / gcd, b / gcd);
//    return 0;
//}

//#include <stdio.h>
//int DayTab[2][13] = {
//    {0,31,28,31,30,31,30,31,31,30,31,30,31},
//    {0,31,29,31,30,31,30,31,31,30,31,30,31}
//};
//int DayofYear(int year, int month, int day) {
//    int i, leap;
//    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
//    for (i = 1; i < month; i++) {
//        day += DayTab[leap][i];
//    }
//    return day;
//}//计算某年某月某日是该年的第几天
//
//int main () {
//    int year, month, day;
//    scanf("%d %d %d", &year, &month, &day);
//    printf("%d\n", DayofYear(year, month, day));
//    return 0;
//}

//#include <stdio.h>
//void splitflaot(float x, float *fracpart) {
//    int intpart = (int)x;
//    *fracpart = x - intpart;
//}
//
//int main () {
//    float x, temp;
//    printf("Input 3 nums:");
//    for (int i = 0; i < 3; i++) {
//        scanf("%f", &x);
//        splitflaot(x, &temp);
//        printf("fracpart=%5.4f\n",temp);
//    }
//}

//#include <stdio.h>
//#include <string.h>
//
//int main() {
//    char s[101];
//    gets(s);
//    // 如果已经是科学计数法格式，直接输出
//    if(strchr(s, 'e') != NULL) {
//        printf("%s", s);
//        return 0;
//    }
//    double num;
//    sscanf(s, "%lf", &num);
//    // 计算指数
//    int exp = 0;
//    while(num >= 10) {
//        num /= 10;
//        exp++;
//    }
//    while(num < 1) {
//        num *= 10;
//        exp--;
//    }
//    printf("%.5ge%d", num, exp);
//    return 0;
//}

//#include <stdio.h>
//
//void expand(char s1[], char s2[]) {
//    int i = 0, j = 0;
//    // 直接复制第一个字符
//    s2[j++] = s1[i++];
//    while (s1[i]) {
//        // 如果当前字符是连字符且前后都有字符
//        if (s1[i] == '-' && s1[i+1] && i > 0) {
//            char prev = s1[i-1];  // 前一个字符
//            char next = s1[i+1];  // 后一个字符
//            // 只有当前一个字符小于后一个字符时才展开
//            if (prev < next) {
//                // 从prev的下一个字符开始展开到next
//                for (char c = prev + 1; c <= next; c++) {
//                    s2[j++] = c;
//                }
//                i += 2;  // 跳过连字符和后面的字符
//            } else {
//                // 不是有效范围，直接复制连字符
//                s2[j++] = s1[i++];
//            }
//        } else {
//            // 不是连字符，直接复制
//            s2[j++] = s1[i++];
//        }
//    }
//    s2[j] = '\0';
//}
//
//int main() {
//    char s1[101], s2[101];
//    gets(s1);
//    expand(s1, s2);
//    printf("%s\n", s2);
//    return 0;
//}

//#include <stdio.h>
//
//int fun (char *s) {
//    char *p = s;
//    while (*p++);
//    return p - s - 1;
//}
//
//int main () {
//    char s[100];
//    gets(s);
//    printf("%d\n", fun(s));
//    return 0;
//}

//#include <stdio.h>
//int main () {
//    int n = 60, i;
//    printf("%d = ", n);
//    for (i = 2; i < n; i++) {
//        if (n % i == 0) {
//            printf("%d * ", i);
//            n /= i;
//            i--;
//        }
//    }
//    printf("%d", n);
//}

//#include <stdio.h>
//int main () {
//    char c1, c2, c3, c4, c5, c6;
//    scanf("%c%c%c%c", &c1, &c2, &c3, &c4);
//    c5 = getchar();
//    c6 = getchar();
//    putchar(c1);
//    putchar(c2);
//    printf("%c%c\n", c5, c6);
//    return 0;
//}

//#include <stdio.h>
//int main () {
//    char k;
//    while ((k = getchar()) != '\n') {
//        switch (k) {
//            case '1':
//                k = k + 1;
//                putchar(k);
//            case '2':
//                k = k + 2;
//                putchar(k);
//            default:
//                k = k - 1;
//                putchar(k);
//        }
//    }
//    return 0;
//}

//#include <stdio.h>
//char *fun(char *str) {
//    return str = "fun";
//}
//int main () {
//    char *str = "ction";
//    printf("%s,%c\n", fun(str) + 1, *fun(str) + 1);
//    return 0;
//}

//#include <stdio.h>
//#include <string.h>
//
//void changeStr(char *str) {
//    str[0] = 'H';
//}
//char* getStr() {
//    return "Hello";
//}
//void combineStr(char *dest, char *src) {
//    while (*dest) dest++;
//    while (*src) *dest++ = *src++;
//    *dest = '\0';
//}
//void reverseStr(char *str) {
//    char *end = str;
//    char temp;
//    while (*end) end++;
//    end--;
//    while (str < end) {
//        temp = *str;
//        *str++ = *end;
//        *end-- = temp;
//    }
//}
//char* findChar(char *str, char ch) {
//    while (*str) {
//        if (*str == ch) return str;
//        str++;
//    }
//    return NULL;
//}
//int main () {
//    char s1[20] = "hello";
//    char s2[20] = "world";
//    strlen(s1);//5
//    strcpy(s1, s2);//s1 = "world"
//    strcat(s1, s2);//s1 = "worldworld"
//    strcmp(s1, s2);//0
//    changeStr(s1);//s1 = "Hello"
//    printf("%s\n", getStr());//Hello
//    combineStr(s1, s2);//s1 = "Helloworld"
//    reverseStr(s1);//s1 = "dlrowolleH"
//    printf("%s\n", findChar(s1, 'o'));//olleH
//}

//#include <stdio.h>
//int getCount() {
//    static int count = 0;
//    return ++count;
//}
//int main () {
//    printf("%d\n", getCount());//1
//    printf("%d\n", getCount());//2
//    printf("%d\n", getCount());//3
//    return 0;
//}

//#include <stdio.h>
//#include <malloc.h>
//
//typedef struct {
//    int *data;   // 数据数组
//    int length;   // 当前长度
//    int capacity;  // 最大容量
//} ArrayList;
//// 初始化
//ArrayList* initList(int capacity) {
//    ArrayList *list = (ArrayList*)malloc(sizeof(ArrayList));// 分配内存
//    list->data = (int*)malloc(capacity * sizeof(int));// 分配数据内存
//    list->length = 0;// 长度为0
//    list->capacity = capacity; // 容量
//    return list;// 返回
//}
//// 插入元素
//int insert(ArrayList *list, int index, int element) {
//    if(index < 0 || index > list->length) return 0;// 越界
//    if(list->length >= list->capacity) return 0;// 满了
//
//    for(int i = list->length; i > index; i--) {
//        list->data[i] = list->data[i-1];// 后移
//    }
//    list->data[index] = element;    // 插入
//    list->length++;// 长度加1
//    return 1;
//}
//int main () {
//    ArrayList *list = initList(10);
//    insert(list, 0, 1);
//    insert(list, 1, 2);
//    insert(list, 2, 3);
//    for(int i = 0; i < list->length; i++) {
//        printf("%d ", list->data[i]);
//    }
//    return 0;
//}

//链表
//#include <stdio.h>
//#include <malloc.h>
//typedef struct Node {
//    int data;
//    struct Node *next;
//} Node;
//// 初始化链表
//Node* initList() {
//    Node *head = (Node*)malloc(sizeof(Node));
//    head->next = NULL;
//    return head;
//}
////头插法
//void insertHead(Node *head, int data) {
//    Node *newNode = (Node*)malloc(sizeof(Node));
//    newNode->data = data;
//    newNode->next = head->next;
//    head->next = newNode;
//}
////尾插法
//void insertTail(Node *head, int data) {
//    Node *p = head;
//    while(p->next) {
//        p = p->next;
//    }
//    Node *newNode = (Node*)malloc(sizeof(Node));
//    newNode->data = data;
//    newNode->next = NULL;
//    p->next = newNode;
//}
////遍历
//void traverse(Node *head) {
//    Node *p = head->next;
//    while(p) {
//        printf("%d ", p->data);
//        p = p->next;
//    }
//    printf("\n");
//}
//int main () {
//    Node *head = initList();
//    insertHead(head, 1);
//    insertHead(head, 2);
//    insertHead(head, 3);
//    insertTail(head, 4);
//    insertTail(head, 5);
//    insertTail(head, 6);
//    traverse(head);//3 2 1 4 5 6
//    return 0;
//}

//#include <stdio.h>
//float Fun (int a, int b) {
//    return (a + b);
//}
//int main () {
//    int a = 2, b = 5, c = 8;
//    printf("%3.0f\n", Fun((int) Fun(a+c,b), a-c));// 9
//    return 0;
//}

//#include <stdio.h>
//int main () {
//    char str[100];
//    fgets(str, sizeof(str), stdin);
//    printf("%s", str);
//    return 0;
//}

#include <stdio.h>
int main () {
   char a = 'A';
   int b = 1;
   float c = 2.0;
   double d = 3.0;
   int f = a * b + c - d;// 65 * 1 + 2.0 - 3.0 = 64.0
   char *strArray[] = {"Hello", "World", "C"};
   int count = sizeof(strArray) / sizeof(strArray[0]);// 3
   // 或
   int count2 = sizeof(strArray) / sizeof(char*);// 3
   char *strArray2[] = {"Hello", "World"};
   printf("总大小：%llu\n", sizeof(strArray2));          // 指针数组的大小
   printf("每个元素大小：%llu\n", sizeof(char*));      // 指针的大小
   printf("字符串数量：%llu\n", sizeof(strArray2 )/sizeof(char*)); // 字符串数量
   int *p;
   char *c1;
   double *d1;
   printf("%zu %zu %zu\n", sizeof(p), sizeof(c1), sizeof(d1)); // 8 8 8
}

// #include <stdio.h>
// struct Student {
//    char name[20];
//    int age;
//    double score;
// };
// void modifyStudent(struct Student *s) {
//    s->age = 20;  // 会影响原结构体
// }

// // 调用
// int main () {
//    struct Student s1 = {"Tom", 18, 85.5};
//    modifyStudent(&s1);  // s1的age会变为20
//    printf("%s %d %.1f\n", s1.name, s1.age, s1.score);
//    return 0;
// }

// #include <stdio.h>
// int main () {
//    int x = 1, y = 0, a = 0, b = 0;
//    switch (x) {
//        case 1:
//            switch (y) {
//                case 0:a++;
//                case 1:b++;
//            }
//        case 2:a++;
//               b++;
//    }
//    printf("a=%d,b=%d\n", a, b);
//    return 0;
// }

// #include <stdio.h>
// int main () {
//    int n = 0;
//    for (int i = 2; i < 5; i++) {
//        do {
//            if (n % 3) continue;
//            n++;
//        } while (!i) ;
//        n++;
//    }
//    printf("%d\n", n);
//    return 0;
// }
