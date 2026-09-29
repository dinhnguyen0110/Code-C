#include <stdio.h>

int main () {
    int n;
    scanf("%d", &n);
    int hoan_hao = 1;
    //ý a (Số hoàn hảo)
    for(int i = 2; i < n; i++) {
        if(n % i == 0) {
            hoan_hao += i;
        }
    }
    if(hoan_hao == n) {
        printf("%d la so hoan hao\n", n);
    }
    //ý b (Số nguyên tố)
    int temp = 0;
    for(int i = 2; i * i <= n; i++) {      
        if(n % i == 0) {
            temp = 1;
            break;
        }
    }
        if(temp == 0) {
        printf("%d la so nguyen to\n", n);
        }
    
    //ý c (Số chính phương)
    for(int i = 1; i * i <= n; i++) {
        if(i*i == n) {
            printf("%d la so chinh phuong\n", n);
        }
    }
    
    return 0;
}