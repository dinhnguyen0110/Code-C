#include <stdio.h>
#include <string.h>

typedef struct {
    char MSSV[10];
    char HoTen[50];
    float DiemLT, DiemTH1, DiemTH2;
} SinhVien;

typedef struct {
    SinhVien A[40];
    int n;
} DanhSach;

DanhSach dsRong() {
    DanhSach R;
    R.n = 0;
    return R;
}

void chenCuoi(DanhSach *pL) {
    scanf("%s", pL->A[pL->n].MSSV);
    getchar(); // Hút ký tự khoảng trắng/enter sau khi nhập MSSV
    
    fgets(pL->A[pL->n].HoTen, 40, stdin);
    // Xóa dấu enter ở cuối chuỗi do fgets để lại
    if(pL->A[pL->n].HoTen[strlen(pL->A[pL->n].HoTen) - 1] == '\n') {
        pL->A[pL->n].HoTen[strlen(pL->A[pL->n].HoTen) - 1] = '\0';
    }
        
    scanf("%f", &pL->A[pL->n].DiemLT);
    scanf("%f", &pL->A[pL->n].DiemTH1);
    scanf("%f", &pL->A[pL->n].DiemTH2);
    pL->n++;
}

void nhapDS(DanhSach *pL, int n) {
    *pL = dsRong();
    for(int i = 0; i < n; i++) {
        chenCuoi(pL);
    }
}

void inDS(DanhSach L) {
    for(int i = 0; i < L.n; i++) {
        printf("%s - %s - %.2f - %.2f - %.2f\n", L.A[i].MSSV, L.A[i].HoTen, L.A[i].DiemLT, L.A[i].DiemTH1, L.A[i].DiemTH2);
    }    
}

void timSV(char *mssv, DanhSach L) {
    int found = 0;
    
    for(int i = 0; i < L.n; i++) {
        if(strcmp(L.A[i].MSSV, mssv) == 0) {
            printf("Tim thay sinh vien %s. Thong tin sinh vien:\n", L.A[i].MSSV);
            printf("%s - %s - %.2f - %.2f - %.2f\n", L.A[i].MSSV, L.A[i].HoTen, L.A[i].DiemLT, L.A[i].DiemTH1, L.A[i].DiemTH2);
            found = 1;
            break;
        }
    }
    
    if (found == 0) {
        printf("Khong tim thay sinh vien co MSSV: %s\n", mssv);
    }
}

void svDat(DanhSach L) {
    float tong = 0;
    int temp = 0;
    printf("")
    for(int i = 0; i < L.n; i++) {
        tong = L.A[i].DiemLT + L.A[i].DiemTH1 + L.A[i].DiemTH2;
        if(tong >= 4.0) {
            temp = 1;
        }
    }
    if(temp == 1) {
        printf("Sinh vien DAT\n");
        for(int i = 0; i < L.n; i++) {
            tong = L.A[i].DiemLT + L.A[i].DiemTH1 + L.A[i].DiemTH2;
            if(tong >= 4.0) {
                printf("%s - %s - %.2f - %.2f - %.2f\n", L.A[i].MSSV, L.A[i].HoTen, L.A[i].DiemLT, L.A[i].DiemTH1, L.A[i].DiemTH2);
            }
        }
    } else {
        printf("Khong co sinh vien DAT\n");
    }
}

int main () {
    int n;
    scanf("%d", &n);
    DanhSach L;
    nhapDS(&L, n);
    inDS(L);
    
    char mssv[10]; // Sửa thành mảng ký tự để lưu chuỗi
    scanf("%s", mssv); // Nhập chuỗi
    timSV(mssv, L);
    
    return 0;
}