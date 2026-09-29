#include <stdio.h>

int main () {
    int h;
    scanf("%d", &h);

    for(int dong = 0; dong <= h; dong++) { // vẽ số dòng của tam giác (chạy dọc)
        int gt1 = 1;
        for(int i = dong; i > 0; i--) {
            gt1 = gt1 * i;
        }
        for(int vt = 0; vt <= dong; vt++) { // vị trí (chạy ngang)
            int gt2 = 1, gt3 = 1;
            for(int j = vt; j > 0; j--) {
                gt2 = gt2 * j;
            }
            for(int k = dong - vt; k > 0; k--) {
                gt3 = gt3 * k;
            }
            printf("%d ", gt1 / (gt2 * gt3));
        }
        printf("\n");
    }
    
    return 0;
}