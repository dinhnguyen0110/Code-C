#include <stdio.h>

void change(int win[], int n);
int Find(int win[], int n, int x, int trai, int phai);

int main () {
    
    int n;
    printf("Nhap so phan tu cua mang: ");
    scanf("%d", &n);
    int win[n];
    for(int i = 0; i < n; i++) {
        printf("Nhap vao win[%d]: ", i);
        scanf("%d", &win[i]);
    }

    // ý a
    change(win, n);

    // ý b
    printf("Mang sau khi sap xep: \n");
    for(int i = 0; i < n; i++) {
        printf("%d ", win[i]);
    }

    // ý c
    int x;
    printf("\nNhap so can tim: ");
    scanf("%d", &x);
    if(Find(win, n, x, 0, n-1) == -1) {
        printf("Khong tim thay %d trong mang\n", x);
    } else {
        printf("Tim thay %d tai vi tri %d\n", x, Find(win, n, x, 0, n-1));
    }
    
    return 0;
}

void change(int win[], int n) {
    for (int i = 0; i < n -1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (win[j] < win[min]) {
                min = j;
            }
        }
        int temp = win[i];
        win[i] = win[min];
        win[min] = temp;
    }

}

int Find(int win[], int n, int x, int trai, int phai) {

    if(trai > phai) {
        return -1;
    }

    int giua = (trai + phai) / 2;

    if(win[giua] == x) {
        return giua;
    } else if (win[giua] > x) { //x lớn hơn 1/2 dãy cần tìm nên sẽ chia 1/2 nửa kia tiếp
        return Find(win, n, x, trai, giua - 1);
    } else { // tương tự
        return Find(win, n, x, giua + 1, phai);
    }
}    