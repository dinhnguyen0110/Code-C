#include <stdio.h>

// Hàm tìm ƯCLN (GCD) bằng thuật toán Euclid
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Hàm tìm BCNN (LCM)
int lcm(int a, int b) {
    return (a / gcd(a, b)) * b;  // Chia trước để tránh tràn số
}

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    
    printf("UCLN: %d\n", gcd(a, b));
    printf("BCNN: %d\n", lcm(a, b));

    return 0;
}