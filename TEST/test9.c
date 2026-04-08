//平时练习
//猴子吃桃问题
//#include <stdio.h>
//int main(void)
//{
//    int day,x1,x2;
//    day = 9;
//    x2 = 1;
//    while(day > 0)
//    {
//        x1 = (x2 + 1 ) * 2;
//        x2 = x1;
//        day--;
//    }
//    printf("总共有%d个桃子\n",x1);
//    return 0;
//}

//百钱买百鸡问题
//#include <stdio.h>
//int main(void)
//{
//    int a,b,c;
//    for(a = 0;a <= 20;a++)
//    {
//        for(b = 0;b <= 33;b++)
//        {
//            for(c = 3;c <= 100;c++)
//            {
//                if(a + b + c == 100 && a * 5 + b * 3 + c / 3 == 100)
//                {
//                    if(c % 3 == 0)
//                    {
//                        printf("公鸡%d只，母鸡%d只，小鸡%d只\n",a,b,c);
//                    }
//                }
//            }
//        }
//    }
//    return 0;
//}

//lab 3-1
//#include <stdio.h>
//int main(void)
//{
//    int n;
//    scanf("%d",&n);
//    int sum = 0;
//    int speed = 25;
//    int time = 2;
//    for (int i = 1; i <= n; i++){
//        int distance = speed * time;
//        sum += distance;
//        speed *= 2;
//        time *= 2;
//    }
//    printf("%d\n",sum);
//    return 0;
//}

//lab 3-2
//#include <stdio.h>
//int main(void)
//{
//    int total = 900;
//    int noodles = 160;
//    int orange = 40;
//    int watermelon = 50;
//    int vegetable = 80;
//    for (int i = 1; i <= 10; i++){
//        for (int j = 0; j <= 10; j++){
//            for (int k = 0; k <= 10; k++){
//                for (int s = 0; s <= 10; s++){
//                    if (noodles * i + orange * j + watermelon * k + vegetable * s == total && i + j + k + s <= 10 && (j > 0 || k > 0)){
//                        printf("%d %d %d %d\n",i,j,k,s);
//                    }
//                }
//            }
//        }
//    }
//    return 0;
//}

//lab 3-3
//#include <stdio.h>
//#include <stdlib.h>
//int cai_shu_zi();
//int main(void){
//    unsigned seed;
//    printf("Please input the seed:");
//    scanf("%u",&seed);
//    srand(seed);
//    int magic = rand() % 100 + 1;
//    cai_shu_zi(magic);
//    return 0;
//}
//int cai_shu_zi(int magic){
//    int guess;
//    printf("Guess the nuber:");
//    scanf("%d",&guess);
//    int count = 0;
//    if(guess < 1 || guess > 100){
//        printf("Invalid input,please input again:\n");
//        scanf("%d",&guess);
//        count++;
//    }
//    while(guess != magic){
//        if(guess > magic){
//            printf("Bigger than the answer,guess again:\n");
//            scanf("%d",&guess);
//            count++;
//        }else{
//            printf("Smaller than the answer,guess again:\n");
//            scanf("%d",&guess);
//            count++;
//        }if (count > 5){
//            printf("You are a loser!\n");
//            break;
//        }
//    }while (guess == magic){
//        printf("Correct!\n");
//    }
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
//    circumference = 2 * 3.14 * max;
//    area = 3.14 * max * max;
//    printf("最大圆的周长为：%.2f\n", circumference);
//    printf("最大圆的面积为：%.2f\n", area);
//    return 0;
//}

//#include <stdio.h>
//int gcd(int a,int b);
//int main (void)
//{
//    int a,b;
//    printf("Input a,b:\n");
//    scanf("%d %d",&a,&b);
//    int result = gcd(a,b);
//    if(a <= 0 || b <= 0){
//        printf("Input number should be positive!\n");
//    }else{
//        printf("Greatest Common Divisor of %d and %d is %d\n",a,b,result);
//    }
//    return 0;
//}
//int gcd(int a,int b){
//    while (b != 0){
//        int temp = a % b;
//        a = b;
//        b = temp;
//    }
//    return a;
//}

//#include <stdio.h>
//int getPeachNumber(int n);
//int main (void)
//{
//    int n = 10;
//    int num = getPeachNumber(n);
//    int peaches = 1;
//    for (int i = n - 1;i >= 1;i--){
//        peaches = 2 * (peaches + 1);
//        printf("第%d天所剩桃子%d个\n",i , peaches);
//    }
//    printf("猴子第一天摘了:%d个桃子.\n",num);
//    return 0;
//}
//int getPeachNumber(int n){
//    if (n == 1){
//        return 1;
//    }else{
//        return 2 * (getPeachNumber(n - 1) + 1);
//    }
//}

//#include <stdio.h>
//#include <stdlib.h>
//
//// 计算给定日期是星期几的函数
//int dayOfWeek(int year, int month, int day) {
//    if (month < 3) {
//        month += 12;
//        year -= 1;
//    }
//    int k = year % 100;
//    int j = year / 100;
//    int f = day + 13 * (month + 1) / 5 + k + k / 4 + j / 4 + 5 * j;
//    return f % 7;
//}
//
//// 打印月历的函数
//void printMonthCalendar(int year, int month) {
//    // 月份名称数组
//    const char *months[] = {"January", "February", "March", "April", "May", "June",
//                            "July", "August", "September", "October", "November", "December"};
//
//    // 每个月的天数
//    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
//
//    // 判断是否为闰年
//    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
//        daysInMonth[1] = 29;
//    }
//
//    // 打印月份标题
//    printf("   %s %d\n", months[month - 1], year);
//    printf("Su Mo Tu We Th Fr Sa\n");
//
//    // 计算当月1号是星期几
//    int startDay = dayOfWeek(year, month, 1);
//
//    // 打印空格
//    for (int i = 0; i < startDay; i++) {
//        printf("   ");
//    }
//
//    // 打印日期
//    for (int day = 1; day <= daysInMonth[month - 1]; day++) {
//        printf("%2d ", day);
//
//        // 换行
//        if ((startDay + day) % 7 == 0) {
//            printf("\n");
//        }
//    }
//
//    // 最后一行换行
//    if ((startDay + daysInMonth[month - 1]) % 7 != 0) {
//        printf("\n");
//    }
//}
//
//int main() {
//    int year, month;
//
//    // 获取用户输入的年份和月份
//    printf("Enter the year: ");
//    scanf("%d", &year);
//    printf("Enter the month: ");
//    scanf("%d", &month);
//
//    // 打印月历
//    printMonthCalendar(year, month);
//
//    return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//int isLeapYear(int year) {
//    return (year % 4 == 0 && year % 100!= 0) || year % 400 == 0;
//}
//int getDaysInMonth(int month, int year) {
//    int days;
//    switch (month) {
//        case 2:
//            days = isLeapYear(year)? 29 : 28;
//            break;
//        case 4:case 6:case 9:case 11:
//            days = 30;
//            break;
//        default:
//            days = 31;
//    }
//    return days;
//}
//void printCalendar(int month, int year) {
//    int daysInMonth = getDaysInMonth(month, year);
//    int dayOfWeek = 1;
//
//    for (int i = 1900; i < year; i++) {
//        if (isLeapYear(i)) {
//            dayOfWeek += 366;
//        } else {
//            dayOfWeek += 365;
//        }
//    }
//    for (int i = 1; i < month; i++) {
//        dayOfWeek += getDaysInMonth(i, year);
//    }
//    dayOfWeek %= 7;
//    if(month == 1)             printf("    January       %d\n", year);
//    else if(month == 2)        printf("    February      %d\n", year);
//    else if(month == 3)        printf("    March         %d\n", year);
//    else if(month == 4)        printf("    April         %d\n", year);
//    else if(month == 5)        printf("    May           %d\n", year);
//    else if(month == 6)        printf("    June          %d\n", year);
//    else if(month == 7)        printf("    July          %d\n", year);
//    else if(month == 8)        printf("    August        %d\n", year);
//    else if(month == 9)        printf("    September     %d\n", year);
//    else if(month == 10)       printf("    October       %d\n", year);
//    else if(month == 11)       printf("    November      %d\n", year);
//    else if(month == 12)       printf("    December      %d\n", year);
//    printf("---------------------------\n");
//    printf("Sun Mon Tue Wed Thu Fri Sat\n");
//    for (int i = 0; i < dayOfWeek; i++) {
//        printf("    ");
//    }
//    for (int day = 1; day <= daysInMonth; day++) {
//        printf("%2d  ", day);
//        if ((day + dayOfWeek) % 7 == 0) {
//            printf("\n");
//        }
//    }
//    printf("\n");
//}
//int main()
//{
//    int month, year;
//    printf("Please input the year:");
//    scanf("%d", &year);
//    printf("Please input the month:");
//    scanf("%d", &month);
//    printf("The output is：\n");
//    printCalendar(month, year);
//    return 0;
//}

//#include <stdio.h>

///**
// * 主函数
// * 本函数用于计算满足以下条件的最大整数i：
// * 1! + 2! + ... + i! >= n
// * 其中n是用户输入的正整数
// */
//int main (){
//    unsigned long i, n, term = 1, sum = 0;
//    // 接收用户输入的正整数n
//    scanf("%lu", &n);
//    // 使用无限循环计算阶乘和，直到和大于等于n
//    for (i = 1; ; i++){
//        // 计算当前项的阶乘值
//        term *= i;
//        // 累加当前项到总和中
//        sum += term;
//        // 如果总和达到或超过n，则退出循环
//        if(sum >= n)
//            break;
//    }
//    // 输出满足条件的最大整数i
//    printf("the ans is %lu\n", i - 1);
//    return 0;
//}

//#include <stdio.h>
//用小于等于n元去买100只鸡，大鸡5元/只，小鸡3元/只,还有1/3元每只的一种小鸡，分别记为x只,y只,z只。编程求解x,y,z所有可能解。
//对于每组输入,请输出x,y,z所有可行解，按照x，y，z依次增大的顺序输出。
//int main ()
//{
//    int n, x, y, z;
//    scanf("%d", &n);
//    for (x = 0; x <= n / 5; x++){
//        for (y = 0; y <= n / 3; y++){
//            for (z = 0; z <= 100; z++){
//                if ((5 * x + 3 * y + (1 / 3) * z ) <= n && (x + y + z == 100)){
//                    printf("x = %d,y = %d,z = %d\n",x,y,z);
//                }
//            }
//        }
//    }
//    return 0;
//}

//#include <stdio.h>
//int main()
//{
//    double a;
//    double b = 0;
//    printf("请输入党员的月收入：");
//    scanf("%lf", &a);
//    if (a == 0) {
//        b = 0.2 * 3;
//    }
//    else if (a <= 3000) {
//        b = a * 0.005 * 3;
//    }
//    else if (a <= 5000) {
//        b = a * 0.01 * 3;
//    }
//    else if (a <= 10000) {
//        b = a * 0.015 * 3;
//    }
//    else {
//        b = a * 0.02 * 3;
//    }
//    printf("每个季度应交党费总数为：%.2f\n", b);
//    return 0;
//}

//#include <stdio.h>
//int main ()
//{
//    int a,b,c;
//    int count = 0;
//    for (int i = 100;i <= 999;i++){
//        a = i / 100; // 百位
//        b = i / 10 % 10; // 十位
//        c = i % 10; // 个位
//        if (a * a * a + b * b * b + c * c * c == i){
//            printf("%d\n", i);
//            count++;
//        }
//    }
//    printf("共有%d个水仙花数\n", count);
//    return 0;
//}

//输出Fibonacci（斐波那契）数列的前20个数。这个数列有如下特点。第1、2个数为1，1。
//从第3个数开始，该数是其前面两个数之和，。即该数列为1，1，2，3，5，8，13，21，34。。。。。。
//#include <stdio.h>
//int fibonacci(int n);
//int main ()
//{
//    for (int i = 1;i <= 20;i++){
//        printf("%d ", fibonacci(i));
//    }
//    return 0;
//}
//int fibonacci(int n){
//    if (n == 1 || n == 2){
//        return 1;
//    }
//    return fibonacci(n - 1) + fibonacci(n - 2);
//}

//要求从键盘输入百分制分数，输出百分制以及对应的五级制分数。90分以上输出A，80-89分输出B，70-79分输出C，60-69分输出D，60分以下输出E。
//#include <stdio.h>
//int main ()
//{
//    double score;
//    printf("Input your score:\n");
//    scanf("%lf", &score);
//    if (score >= 0 && score <= 100){
//        int n = score / 10;
//        switch (n){
//            case 9:case 10:
//                printf("%.0lf is A", score);
//                break;
//            case 8:
//                printf("%.0lf is B", score);
//                break;
//            case 7:
//                printf("%.0lf is C", score);
//                break;
//            case 6:
//                printf("%.0lf is D", score);
//                break;
//            default:
//                printf("%.0lf is E", score);
//        }
//    }
//    else{
//        printf("Invalid input");
//    }
//    return 0;
//}


//#include <stdio.h>
//void Input (int a[],int n);
//int Search (int a[],int n);
//int check (int x);
//int main ()
//{
//    int n;
//    scanf("%d", &n);
//    int a[n];
//    Input(a, n);
//    int count = Search(a, n);
//    printf("%d", count);
//    return 0;
//}
//void Input (int a[],int n){
//    for (int i = 0;i < n;i++){
//        scanf("%d", &a[i]);
//    }
//}
//int Search (int a[],int n){
//    int count = 0;
//    for (int i = 0;i < n;i++){
//        if (check(a[i]) == 0){
//            printf("%d\n", a[i]);
//            count++;
//        }
//    }
//    return count;
//}
//int check (int x){
//    int reversed = 0;
//    while (x > reversed){
//        reversed = reversed * 10 + x % 10;
//        x /= 10;
//    }
//    if (x == reversed || x == reversed / 10){
//        return 1;
//    }else{
//        return 0;
//    }
//}

//打印一个字母金字塔
//#include <stdio.h>
//// 打印字母金字塔的函数
//void printAlphabetPyramid(char letter) {
//    if (letter >= 'a' && letter <= 'z') {
//        letter = letter - ('a' - 'A');  // 将小写字母转化为大写字母
//    }
//    int n = letter - 'A' + 1;  // 将字母转换为对应的行数
//    for (int i = 1; i <= n; i++) {
//        // 打印空格
//        for (int j = 1; j <= n - i; j++) {
//            printf("  ");
//        }
//        // 打印字母
//        for (int j = 1; j <= i; j++) {
//            char alphabet = 'A' + j - 1;
//            printf("%c ", alphabet);
//        }
//        // 打印另一半字母
//        for (int j = i - 1; j >= 1; j--) {
//            char alphabet = 'A' + j - 1;
//            printf("%c ", alphabet);
//        }
//        printf("\n");
//    }
//}
//int main() {
//    char letter;
//    printf("请输入一个字母（大小写均可）：");
//    scanf(" %c", &letter);
//    printAlphabetPyramid(letter);
//    return 0;
//}

//读入一个被污染的非负八进制整数，输入中包含非法的字符，需要忽略他们，用十进制格式输出。
//#include <stdio.h>
//int main ()
//{
//    char c;
//    int n = 0;
//    while ((c = getchar()) != '\n'){
//        if (c >= '0' && c <= '7'){
//            n = n * 8 + c - '0';
//        }
//    }
//    printf("Value = %d", n);
//    return 0;
//}

//#include <stdio.h>
//int main (){
//    int Ax1,Ay1,Ax2,Ay2,Bx1,By1,Bx2,By2;
//    scanf("%d %d %d %d", &Ax1, &Ay1, &Ax2, &Ay2);
//    scanf("%d %d %d %d", &Bx1, &By1, &Bx2, &By2);
//    int a1 = Ax1 < Ax2 ? Ax1 : Ax2;
//    int a2 = Ax1 > Ax2 ? Ax1 : Ax2;
//    int a3 = Ay1 < Ay2 ? Ay1 : Ay2;
//    int a4 = Ay1 > Ay2 ? Ay1 : Ay2;
//    int b1 = Bx1 < Bx2 ? Bx1 : Bx2;
//    int b2 = Bx1 > Bx2 ? Bx1 : Bx2;
//    int b3 = By1 < By2 ? By1 : By2;
//    int b4 = By1 > By2 ? By1 : By2;
//    int c1 = a1 > b1 ? a1 : b1;
//    int c2 = a2 < b2 ? a2 : b2;
//    int c3 = a3 > b3 ? a3 : b3;
//    int c4 = a4 < b4 ? a4 : b4;
//    if (c2 < c1 || c4 < c3){
//        printf("0");
//    }else{
//        printf("%d\n", (c2 - c1) * (c4 - c3));
//    }
//    return 0;
//}

//#include <stdio.h>
//int main (){
//    int N,max,min;
//    scanf("%d\n", &N);
//    int a[N];
//    for (int i = 0;i < N;i++){
//        scanf("%d", &a[i]);
//    }
//    max = a[0];
//    min = a[0];
//    for (int i = 1;i < N;i++){
//        if (a[i] > max){
//            max = a[i];
//        }
//        if (a[i] < min){
//            min = a[i];
//        }
//    }
//    printf("%d %d", max, min);
//    return 0;
//}

//#include <stdio.h>
//int main() {
//    int N;
//    scanf("%d", &N);
//    int x = 0;
//    for(int A = 1; A <= 8; A++) {
//        for(int B = A + 1; B <= 9; B++) {
//            int AB = A * 10 + B;
//            int BA = B * 10 + A;
//            if(AB * BA == N) {
//                printf("%d\n", A * 10 + B);
//                x = 1;
//                break;
//            }
//        }
//        if(x) break;
//    }
//    if(!x) {
//        printf("No Answer\n");
//    }
//    return 0;
//}

//#include <stdio.h>
//int main (){
//    int a = 10, b = 20;
//    printf("Before swap:a = %d,b = %d\n", a, b);
//    int *pa = &a, *pb = &b;
//    int temp = *pa;
//    *pa = *pb;
//    *pb = temp;
//    printf("After swap:a = %d,b = %d\n", a, b);
//    return 0;
//}

//#include <stdio.h>
//void swap(int *pa, int *pb){
//    int temp = *pa;
//    *pa = *pb;
//    *pb = temp;
//}
//int main (){
//    int a = 10, b = 20;
//    printf("Before swap:a = %d,b = %d\n", a, b);
//    swap(&a, &b);
//    printf("After swap:a = %d,b = %d\n", a, b);
//    printf("\n");
//    int x = 10, y = 20;
//    printf("Before swap:a = %d,b = %d\n", x, y);
//    int *px = &x, *py = &y;
//    int temp1 = *px;
//    *px = *py;
//    *py = temp1;
//    printf("After swap:a = %d,b = %d\n", x, y);
//    printf("\n");
//    int i = 10,j = 20;
//    printf("Before swap:a = %d,b = %d\n", i, j);
//    int temp2 = i;
//    i = j;
//    j = temp2;
//    printf("After swap:a = %d,b = %d\n", i, j);
//    return 0;
//}

//#include <stdio.h>
//static int dayTab[2][13] = {{0,31,28,31,30,31,30,31,31,30,31,30,31},
//                            {0,31,29,31,30,31,30,31,31,30,31,30,31}};
//void MonthDay(int year, int yearDay, int *pMonth, int *pDay){
//    int i, leap;
//    leap = ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
//    for(i=1; yearDay>dayTab[leap][i]; i++){
//        yearDay = yearDay - dayTab[leap][i];
//    }
//    *pMonth = i;
//    *pDay = yearDay;
//}
//int DayOfYear(int year, int month, int day){
//    int i, leap;
//    leap = ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
//    int yearDay = day;
//    for(i=1; i<month; i++){
//        yearDay += dayTab[leap][i];
//    }
//    return yearDay;
//}
//int main (){
//    int year = 2012,month = 12,day = 21;
//    int yearDay = DayOfYear(year, month, day);
//    printf("%d年%d月%d日是%d年的第%d天\n", year, month, day, year, yearDay);
//    int pMonth, pDay;
//    MonthDay(year, yearDay, &pMonth, &pDay);
//    printf("反向验证：第%d天是%d年%d月%d日\n", yearDay, year, pMonth, pDay);
//    return 0;
//}

//#include <stdio.h>
//int main() {
//    int n;
//    scanf("%d", &n);
//    int x[15], y[15];
//    for (int i = 0; i < n; i++) {
//        scanf("%d %d", &x[i], &y[i]);
//    }
//    double area = 0.0;
//    for (int i = 0; i < n; i++) {
//        int j = (i + 1) % n;
//        area += (double)x[i] * y[j];
//        area -= (double)y[i] * x[j];
//    }
//    area = area / 2.0;
//    if (area < 0) {
//        area = -area;
//    }
//    printf("%.1f\n", area);
//    return 0;
//}

//#include <stdio.h>
//int main() {
//    int n, m, q;
//    scanf("%d %d %d", &n, &m, &q);
//    int monkeys[100] = {0};
//    for(int i = 0; i < n; i++) {
//        monkeys[i] = 1;  // 1表示在圈中
//    }
//    int count = n;
//    int pos = q - 1;  // 从第q号开始（下标从0开始所以减1）
//    int step;
//    while(count > 1) {
//        step = 0;
//        while(step < m) {
//            if(monkeys[pos]) step++;
//            if(step < m) pos = (pos + 1) % n;
//        }
//        monkeys[pos] = 0;
//        count--;
//    }
//    for (int i = 0; i < n; i++) {
//        if (monkeys[i]) {
//            printf("最后剩下的是%d号猴子\n", i + 1);
//            break;
//        }
//    }
//    return 0;
//}

//#include<stdio.h>
//int primenumbercheck(int N){
//    if(N <= 1) return 0;
//    for(int i = 2; i*i <= N; i++){
//        if(N % i == 0)
//            return 0;
//    }
//    return 1;
//}
//int reverseInteger(int n) {
//    int reversedNumber = 0;
//    while (n > 0) {
//        reversedNumber = reversedNumber * 10 + n % 10;
//        n = n / 10;
//    }
//    return reversedNumber;
//}
//int main(){
//    int N;
//    scanf("%d", &N);
//    if(N <= 0 || !primenumbercheck(N)){
//        printf("no\n");
//        return 0;
//    }
//    // 再检查反转后的数是否为素数
//    int reversed = reverseInteger(N);
//    if(primenumbercheck(reversed))
//        printf("yes\n");
//    else
//        printf("no\n");
//    return 0;
//}

//#include <stdio.h>
//
//int main() {
//    long n;
//    scanf("%ld", &n);
//    int first = 1;  // 用于控制空格输出
//    // 处理所有2的因子
//    if(n % 2 == 0) {
//        printf("2");
//        first = 0;
//        n = n / 2;
//        while(n % 2 == 0) n = n / 2;
//    }
//    // 处理其他素因子
//    for(int i = 3; i <= n; i += 2) {
//        if(n % i == 0) {
//            if(!first) printf(" ");
//            printf("%d", i);
//            first = 0;
//            n = n / i;
//            while(n % i == 0) n = n / i;
//            i -= 2;  // 重置i，继续检查当前位置
//        }
//    }
//    printf("\n");
//    return 0;
//}

//#include <stdio.h>
//int main() {
//    int x,y,z;
//    for(x = 0; x <= 30; x++) {
//        for(y = 0; y <= 30; y++) {
//            z = 30 - x - y;
//            if(z >= 0 && 1.0 * x / 2 + 2.0 * y / 3 + 5.0 * z / 7 == 20) {
//                printf("x = %d, y = %d, z = %d\n", x, y, z);
//            }
//        }
//    }
//    return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//// 节点结构定义
//typedef struct {
//    char data;
//    struct node *link;
//} node;
//node *head;  // 头指针
//// 头插法插入节点
//void ins(node *q) {
//    if (head == NULL) {
//        head = q;
//        q->link = NULL;
//    } else {
//        q->link = head;
//        head = q;
//    }
//}
//
//// 主函数
//int main() {
//    node *p;
//    char ch;
//    // 读取输入字符
//    while ((ch = getchar()) != EOF) {
//        // 创建新节点
//        p = (node *)malloc(sizeof(node));
//        p->data = ch;
//        ins(p);  // 插入节点
//    }
//
//    // 打印链表
//    for (p = head; p; p = p->link) {
//        printf("%c", p->data);
//    }
//    return 0;
//}

//#include <stdio.h>
//typedef struct clock{
//    int hour;
//    int minute;
//    int second;
//}CLOCK;
//void Update (CLOCK *t) {
//    static long m = 1;
//    t->hour = m / 3600;
//    t->minute = m % 3600 / 60;
//    t->second = m % 60;
//    m++;
//    if (t->hour == 24) m = 1;
//}
//void Display (CLOCK *t) {
//    printf("%2d:%2d:%2d\n", t->hour, t->minute, t->second);
//}
//void Delay () {
//    long t;
//    for (t = 0; t < 50000000; t++) {}
//}
//int main () {
//    CLOCK myClock;
//    myClock.hour = myClock.minute = myClock.second = 0;
//    for (long i = 0; 1; i++) {
//        Update(&myClock);
//        Display(&myClock);
//        Delay();
//        return 0;
//    }
//}

//#include <stdio.h>
//int lengthOfLongestSubstring(char *s) {
//    int last[128] = {0};
//    int start = 0, max = 0;
//    for (int i = 0; s[i] != '\0'; i++) {
//        if (last[s[i]] > start) {
//            start = last[s[i]];
//        }
//        last[s[i]] = i + 1;
//        if (i - start + 1 > max) {
//            max = i - start + 1;
//        }
//    }
//    return max;
//}
//int main() {
//    printf("Input a string:");
//    char s[100];
//    scanf("%s", s);
//    printf("%d\n", lengthOfLongestSubstring(s));
//    return 0;
//}

////链表的相关操作
//#include <stdio.h>
//#include <stdlib.h>
////定义节点
//typedef struct node {
//    int data;//数据域
//    struct node *next;//指针域
//}Node;
////创建节点
//Node *createNode (int data) {
//    Node *p = (Node *)malloc(sizeof(Node));//分配内存
//    p->data = data;//赋值
//    p->next = NULL;//指针域为空
//    return p;
//}
////插入节点
//Node *insertNode (Node *head, int data, int index) {
//    Node *p = createNode(data);//创建新节点
//    if (head == NULL) {
//        return p;//如果链表为空，直接返回新节点
//    }
//    if (index == 0) {
//        p->next = head;//新节点指向头节点
//        return p;
//    }
//    Node *current = head;
//    for (int i = 0; i < index - 1 && current->next != NULL; i++) {
//        current = current->next;//遍历链表，直到找到要插入的位置
//    }
//    p->next = current->next;//新节点指向下一个节点
//    current->next = p;//当前节点指向新节点
//    return head;//返回头节点
//}
////头插法
//Node *insertAtHead (Node *head, int data) {
//    Node *p = createNode(data);//创建新节点
//    if (head != NULL) {
//        p->next = head;//新节点指向头节点
//    }
//    return p;//返回新节点
//}
////尾插法
//Node *insertAyTail (Node *head, int data) {
//    Node *p = createNode(data);//创建新节点
//    if (head == NULL) {
//        return p;//如果链表为空，直接返回新节点
//    }
//    Node *current = head;//定义一个指针指向头节点
//    while (current->next != NULL) {
//        current = current->next;//遍历链表，直到找到最后一个节点
//    }
//    current->next = p;//将新节点插入到链表的尾部
//    return head;//返回头节点
//}
////交换节点
//Node *swapNode (Node *head, int data1, int data2) {
//    if (data1 == data2) {
//        return head;//如果两个节点相同，直接返回
//    }
//    Node *prevX = NULL, *currentX = head;//定义两个指针，一个指向第一个节点，一个指向第二个节点
//    while (currentX != NULL && currentX->data != data1) {
//        prevX = currentX;//保存第一个节点的前一个节点
//        currentX = currentX->next;//遍历链表，找到第一个节点
//    }
//    Node *prevY = NULL, *currentY = head;
//    while (currentY != NULL && currentY->data != data2) {
//        prevY = currentY;
//        currentY = currentY->next;//遍历链表，找到第二个节点
//    }
//    if (currentX == NULL || currentY == NULL) {
//        return head;//如果有一个节点为空，直接返回
//    }
//    if (prevX != NULL) {
//        prevX->next = currentY;//第一个节点的前一个节点指向第二个节点
//    }else{
//        head = currentY;//如果第一个节点是头节点，直接将头节点指向第二个节点
//    }
//    if (prevY != NULL) {
//        prevY->next = currentX;//第二个节点的前一个节点指向第一个节点
//    }else{
//        head = currentX;//如果第二个节点是头节点，直接将头节点指向第一个节点
//    }
//    Node *temp = currentX->next;//保存第一个节点的下一个节点
//    currentX->next = currentY->next;//第一个节点指向第二个节点的下一个节点
//    currentY->next = temp;//第二个节点指向第一个节点的下一个节点
//    return head;//返回头节点
//}
////删除节点
//Node *deleteNode (Node *head, int data) {
//    if (head == NULL) return NULL;//如果链表为空，直接返回
//    if (head->data == data) {
//        Node *temp = head->next;//保存头节点的下一个节点
//        free(head);//释放头节点
//        return temp;//返回新的头节点
//    }
//    Node *current = head;
//    while (current->next != NULL && current->next->data != data) {
//        current = current->next;//遍历链表，直到找到要删除的节点
//    }
//    if (current->next != NULL) {
//        Node *temp = current->next;//保存要删除的节点
//        current->next = current->next->next;//删除节点
//        free(temp);//释放节点
//    }
//    return head;//返回头节点
//}
////查找节点
//Node *findNode (Node *head, int data) {
//    Node *current = head;
//    while (current != NULL) {
//        if (current->data == data) {
//            return current;//找到节点，返回节点
//        }
//        current = current->next;//继续遍历
//    }
//    return NULL;//未找到，返回空
//}
////打印链表
//void printList (Node *head) {
//    Node *current = head;
//    while (current != NULL) {
//        printf("%d -> ", current->data);
//        current = current->next;
//    }
//    printf("NULL\n");
//}
////释放链表
//void freeList (Node *head) {
//    Node *current = head;
//    while (current != NULL) {
//        Node *temp = current;
//        current = current->next;
//        free(temp);
//    }
//}
//int main () {
//    Node *head = NULL;
//    head = insertNode(head, 1, 0);
//    head = insertNode(head, 2, 1);
//    head = insertNode(head, 3, 2);
//    head = insertNode(head, 4, 3);
//    head = insertNode(head, 5, 4);
//    printList(head);
//    head = insertAtHead(head, 0);
//    printList(head);
//    head = insertAyTail(head, 6);
//    printList(head);
//    head = swapNode(head, 0, 6);
//    printList(head);
//    head = deleteNode(head, 6);
//    printList(head);
//    Node *node = findNode(head, 5);
//    if (node != NULL) {
//        printf("Found: %d\n", node->data);
//    }else{
//        printf("Not Found\n");
//    }
//    freeList(head);
//    return 0;
//}

////所有排序算法
//#include <stdio.h>
//#include <stdlib.h>
////冒泡排序
//void bubbleSort (int arr[], int n) {//时间复杂度O(n^2)
//    for (int i = 0; i < n - 1; i++) {//外层循环控制比较轮数
//        for (int j = 0; j < n - i - 1; j++) {//内层循环控制每轮比较次数
//            if (arr[j] > arr[j + 1]) {//如果前一个元素大于后一个元素，交换位置
//                int temp = arr[j];//交换位置
//                arr[j] = arr[j + 1];
//                arr[j + 1] = temp;
//            }
//        }
//    }
//}
////选择排序
//void selectionSort (int arr[], int n) {//时间复杂度O(n^2)
//    for (int i = 0; i < n - 1; i++) {//外层循环控制比较轮数
//        int minIndex = i;//假设当前位置是最小值
//        for (int j = i + 1; j < n; j++) {//遍历数组，找到最小值的位置
//            if (arr[j] < arr[minIndex]) {//如果当前位置的值小于最小值，更新最小值的位置
//                minIndex = j;//更新最小值的位置
//            }
//        }
//        if (minIndex != i) {//如果最小值的位置不是当前位置，交换位置
//            int temp = arr[i];
//            arr[i] = arr[minIndex];
//            arr[minIndex] = temp;
//        }
//    }
//}
////插入排序
//void insertionSort (int arr[], int n) {//时间复杂度O(n^2)
//    for (int i = 1; i < n; i++) {//外层循环控制插入的元素
//        int key = arr[i];//保存当前位置的值
//        int j = i - 1;//保存当前位置的前一个位置
//        while (j >= 0 && arr[j] > key) {//如果前一个位置的值大于当前位置的值，将前一个位置的值后移
//            arr[j + 1] = arr[j];//将前一个位置的值后移
//            j--;//继续向前比较
//        }
//        arr[j + 1] = key;//将当前位置的值插入到合适的位置
//    }
//}
////快速排序
//void quickSort (int arr[], int low, int high) {//时间复杂度O(nlogn)
//    if (low < high) {//递归结束条件
//        int i = low, j = high, key = arr[low];//定义左右指针和基准值
//        while (i < j) {//左右指针未相遇
//            while (i < j && arr[j] >= key) j--;//从右向左找到第一个小于基准值的位置
//            if (i < j) arr[i++] = arr[j];//将小于基准值的值放到左边
//            while (i < j && arr[i] < key) i++;//从左向右找到第一个大于等于基准值的位置
//            if (i < j) arr[j--] = arr[i];//将大于等于基准值的值放到右边
//        }
//        arr[i] = key;//将基准值放到合适的位置
//        quickSort(arr, low, i - 1);//递归左边
//        quickSort(arr, i + 1, high);//递归右边
//    }
//}
////归并排序
//void merge (int arr[], int low, int mid, int high) {//合并两个有序数组
//    int *temp = (int *)malloc((high - low + 1) * sizeof(int));//分配内存
//    int i = low, j = mid + 1, k = 0;//定义左右指针和临时数组的下标
//    while (i <= mid && j <= high) {//合并两个有序数组
//        temp[k++] = arr[i] < arr[j] ? arr[i++] : arr[j++];//将较小的值放到临时数组
//    }
//    while (i <= mid) temp[k++] = arr[i++];//将左边剩余的值放到临时数组
//    while (j <= high) temp[k++] = arr[j++];//将右边剩余的值放到临时数组
//    for (i = 0; i < k; i++) arr[low + i] = temp[i];//将临时数组的值复制到原数组
//    free(temp);//释放内存
//}
//void mergeSort (int arr[], int low, int high) {//时间复杂度O(nlogn)
//    if (low < high) {//递归结束条件
//        int mid = (low + high) / 2;//计算中间位置
//        mergeSort(arr, low, mid);//递归左边
//        mergeSort(arr, mid + 1, high);//递归右边
//        merge(arr, low, mid, high);//合并两个有序数组
//    }
//}
//int main () {
//    int arr[] = {5, 3, 8, 6, 4};
//    int n = sizeof(arr) / sizeof(arr[0]);
//    bubbleSort(arr, n);
//    for (int i = 0; i < n; i++) {
//        printf("%d ", arr[i]);
//    }
//    printf("\n");
//    int arr1[] = {5, 3, 8, 6, 4};
//    selectionSort(arr1, n);
//    for (int i = 0; i < n; i++) {
//        printf("%d ", arr1[i]);
//    }
//    printf("\n");
//    int arr2[] = {5, 3, 8, 6, 4};
//    insertionSort(arr2, n);
//    for (int i = 0; i < n; i++) {
//        printf("%d ", arr2[i]);
//    }
//    printf("\n");
//    int arr3[] = {5, 3, 8, 6, 4};
//    quickSort(arr3, 0, n - 1);
//    for (int i = 0; i < n; i++) {
//        printf("%d ", arr3[i]);
//    }
//    printf("\n");
//    int arr4[] = {5, 3, 8, 6, 4};
//    mergeSort(arr4, 0, n - 1);
//    for (int i = 0; i < n; i++) {
//        printf("%d ", arr4[i]);
//    }
//    printf("\n");
//    return 0;
//}

////二分查找
//#include <stdio.h>
//int binarySearch (int arr[], int n, int key) {//时间复杂度O(logn)
//    int low = 0, high = n - 1;//定义左右指针
//    while (low <= high) {//循环查找
//        int mid = (low + high) / 2;//计算中间位置
//        if (arr[mid] == key) return mid;//找到元素，返回位置
//        if (arr[mid] < key) low = mid + 1;//如果中间位置的值小于要查找的值，向右查找
//        else high = mid - 1;//如果中间位置的值大于要查找的值，向左查找
//    }
//    return -1;//未找到，返回-1
//}
//int main () {
//    int arr[] = {1, 3, 5, 7, 9};
//    int n = sizeof(arr) / sizeof(arr[0]);
//    int key = 5;
//    int index = binarySearch(arr, n, key);
//    if (index != -1) {
//        printf("Found: %d\n", index);
//    }else{
//        printf("Not Found\n");
//    }
//    return 0;
//}

////数组相关操作
//#include <stdio.h>
//int N;
////一维数组  常见考试题型
//// 1. 数组元素求和
//int Sum (int arr[], int n) { //时间复杂度O(n)
//    int sum = 0; //定义和
//    for (int i = 0; i < n; i++) { //遍历数组
//        sum += arr[i]; //累加
//    }
//    return sum; //返回和
//}
//
//// 2. 查找最大/最小值
//int Max (int arr[], int n) { //时间复杂度O(n)
//    int max = arr[0]; //定义最大值
//    for (int i = 1; i < n; i++) { //遍历数组
//        if (arr[i] > max) { //如果当前元素大于最大值
//            max = arr[i]; //更新最大值
//        }
//    }
//    return max; //返回最大值
//}
//int Min (int arr[], int n) { //时间复杂度O(n)
//    int min = arr[0]; //定义最小值
//    for (int i = 1; i < n; i++) { //遍历数组
//        if (arr[i] < min) { //如果当前元素小于最小值
//            min = arr[i]; //更新最小值
//        }
//    }
//    return min; //返回最小值
//}
//
//// 3. 数组元素逆序
//void Reverse (int arr[], int n) { //时间复杂度O(n)
//    for (int i = 0; i < n / 2; i++) { //遍历数组的一半
//        int temp = arr[i]; //交换元素
//        arr[i] = arr[n - i - 1]; //交换元素
//        arr[n - i - 1] = temp; //交换元素
//    }
//}
//
////二维数组  常见考试题型
////1. 矩阵转置
//void transpose(int a[][N], int n) { //时间复杂度O(n^2)
//    for(int i = 0; i < n; i++) { //遍历矩阵
//        for(int j = i+1; j < n; j++) { //遍历矩阵
//            int temp = a[i][j]; //交换元素
//            a[i][j] = a[j][i]; //交换元素
//            a[j][i] = temp; //交换元素
//        }
//    }
//}
//
//// 2. 求主/副对角线元素和
//int sumDiagonal(int a[][N], int n) { //时间复杂度O(n)
//    int sum = 0; //定义和
//    for(int i = 0; i < n; i++) { //遍历矩阵
//        sum += a[i][i]; //累加
//        sum += a[i][n-i-1]; //累加
//    }
//    if(n % 2 == 1) { //如果是奇数阶矩阵
//        sum -= a[n/2][n/2]; //减去重复的中心元素
//    }
//    return sum; //返回和
//}
//
//// 3. 行/列最大值
//void maxRow(int a[][N], int n) { //时间复杂度O(n^2)
//    for(int i = 0; i < n; i++) { //遍历矩阵
//        int max = a[i][0]; //定义最大值
//        for(int j = 1; j < n; j++) { //遍历矩阵
//            if(a[i][j] > max) { //如果当前元素大于最大值
//                max = a[i][j]; //更新最大值
//            }
//        }
//        printf("%d ", max); //输出最大值
//    }
//}
//void maxColumn(int a[][N], int n) { //时间复杂度O(n^2)
//    for(int i = 0; i < n; i++) { //遍历矩阵
//        int max = a[0][i]; //定义最大值
//        for(int j = 1; j < n; j++) { //遍历矩阵
//            if(a[j][i] > max) { //如果当前元素大于最大值
//                max = a[j][i]; //更新最大值
//            }
//        }
//        printf("%d ", max); //输出最大值
//    }
//}
//
//// 4. 行/列最小值
//void minRow(int a[][N], int n) { //时间复杂度O(n^2)
//    for(int i = 0; i < n; i++) { //遍历矩阵
//        int min = a[i][0]; //定义最小值
//        for(int j = 1; j < n; j++) { //遍历矩阵
//            if(a[i][j] < min) { //如果当前元素小于最小值
//                min = a[i][j]; //更新最小值
//            }
//        }
//        printf("%d ", min); //输出最小值
//    }
//}
//void minColumn(int a[][N], int n) { //时间复杂度O(n^2)
//    for(int i = 0; i < n; i++) { //遍历矩阵
//        int min = a[0][i]; //定义最小值
//        for(int j = 1; j < n; j++) { //遍历矩阵
//            if(a[j][i] < min) { //如果当前元素小于最小值
//                min = a[j][i]; //更新最小值
//            }
//        }
//        printf("%d ", min); //输出最小值
//    }
//}
//
////字符数组  常见考试题型
//// 1. 字符串长度
//int Length (char str[]) { //时间复杂度O(n)
//    int len = 0; //定义长度
//    while (str[len] != '\0') { //遍历字符串
//        len++; //累加
//    }
//    return len; //返回长度
//}
//
//// 2. 字符串复制
//void Copy (char str1[], char str2[]) { //时间复杂度O(n)
//    int i = 0; //定义下标
//    while (str1[i] != '\0') { //遍历字符串
//        str2[i] = str1[i]; //复制
//        i++; //下标加1
//    }
//    str2[i] = '\0'; //添加结束符
//}
//
//// 3. 字符串反转
//void ReverseStr (char str[]) { //时间复杂度O(n)
//    int len = Length(str); //获取字符串长度
//    for (int i = 0; i < len / 2; i++) { //遍历一半
//        char temp = str[i]; //交换元素
//        str[i] = str[len - i - 1]; //交换元素
//        str[len - i - 1] = temp; //交换元素
//    }
//}
//
//// 4. 字符串连接
//void Concat (char str1[], char str2[]) { //时间复杂度O(n)
//    int len1 = Length(str1); //获取字符串长度
//    int len2 = Length(str2); //获取字符串长度
//    for (int i = 0; i < len2; i++) { //遍历字符串
//        str1[len1 + i] = str2[i]; //连接
//    }
//    str1[len1 + len2] = '\0'; //添加结束符
//}
//
//// 5. 字符串比较
//int Compare (char str1[], char str2[]) { //时间复杂度O(n)
//    int i = 0; //定义下标
//    while (str1[i] != '\0' && str2[i] != '\0') { //遍历字符串
//        if (str1[i] != str2[i]) { //如果不相等
//            return str1[i] - str2[i]; //返回差值
//        }
//        i++; //下标加1
//    }
//    return str1[i] - str2[i]; //返回差值
//}
//
//// 例1：找出数组中第二大的数
//int secondMax(int arr[], int n) { //时间复杂度O(n)
//    int max = arr[0], second = arr[0]; //定义最大值和第二大值
//    for(int i = 1; i < n; i++) { //遍历数组
//        if(arr[i] > max) { //如果当前元素大于最大值
//            second = max; //更新第二大值
//            max = arr[i]; //更新最大值
//        }else if(arr[i] > second && arr[i] < max) { //如果当前元素大于第二大值且小于最大值
//            second = arr[i]; //更新第二大值
//        }
//    }
//    return second; //返回第二大值
//}
//
//// 例2：判断矩阵是否对称
//int isSymmetric(int a[][N], int n) { //时间复杂度O(n^2)
//    for(int i = 0; i < n; i++) { //遍历矩阵
//        for(int j = i+1; j < n; j++) { //遍历矩阵
//            if(a[i][j] != a[j][i]) { //如果不对称
//                return 0; //返回0
//            }
//        }
//    }
//    return 1; //对称则返回1
//}
//
//// 例3：统计字符串中各类字符的个数
//void countChar(char str[]) { //时间复杂度O(n)
//    int letter = 0, digit = 0, space = 0, other = 0; //定义字母、数字、空格、其他字符的个数
//    for(int i = 0; str[i] != '\0'; i++) { //遍历字符串
//        if((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')) { //如果是字母
//            letter++; //字母个数加1
//        }else if(str[i] >= '0' && str[i] <= '9') { //如果是数字
//            digit++; //数字个数加1
//        }else if(str[i] == ' ') { //如果是空格
//            space++; //空格个数加1
//        }else{   //其他字符
//            other++; //其他字符个数加1
//        }
//    }
//    printf("letter = %d, digit = %d, space = %d, other = %d\n", letter, digit, space, other);   //输出结果
//}

////字符串相关操作
////定义和初始化字符串
//#include <stdio.h>
//#include <string.h>
//int main () {
//    char str1[] = "Hello, World!"; //定义字符串
//    char str2[100] = "Hello, World!"; //定义字符串
//    char str3[] = {'H', 'e', 'l', 'l', 'o', '\0'}; //定义字符串
//    char str4[100] = {'H', 'e', 'l', 'l', 'o', '\0'}; //定义字符串
//    printf("%s\n", str1); //输出字符串
//    printf("%s\n", str2); //输出字符串
//    printf("%s\n", str3); //输出字符串
//    printf("%s\n", str4); //输出字符串
//    return 0;
//}
//// 1. 实现strlen
//int myStrlen(const char *str) { //时间复杂度O(n)
//    int len = 0; //定义长度
//    while(str[len] != '\0') { //遍历字符串
//        len++; //累加
//    }
//    return len;
//}
//
//// 2. 实现strcpy
//char* myStrcpy(char *dest, const char *src) { //时间复杂度O(n)
//    char *temp = dest; //保存目标字符串的首地址
//    while((*dest++ = *src++) != '\0'); //复制字符串
//    return temp; //返回目标字符串的首地址
//}
//
//// 3. 实现strcmp
//int myStrcmp(const char *s1, const char *s2) { //时间复杂度O(n)
//    while(*s1 && (*s1 == *s2)) { //遍历字符串
//        s1++; //指针后移
//        s2++; //指针后移
//    }
//    return *(unsigned char*)s1 - *(unsigned char*)s2; //返回差值
//}
//// 1.字符串反转
//void strReverse(char *str) { //时间复杂度O(n)
//    int left = 0; //定义左指针
//    int right = strlen(str) - 1; //定义右指针
//    while(left < right) { //遍历字符串
//        char temp = str[left]; //交换元素
//        str[left] = str[right];
//        str[right] = temp;
//        left++; //左指针后移
//        right--; //右指针前移
//    }
//}
//// 2. 字符串查找
//// 查找字符
//int findChar(const char *str, char ch) { //时间复杂度O(n)
//    for(int i = 0; str[i] != '\0'; i++) { //遍历字符串
//        if(str[i] == ch) return i; //找到字符，返回位置
//    }
//    return -1; //未找到，返回-1
//}
//// 查找子串
//char* myStrstr(const char *haystack, const char *needle) { //时间复杂度O(n^2)
//    if(*needle == '\0') return (char*)haystack; //空串
//    for(int i = 0; haystack[i] != '\0'; i++) { //遍历字符串
//        int j; //定义下标
//        for(j = 0; needle[j] != '\0'; j++) { //遍历子串
//            if(haystack[i+j] != needle[j]) break; //不匹配
//        }
//        if(needle[j] == '\0') return (char*)&haystack[i]; //找到子串，返回位置
//    }
//    return NULL; //未找到，返回空
//}
//// 3.字符串转整数
//int myAtoi(const char *str) { //时间复杂度O(n)
//    int result = 0; //定义结果
//    int sign = 1; //定义符号
//    // 处理空格
//    while(*str == ' ') str++; //跳过空格
//    // 处理符号
//    if(*str == '-') {   //负数
//        sign = -1; //更新符号
//        str++; //指针后移
//    } else if(*str == '+') { //正数
//        str++; //指针后移
//    }
//    // 转换数字
//    while(*str >= '0' && *str <= '9') { //遍历字符串
//        result = result * 10 + (*str - '0'); //累加
//        str++; //指针后移
//    }
//    return sign * result; //返回结果
//}
//// 4.整数转字符串
//char* myItoa(int num, char *str) { //时间复杂度O(n)
//    int i = 0; //定义下标
//    int sign = 1; //定义符号
//    if(num < 0) { //负数
//        sign = -1; //更新符号
//        num = -num; //取绝对值
//    }
//    do {
//        str[i++] = num % 10 + '0'; //取余数
//        num /= 10; //取商
//    } while(num);  //直到商为0
//    if(sign == -1) str[i++] = '-'; //添加符号
//    str[i] = '\0'; //添加结束符
//    strReverse(str); //反转字符串
//    return str; //返回字符串
//}
//// 5.单词计数
//int countWords(const char *str) { //时间复杂度O(n)
//    int count = 0; //定义单词个数
//    int inWord = 0; //定义标志
//    while(*str) { //遍历字符串
//        if(*str == ' ' || *str == '\t' || *str == '\n') { //空格、制表符、换行符
//            inWord = 0; //更新标志
//        }
//        else if(inWord == 0) { //单词的第一个字符
//            inWord = 1; //更新标志
//            count++; //累加
//        }
//        str++; //指针后移
//    }
//    return count; //返回单词个数
//}
//// 6.删除字符串中的指定字符
//void deleteChar(char *str, char ch) { //时间复杂度O(n)
//    int i, j; //定义下标
//    for(i = j = 0; str[i] != '\0'; i++) { //遍历字符串
//        if(str[i] != ch) { //不是指定字符
//            str[j++] = str[i]; //复制
//        }
//    }
//    str[j] = '\0'; //添加结束符
//}
//// 7.判断回文字符串
//int isPalindrome(const char *str) { //时间复杂度O(n)
//    int left = 0; //定义左指针
//    int right = strlen(str) - 1; //定义右指针
//    while(left < right) { //遍历字符串
//        if(str[left] != str[right]) { //不相等
//            return 0;  //不是回文字符串
//        }
//        left++; //左指针后移
//        right--; //右指针前移
//    }
//    return 1; //是回文字符串
//}
//// 8.字符串拼接
//char* myStrcat(char *dest, const char *src) { //时间复杂度O(n)
//    char *temp = dest; //保存目标字符串的首地址
//    while(*dest) dest++; //找到目标字符串的结束位置
//    while((*dest++ = *src++)); //拼接字符串
//    return temp; //返回目标字符串的首地址
//}
////应用例题
//// 1. 字符串排序
//void sortStrings(char str[][50], int n) { //时间复杂度O(n^2)
//    for(int i = 0; i < n-1; i++) { //遍历字符串数组
//        for(int j = 0; j < n-i-1; j++) { //遍历字符串数组
//            if(strcmp(str[j], str[j+1]) > 0) { //比较字符串
//                char temp[50]; //定义临时数组
//                strcpy(temp, str[j]); //复制字符串
//                strcpy(str[j], str[j+1]); //复制字符串
//                strcpy(str[j+1], temp); //复制字符串
//            }
//        }
//    }
//}
//// 2. 最长公共子串
//void findLongestCommonSubstring(char *str1, char *str2) { //时间复杂度O(n^2)
//    int len1 = strlen(str1); //获取字符串长度
//    int len2 = strlen(str2); //获取字符串长度
//    int maxLen = 0; //定义最大长度
//    int endIndex = 0; //定义结束位置
//    for(int i = 0; i < len1; i++) { //遍历字符串
//        for(int j = 0; j < len2; j++) { //遍历字符串
//            int len = 0; //定义长度
//            while(str1[i+len] == str2[j+len]) { //比较字符串
//                len++; //累加
//                if(len > maxLen) { //更新最大长度
//                    maxLen = len; //更新最大长度
//                    endIndex = i + len; //更新结束位置
//                }
//            }
//        }
//    }
//    // 输出结果
//    for(int i = endIndex - maxLen; i < endIndex; i++) { //遍历字符串
//        printf("%c", str1[i]); //输出字符
//    }
//}

//#include <stdio.h>
//typedef struct patient_info {
//    int ID;
//    char name[10];
//    int age;
//    char sex;
//    char diagonsidTinme[10];
//    char symptom[100];
//    char doctorDiagonsis[100];
//}patient_info;
//int main() {
//    //从键盘输入5个病人的信息，包括ID、姓名、年龄、性别、诊断时间、症状、医生诊断
//    patient_info patients[5];
//    for (int i = 0; i < 5; i++) {
//        scanf("%d", &patients[i].ID);
//        scanf("%s", patients[i].name);
//        scanf("%d", &patients[i].age);
//        scanf("%s", &patients[i].sex);
//        scanf("%s", patients[i].diagonsidTinme);
//        scanf("%s", patients[i].symptom);
//        scanf("%s", patients[i].doctorDiagonsis);
//    }
//}

//#include <stdio.h>
//#include <math.h>
//// 计算阶乘
//double factorial(int n) {
//    double result = 1.0;
//    for(int i = 2; i <= n; i++) {
//        result *= i;
//    }
//    return result;
//}
//
//// 计算x的n次方
//double power(double x, int n) {
//    double result = 1.0;
//    for(int i = 0; i < n; i++) {
//        result *= x;
//    }
//    return result;
//}
//
//// 计算第n项的值
//double term(double x, int n) {
//    return power(x, n) / factorial(n);
//}
//
//// 计算e^x的近似值
//double calculate(double x, int n) {
//    double sum = 1.0;  // 第0项
//    for(int i = 1; i <= n; i++) {
//        sum += term(x, i);
//    }
//    return sum;
//}
//
//int main() {
//    int x;
//    double eps;
//    scanf("%d %lf", &x, &eps);
//    int n = 1;
//    double curr, prev;
//    // 计算第一个值
//    curr = calculate(x, n);
//    // 不断增加n直到满足精度要求
//    do {
//        n++;
//        prev = curr;
//        curr = calculate(x, n);
//    } while(fabs(curr - prev) > eps);
//    printf("%d\n", n);
//    return 0;
//}

//#include <stdio.h>
//#include <string.h>
//int main() {
//    char str[1001];
//    gets(str);  // 读入字符串
//    int len = strlen(str);
//    int maxLen = 0;  // 最长对称串长度
//    char result[1001] = "none";  // 存储结果
//    // 遍历每个字符作为中心点
//    for(int i = 0; i < len; i++) {
//        // 以i为中心的奇数长度回文
//        int left = i - 1;
//        int right = i + 1;
//        int currLen = 1;
//        while(left >= 0 && right < len && str[left] == str[right]) {
//            currLen += 2;
//            left--;
//            right++;
//        } if(currLen > maxLen) {
//            maxLen = currLen;
//            // 复制找到的回文串
//            strncpy(result, str + left + 1, currLen);
//            result[currLen] = '\0';
//        }
//        // 以i和i+1为中心的偶数长度回文
//        left = i;
//        right = i + 1;
//        currLen = 0;
//        while(left >= 0 && right < len && str[left] == str[right]) {
//            currLen += 2;
//            left--;
//            right++;
//        } if(currLen > maxLen) {
//            maxLen = currLen;
//            strncpy(result, str + left + 1, currLen);
//            result[currLen] = '\0';
//        }
//    }
//    printf("%s\n", result);
//    return 0;
//}

//#include <stdio.h>
//// 计算组合数C(n,r)
//int combination(int n, int r) {
//    if(r == 0 || r == n) return 1;
//    if(r == 1) return n;
//    long long result = 1;
//    r = (r < n-r) ? r : n-r;  // 使用较小的r来减少计算量
//    for(int i = 0; i < r; i++) {
//        result *= (n-i);
//        result /= (i+1);
//    }
//    return (int)result;
//}
//
//// 获取某一行的最大值
//int getMaxInRow(int n) {
//    int max = 0;
//    // 计算第n行的每个数，找出最大值
//    for(int i = 0; i <= n; i++) {
//        int curr = combination(n, i);
//        if(curr > max) {
//            max = curr;
//        }
//    }
//    return max;
//}
//
//int main() {
//    int n;
//    scanf("%d", &n);
//    // 输入验证
//    if(n <= 0 || n >= 40) {
//        return 1;
//    }
//    // 计算并输出第n行的最大值
//    printf("%d\n", getMaxInRow(n-1));  // n-1是因为行数从0开始
//    return 0;
//}

//#include <stdio.h>
//#define MAX_SIZE 9
//void mark_eliminations(int board[MAX_SIZE][MAX_SIZE], int n, int m, int to_eliminate[MAX_SIZE][MAX_SIZE]) {
//    // Check rows for eliminations
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < m - 2; j++) {
//            if (board[i][j] == board[i][j+1] && board[i][j] == board[i][j+2]) {
//                to_eliminate[i][j] = 1;
//                to_eliminate[i][j+1] = 1;
//                to_eliminate[i][j+2] = 1;
//            }
//        }
//    }
//    // Check columns for eliminations
//    for (int j = 0; j < m; j++) {
//        for (int i = 0; i < n - 2; i++) {
//            if (board[i][j] == board[i+1][j] && board[i][j] == board[i+2][j]) {
//                to_eliminate[i][j] = 1;
//                to_eliminate[i+1][j] = 1;
//                to_eliminate[i+2][j] = 1;
//            }
//        }
//    }
//}
//void eliminate_marked(int board[MAX_SIZE][MAX_SIZE], int n, int m, int to_eliminate[MAX_SIZE][MAX_SIZE]) {
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < m; j++) {
//            if (to_eliminate[i][j]) {
//                board[i][j] = 0;
//            }
//        }
//    }
//}
//int main() {
//    int n, m;
//    scanf("%d %d", &n, &m);
//    int board[MAX_SIZE][MAX_SIZE];
//    int to_eliminate[MAX_SIZE][MAX_SIZE] = {0};
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < m; j++) {
//            scanf("%d", &board[i][j]);
//        }
//    }
//    mark_eliminations(board, n, m, to_eliminate);
//    eliminate_marked(board, n, m, to_eliminate);
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < m; j++) {
//            printf("%d ", board[i][j]);
//        }
//        printf("\n");
//    }
//    return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//#define MAX_STUDENTS 100
//#define MAX_SUBJECTS 4
//#define MAX_NAME_LENGTH 11
//
//typedef struct {
//    char name[MAX_NAME_LENGTH];
//    int scores[MAX_SUBJECTS];
//    int count;
//} Student;
//
//int find_student(Student students[], int count, const char *name) {
//    for (int i = 0; i < count; i++) {
//        if (strcmp(students[i].name, name) == 0) {
//            return i;
//        }
//    }
//    return -1;
//}
//
//int compare_names(const void *a, const void *b) {
//    return strcmp(((Student *)a)->name, ((Student *)b)->name);
//}
//
//int main() {
//    FILE *input = fopen("input.txt", "r");
//    FILE *output = fopen("output.txt", "w");
//    if (!input || !output) {
//        perror("Error opening file");
//        return EXIT_FAILURE;
//    }
//    Student students[MAX_STUDENTS];
//    int student_count = 0;
//    char name[MAX_NAME_LENGTH], subject[MAX_NAME_LENGTH];
//    int score;
//    while (fscanf(input, "%s %s %d", name, subject, &score) == 3) {
//        int index = find_student(students, student_count, name);
//        if (index == -1) {
//            strcpy(students[student_count].name, name);
//            memset(students[student_count].scores, 0, sizeof(students[student_count].scores));
//            students[student_count].count = 0;
//            index = student_count++;
//        }
//        if (students[index].count < MAX_SUBJECTS) {
//            students[index].scores[students[index].count++] = score;
//        }
//    }
//    qsort(students, student_count, sizeof(Student), compare_names);
//    for (int i = 0; i < student_count; i++) {
//        double sum = 0;
//        for (int j = 0; j < MAX_SUBJECTS; j++) {
//            sum += students[i].scores[j];
//        }
//        double average = sum / MAX_SUBJECTS;
//        fprintf(output, "%s %.2f\n", students[i].name, average);
//    }
//    fclose(input);
//    fclose(output);
//    return 0;
//}

//#include <stdio.h>
//#include <limits.h>
//#define MAX_SIZE 10
//void find_min_points(int arr[MAX_SIZE][MAX_SIZE], int n, int m) {
//    int row_min[MAX_SIZE];
//    int col_min[MAX_SIZE];
//    // 初始化行最小值和列最小值
//    for (int i = 0; i < n; i++) {
//        row_min[i] = INT_MAX;
//    }
//    for (int j = 0; j < m; j++) {
//        col_min[j] = INT_MAX;
//    }
//    // 找到每行的最小值
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < m; j++) {
//            if (arr[i][j] < row_min[i]) {
//                row_min[i] = arr[i][j];
//            }
//        }
//    }
//    // 找到每列的最小值
//    for (int j = 0; j < m; j++) {
//        for (int i = 0; i < n; i++) {
//            if (arr[i][j] < col_min[j]) {
//                col_min[j] = arr[i][j];
//            }
//        }
//    }
//    // 查找并输出最小点
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < m; j++) {
//            if (arr[i][j] == row_min[i] && arr[i][j] == col_min[j]) {
//                printf("%d %d %d\n", arr[i][j], i + 1, j + 1);
//            }
//        }
//    }
//}
//
//int main() {
//    int n, m;
//    scanf("%d %d", &n, &m);
//    int arr[MAX_SIZE][MAX_SIZE];
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < m; j++) {
//            scanf("%d", &arr[i][j]);
//        }
//    }
//    find_min_points(arr, n, m);
//    return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <ctype.h>
//#include <stdbool.h>
//
//#define MAX_WORDS 100
//#define MAX_WORD_LENGTH 20
//#define MAX_ERROR_WORDS 50
//
//void to_lowercase(char *str) {
//    for (int i = 0; str[i]; i++) {
//        str[i] = tolower(str[i]);
//    }
//}
//
//bool is_word_in_list(char *word, char words[MAX_WORDS][MAX_WORD_LENGTH], int word_count) {
//    for (int i = 0; i < word_count; i++) {
//        if (strcasecmp(word, words[i]) == 0) {
//            return true;
//        }
//    }
//    return false;
//}
//
//int compare_words(const void *a, const void *b) {
//    return strcmp((const char *)a, (const char *)b);
//}
//
//void extract_word(char *line, char *word, int *index) {
//    int j = 0;
//    while (line[*index] && !isalpha(line[*index])) {
//        (*index)++;
//    }
//    while (line[*index] && isalpha(line[*index])) {
//        word[j++] = tolower(line[*index]);
//        (*index)++;
//    }
//    word[j] = '\0';
//}
//
//int main() {
//    FILE *words_file = fopen("words.txt", "r");
//    FILE *in_file = fopen("in.txt", "r");
//    if (!words_file || !in_file) {
//        perror("Error opening file");
//        return EXIT_FAILURE;
//    }
//    char words[MAX_WORDS][MAX_WORD_LENGTH];
//    int word_count = 0;
//    // 读取词汇表
//    while (fscanf(words_file, "%s", words[word_count]) != EOF && word_count < MAX_WORDS) {
//        word_count++;
//    }
//    fclose(words_file);
//    char error_words[MAX_ERROR_WORDS][MAX_WORD_LENGTH];
//    int error_count = 0;
//    char line[256];
//    char word[MAX_WORD_LENGTH];
//    // 读取文章并检查单词
//    while (fgets(line, sizeof(line), in_file)) {
//        int index = 0;
//        while (line[index]) {
//            extract_word(line, word, &index);
//            if (word[0] && !is_word_in_list(word, words, word_count)) {
//                strcpy(error_words[error_count++], word);
//            }
//        }
//    }
//    fclose(in_file);
//    // 按字典顺序排序错误单词
//    qsort(error_words, error_count, MAX_WORD_LENGTH, compare_words);
//    // 输出错误单词
//    for (int i = 0; i < error_count; i++) {
//        printf("%s\n", error_words[i]);
//    }
//    return 0;
//}