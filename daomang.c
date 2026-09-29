#include <stdio.h>

int main () {

    int n, k;
    printf("Nhap so n va k: ");
    scanf("%d %d", &n, &k);
    int win[n];
    printf("Nhap cac phan tu cua mang: ");
    for(int i = 0; i < n; i++) {
        scanf("%d", &win[i]);
    }
    int temp = win[n-1];
    for(int i = 0; i < k; i++) {
    
    win[n-1] = 0;
        for(int j = n - 1 ; j > 0; j--) {
            if(j == 0) {
                win[0] = temp;
            }
            win[j] = win[j - 1];
        }
    }

    for(int i = 0; i < n; i++) {
        printf("%d ", win[i]);
    }
    printf("%d", temp);

    return 0;
}