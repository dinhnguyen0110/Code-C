#include <stdio.h>

int main () {
    int n;
    printf("Nhap n: ");
    scanf("%d", &n);
    int win[n];

    for(int i = 0; i < n; i++) {
        printf("win[%d]: ", i);
        scanf("%d", &win[i]);
    }

    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(win[i] == win[j]) {
                //dồn mảng sang trái
                for(int t = j; t <= n-1; t++) {
                    win[t] = win[t + 1];
                }
                n--; // giảm kích thước mảng
                j--; // kiểm tra lại vị trí j sau khi dồn mảng
            }
        }
    }

    for(int i = 0; i < n; i++) {
            printf("%d ", win[i]);
    }
    
    return 0;
}