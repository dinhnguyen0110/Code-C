#include <stdio.h>
int main () {
  int a, b;
  printf("Nhap do dai canh a, b: \n;");
  scanf("%d%d", &a, &b);
  printf("Chu vi hinh chu nhat canh a, b la:%d\n",2*(a+b)); 
  printf("Dien tich hinh chu nhat canh a, b la:%d", a*b);
    return 0;
}