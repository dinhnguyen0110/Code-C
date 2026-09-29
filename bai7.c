#include <stdio.h>

int main () {
    
    int n, f0, f1, f2;
    printf("Nhap so n: ");
    scanf("%d", &n);
    f0 = 0;
    f1 = 1;
    printf("%d %d ", f0, f1);
    for(int i = 0; i < n - 2; i++) {
        f2 = f0 + f1;
        printf("%d ", f2);
        f0 = f1;
        f1 = f2;
    }

    return 0;
}