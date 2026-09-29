#include <stdio.h>

int main () {

    int n;

    printf("Nhap so n: ");
    scanf("%d", &n);

    //Build cay thong
    for(int i = 1; i <= n; i++) {
      for(int k = 1; k <= n - i; k ++) {
        printf(" ");
      }
      for(int j = 1; j <= 2*i - 1; j++) {
        printf("*");
      }
      printf("\n");
    }

      //Build cot cua cay thong
      for(int i = 1; i <= n/2; i ++) {
        for(int j = 1; j < n; j++) {
          printf(" ");
         }
        printf("*");
        printf("\n");
      }

    return 0;
}