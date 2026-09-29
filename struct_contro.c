#include <stdio.h>
#include <string.h>
#include <malloc.h>

typedef struct {
    char *HoTen;
    float LT, TH;
    char *DiemChu;
} SinhVien;

void nhapDS(SinhVien *pL, int n) {
    
    for(int i = 0; i < n; i++) {
        pL[i].HoTen = NULL;
        pL[i].HoTen = (char*)malloc(sizeof(char)*100);
        pL[i].DiemChu = NULL;
        pL[i].DiemChu = (char*)malloc(sizeof(char)*5);
        fgets(pL[i].HoTen, 100, stdin);
        if(pL[i].HoTen[strlen(pL[i].HoTen) - 1]  == '\n') {
            pL[i].HoTen[strlen(pL[i].HoTen) - 1] = '\0';
        }
        scanf("%f%f", &pL[i].LT, &pL[i].TH);
        getchar(); //xóa bộ nhớ đệm, nếu fgets có \n thì sẽ xóa
        float DT = pL[i].LT + pL[i].TH;
        if(DT >= 9.0) {
            strcpy(pL[i].DiemChu, "A");
        } else if (DT >= 8.0 && DT < 9.0) {
            strcpy(pL[i].DiemChu, "B+");
        } else if (DT >= 7.0 && DT < 8.0) {
            strcpy(pL[i].DiemChu, "B");
        } else if (DT >= 6.0 && DT < 7.0) {
            strcpy(pL[i].DiemChu, "C+");
        } else if (DT >= 5.0 && DT < 6.0) {
            strcpy(pL[i].DiemChu, "C");
        } else if (DT >= 4.5 && DT < 5.0) {
            strcpy(pL[i].DiemChu, "D+");
        } else if (DT >= 4.0 && DT < 4.5) {
            strcpy(pL[i].DiemChu, "D");
        } else {
            strcpy(pL[i].DiemChu, "F");
        }
    }
}

void inDS(SinhVien *L, int n) {
    for(int i = 0; i < n; i++) {
        printf("%s ", L[i].HoTen);
        printf("%.3f %.3f ", L[i].LT, L[i].TH);
        printf("%s", L[i].DiemChu);
        printf("\n");
        free(L[i].HoTen);
        free(L[i].DiemChu);
    }
}

int main () {
    int n;
    SinhVien *list;
    scanf("%d ",&n);
    list = (SinhVien *) malloc (sizeof(SinhVien)*n);
    nhapDS(list,n);
    inDS(list,n);
    free(list);

    return 0;
}