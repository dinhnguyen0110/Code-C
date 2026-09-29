#include <stdio.h>

int main () {
    int m, n;
    printf("Nhap so m va n: ");
    scanf("%d %d", &m, &n);

    int win[m][n];
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            printf("Nhap vao win[%d][%d]: ", i, j);
            scanf("%d", &win[i][j]);
        }
    }
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
      printf("%d ", win[i][j]);
    }
    printf("\n");
  }
    int max;
    int i_, j_;
    // ý a
    printf("Tong phan tu cua tung hang la: \n");
    int sum = 0;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            sum += win[i][j];
            max = sum;
        if(sum >= max) {
            max = sum;
            i_ = i;
            j_ = j;
        }
        }
        
        printf("Tong hang %d la: %d\n", i, sum);
        sum = 0;
    }

    // ý b
    printf("Tong phan tu cua tung cot la: \n");
    for(int j = 0; j < n; j++) {
        for(int i = 0; i < m; i++) {
            sum += win[i][j];
        } 
        printf("Tong cot %d la: %d\n", j, sum);
        sum = 0;
    }

    // ý c
    printf("Hang %d co tong lon nhat trong mang la: %d\n", i_, max);

    return 0;
}