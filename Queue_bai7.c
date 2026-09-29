#include<stdio.h>
#define MaxLength 100

typedef int ElementType;
typedef struct {
    ElementType Element[MaxLength];
    int Front, Rear;
}Queue;

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
            for(int i = pQ->Front; i <= pQ->Rear;i++) {
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

int main() {
    Queue st1, st2; //st1 là công việc, st2 là ưu tiên
    makenullQueue(&st1);
    makenullQueue(&st2);
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        int temp;
        scanf("%d", &temp);
        enQueue(temp, &st1);
    }
    for(int i = 0; i < n; i++) {
        int temp;
        scanf("%d", &temp);
        enQueue(temp, &st2);
    }
    int count = 0;
    while(!emptyQueue(st1) && !emptyQueue(st2)) {
        if(front(st1) ==  front(st2)) {
            deQueue(&st1);
            deQueue(&st2);
            count++;
        } else {
            ElementType task = front(st1);
            deQueue(&st1);
            enQueue(task, &st1);
            count++;
        }
    }
    
    printf("%d", count);
    
    return 0;
}