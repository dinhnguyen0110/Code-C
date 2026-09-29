#include<stdio.h>
#include<string.h>
#define MaxLength 100
typedef char ElementType;

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

typedef struct {
    ElementType Elements[MaxLength]; //Khởi tạo Stack
    int Top_idx;
} Stack;

int fullStack(Stack S){
    return S.Top_idx==0;
}

int emptyStack(Stack S) {
    return S.Top_idx==MaxLength;
}
void makenullStack(Stack *pS) {
    pS->Top_idx = MaxLength;
}
void push(ElementType X, Stack *pS){
    if (fullStack(*pS)) {
        printf("Loi! Ngan xep day!");
    } else {
        pS->Top_idx=pS->Top_idx-1;
        pS->Elements[pS->Top_idx]=X;
    }
}
void pop(Stack *pS) {
    if (!emptyStack(*pS)) {
        pS->Top_idx=pS->Top_idx+1;
    } else {
        printf("Loi! Ngan xep rong!");
    }
}
ElementType top(Stack S) {
    if(!emptyStack(S)) {
        return S.Elements[S.Top_idx];
    } else {
        printf("Loi! Ngan xep rong");
    }
}

int main() {
    
    char st[100];
    fgets(st,100,stdin);
    if(st[strlen(st) - 1] == '\n') st[strlen(st) - 1] = '\0';
    Queue Q; //đọc xuôi;
    makenullQueue(&Q);
    Stack S; //đọc ngược
    makenullStack(&S);
    int i = 0;
    while(st[i] != '\0') {
        char c = st[i];
        if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
            if(c >= 'A' && c <= 'Z') {
                c = c - 'A' + 'a';
            }
            enQueue(c, &Q);
            push(c, &S);
        }
    i++;
    }
    int temp = 1;
    while(!emptyQueue(Q) && !emptyStack(S)) {
        if(top(S) == front(Q)) {
            deQueue(&Q);
            pop(&S);
        } else {
            temp = 0;
            break;
        }
    }
    if(temp) {
        printf("\"%s\" doc xuoi va doc nguoc nhu nhau", st);
    } else {
        printf("\"%s\" doc xuoi khac doc nguoc", st);
    }
    
    return 0;
}