#include <stdio.h>

int main () {
 
  int n;
  double sum = 0;

  printf("Nhap so n: ");
  scanf("%d", &n);

  for ( int i = 1; i <= n; i++) {
      sum += (double) 1 / i;
  }

  printf("Gia tri cua tong la:%.3lf", sum);

  return 0;
}