#include <stdio.h>
#define MaxLength 300

typedef int ElementType;
typedef struct {
    ElementType Element[MaxLength];
    int Front, Rear;
} Queue;

void makenullQueue(Queue *pQ) {
    pQ->Front = -1;
    pQ->Rear = -1;
}

int emptyQueue(Queue Q) {
    return Q.Front == -1;
}

int fullQueue(Queue Q) {
    return ((Q.Rear - Q.Front + 1) == MaxLength);
}

void deQueue(Queue *pQ) {
    if(!emptyQueue(*pQ)) {
        pQ->Front = pQ->Front + 1;
        if(pQ->Front > pQ->Rear) {
            makenullQueue(pQ);
        }
    } else {
        printf("Hang doi rong!");
    }
}

void enQueue(ElementType x, Queue *pQ) {
    if(!fullQueue(*pQ)) {
        if(emptyQueue(*pQ)) {
            pQ->Front = 0;
        }
        if(pQ->Rear == MaxLength - 1) {
            for(int i = pQ->Front; i <= pQ->Rear; i++) {
                pQ->Element[i - pQ->Front] = pQ->Element[i];
            }
            pQ->Rear = MaxLength - pQ->Front - 1;
            pQ->Front = 0;
        }
        pQ->Rear = pQ->Rear + 1;
        pQ->Element[pQ->Rear] = x;
    } else {
        printf("Loi! Hang day");
    }
}

ElementType front(Queue Q) {
    return Q.Element[Q.Front];
}

void khachHangDoi(int khachHang, int thoiGianTBDen, Queue *pQ) {
    for(int i = 1; i <= khachHang; i++) {
        int temp = i * thoiGianTBDen;
        enQueue(temp, pQ);
    }
}

float tinhThoiGianCho(int thuNgan, int khachHang, int thoiGianTBDen, int thoiGianXuLy, Queue *pQ) {
    makenullQueue(pQ);
    int tongThoiGian = 0;
    khachHangDoi(khachHang, thoiGianTBDen, pQ);
    int quay[thuNgan];
    for(int i = 0; i < thuNgan; i++) {
        quay[i] = 0;
    }
    int i = 0;
    while(!emptyQueue(*pQ)) {
        int thoiGianDen = front(*pQ);
        deQueue(pQ);
        if(thoiGianDen < quay[i]) {
            int thoiGianCho = quay[i] - thoiGianDen;
            quay[i] += thoiGianXuLy;
            tongThoiGian += (thoiGianCho + thoiGianXuLy);
        } else {
            quay[i] = thoiGianDen + thoiGianXuLy;
            tongThoiGian += thoiGianXuLy;
        }
        i = (i + 1) % thuNgan;
    }
    return (float)(tongThoiGian / khachHang);
}

int main() {
    int khachHang, thuNgan, thoiGianXuLy, thoiGianTBDen, thoiGianX;
    scanf("%d", &khachHang);
    scanf("%d", &thuNgan);
    scanf("%d", &thoiGianXuLy);
    scanf("%d", &thoiGianTBDen);
    scanf("%d", &thoiGianX);
    Queue Q;
    makenullQueue(&Q);
    int temp = 0, soQuayCanMo;
    for(int i = 1; i <= thuNgan; i++) {
        float tgCho = tinhThoiGianCho(i, khachHang, thoiGianTBDen, thoiGianXuLy, &Q);
        printf("So quay: %d; Thoi gian cho trung binh: %.1f\n", i, tgCho);
        if(tgCho <= thoiGianX) {
            soQuayCanMo = i;
            temp = 1;
            break;
        }
    }
    if(temp) {
        printf("=> Sieu thi se mo %d quay", soQuayCanMo);
    } else {
        printf("Voi %d quay hien co, khach phai cho it nhat %.1f giay moi duoc phuc vu.", thuNgan, tinhThoiGianCho(thuNgan, khachHang, thoiGianTBDen, thoiGianXuLy, &Q));
    }
    
    return 0;
}