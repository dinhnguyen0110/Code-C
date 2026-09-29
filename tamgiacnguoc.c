#include <stdio.h>

int main () {

    int h;
    printf("Nhap chieu cao cua tam giac: ");
    scanf("%d", &h);

    for (int i = 0; i <= h; i++) {
         for (int j = 1; j <= i; j++) 
            printf("*");
            printf("\n");
    }
    return 0;
}