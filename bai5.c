#include <stdio.h>

int main () {
  int n;
  printf("Nhap so n: ");
  scanf("%d", &n);

  int win[n][n];
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      printf("Nhap vao win[%d][%d]: ", i, j);
      scanf("%d", &win[i][j]);
    }
  }

  // ý a
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      printf("%d ", win[i][j]);
    }
    printf("\n");
  }

  // ý b, c
  int cheoChinh = 0;
  int cheoPhu = 0;
  for(int i = 0; i < n; i++) cheoChinh += win[i][i];
  for(int i = n - 1; i >= 0; i--) cheoPhu += win[i][i];
  printf("Tong duong cheo chinh la: %d\n", cheoChinh);
  printf("Tong duong cheo phu la: %d\n", cheoPhu);

  // ý d
  int max = win[0][0];
  int i_;
  int j_;
  for(int i = 0; i < n; i++) {
    for(int j = 1; j < n; j++) {
      if(win[i][j] >= max) {
        max = win[i][j];
        i_ = i;
        j_ = j;
      }
    }
  }
  printf("Max trong mang la: %d, vi tri trong mang la: win[%d][%d]\n", max, i_, j_);


  return 0;
}