#include <stdio.h>

int laSoNguyenTo(int x);
void ngto(int win[], int n);
int Tong(int win[], int n);

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
    printf("Cac so co trong mang la: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", win[i]);
    }

    // ý b
    ngto(win, n);

    //ý c
    printf("\nTong cac so nguyen to trong mang: %d",Tong(win, n));

    return 0;
}

// hàm kiểm tra số nguyên tố
int laSoNguyenTo(int x) {
    if (x < 2) return 0;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0)
            return 0;
    }
    return 1;
}

// hàm in số nguyên tố trong mảng
void ngto(int win[], int n) {
    printf("\nCac so nguyen to trong mang la: ");
    for (int i = 0; i < n; i++) {
        if (laSoNguyenTo(win[i])) {
            printf("%d ", win[i]);
        }
    }
}

// hàm tính tổng các số nguyên tố trong mảng
int Tong(int win[], int n) {
    int sum = 0;
    for(int i = 0; i < n; i++) {
        if(laSoNguyenTo(win[i])){
        sum += win[i];
        }
    }
    return sum;
}