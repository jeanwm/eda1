#include <stdio.h>

int main() {
    int n = 4;
    int v[] = {10, 15, 3, 7};
    int k = 17;
    
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (v[i] + v[j] == k) {
                printf("True");
                return 0;
            }
        }
    }

    printf("False");
    return 0;
}