#include <stdio.h>

typedef struct {
    int prime;
    int count;
} Factor;

int main() {
    int n;
    scanf("%d", &n);
    
    Factor factors[100];
    int factorCount = 0;

    int temp = n;
    for (int i = 2; i * i<= temp; i++) {
        if (temp % i == 0) {
            factors[factorCount].prime = i;
            factors[factorCount].count = 0;
            while (temp % i == 0) {
                factors[factorCount].count++;
                temp /= i;
            }
            factorCount++;
        }
    }
    
    if (temp > 1) {
        factors[factorCount].prime = temp;
        factors[factorCount].count = 1;
        factorCount++;
    }
    
    for (int i = 0; i < factorCount; i++) {
        if (factors[i].count == 1) {
            printf("%d ", factors[i].prime);
        }
    }

    return 0;
}