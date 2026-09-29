#include <stdio.h>

int main () {
    int a, b;
    scanf("%d%d", &a, &b);
    int sumA = 0, sumB = 0;
    for(int i = 2; i < a; i++) {
        if(a % i == 0) {
            sumA += i;
        }
    }
    for(int i = 2; i < b; i++) {
        if(b % i == 0) {
            sumB += i;
        }
    }
    if(sumA == b && sumB == a) {
        printf("YES");
    } else {
        printf("NO");
    }
    
    return 0;
}