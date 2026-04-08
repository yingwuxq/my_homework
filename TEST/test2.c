#include <stdio.h>

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    
    int first, second;
    double first_val, second_val;

    for (int i = 0; i < n; i++) {
        double sum = 0.0;
        for (int j = 0; j < k; j++) {
            int x;
            scanf("%d", &x);
            sum += x;
        }
        
        double avg = sum / k;
        
        if (avg > first_val) {
            second = first;
            second_val = first_val;
            first = i;
            first_val = avg;
        } else if (avg == first_val) {
        } else if (avg > second_val) {
            second = i;
            second_val = avg;
        } else if (avg == second_val) {
        }
    }
    
    printf("%d\n%d\n", first, second);
    
    return 0;
}