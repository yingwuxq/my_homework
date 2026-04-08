#include <stdio.h>

char a[50][50];

int check90(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] != a[j][n - 1 - i]) {
                return 0;
            }
        }
    }
    return 1;
}

int check180(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] != a[n - 1 - i][n - 1 - j]) {
                return 0;
            }
        }
    }
    return 1;
}

int check270(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] != a[n - 1 - j][i]) {
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf(" %c", &a[i][j]);
        }
    }
    
    if (n == 1) {
        printf("Yes\n");
        return 0;
    }
    
    if (check90(n) || check180(n) || check270(n)) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    
    return 0;
}