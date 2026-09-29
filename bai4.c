#include <stdio.h>
#include <math.h>

void MaxMin(int win[], int n);
void ChanLe (int win[], int n);
void SoLuong (int win[], int n); 

int main () {
  
  int n;
  printf("Nhap so n: ");
  scanf("%d", &n);

  int win[n];
  for (int i = 0; i < n; i++) {
    printf("Nhap win[%d]: ", i);
    scanf("%d", &win[i]);
  }
  
  // ý a
  MaxMin(win, n);

  // ý b
  ChanLe(win, n);

  // ý c
  SoLuong(win, n);

 return 0;
}

  // hàm tìm max và min
void MaxMin(int win[], int n) {
  int max = win[0];
  int min = win[0];
  for (int i = 1; i < n; i++) {
      if(win[i] >= max) max = win [i];
      if(win[i] <= min) min = win [i];
    }
    printf("Max trong mang la: %d\n", max);
    printf("Min trong mang la: %d\n", min);
}

// hàm tính tổng chẵn lẻ
void ChanLe (int win[], int n) {
  int chan = 0;
  int le = 0;
  for(int i = 0; i < n; i++) {
    if(abs(win[i]) % 2 == 0) chan += win[i];
    if(abs(win[i]) % 2 == 1) le += win[i];
  }
  printf("Tong cac so chan la: %d\n", chan);
  printf("Tong cac so le la: %d\n", le);
}

// hàm tính số lượng số dương, âm và số 0
void SoLuong (int win[], int n) {
  int duong = 0;
  int am = 0;
  int so_0 = 0;
  for(int i = 0; i < n; i++) {
    if(win[i] > 0) { 
      duong++;
    } else if (win[i] < 0) { 
      am++;
    } else { 
      so_0++;
    }
  }
  printf("So luong so duong trong mang la: %d\n", duong);
  printf("So luong so am trong mang la: %d\n", am);
  printf("So luong so 0 trong mang la: %d\n", so_0);
}