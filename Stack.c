#include<stdio.h>
#include<string.h>
#define MaxLength 100

typedef int ElementType;
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

int mucUutien(char op) {
   if (op=='+' || op=='-')
       return 1;
   else if (op=='*' || op=='/')
       return 2;
}

void chuyenHauto(char trungto[], char hauto[]) {
    Stack S;
    makenullStack(&S);
    int i = 0;
    hauto[0] = '\0'; //Tránh cho thành chuỗi rác
    while(trungto[i] != '\0') {
        int c = trungto[i];
        if((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z')) {
            int len = strlen(hauto);
            hauto[len] = c;
            hauto[len + 1] = '\0';
        } else if(c == '(') {
            push(c, &S);
        } else if(c == ')') {
            while(emptyStack(S) != 1 && top(S) != '(') {
                char t = top(S);
                pop(&S);
                int len = strlen(hauto);
                hauto[len] = t;
                hauto[len + 1] = '\0';
            }
        pop(&S); //Xóa kí tự '(' theo yêu cầu đề bài
        } else if (c == '+' || c == '-' || c == '/' || c == '*') {
            while(emptyStack(S) != 1 && top(S) != '(' && 
            mucUutien(c) <= mucUutien(top(S))) {
                int t = top(S);
                pop(&S);
                int len = strlen(hauto);
                hauto[len] = t;
                hauto[len + 1] = '\0';
            }
        push(c, &S);
        }
    i++;
    }
    while(emptyStack(S) != 1) { // Đưa tất cả các toán tử còn lại vào ngăn xếp
        char t = top(S);
        pop(&S);
        int len = strlen(hauto);
        hauto[len] = t;
        hauto[len + 1] = '\0';
    }
}

void inThaplucphan(int n) {
    Stack S;
    Stack *pS = &S;
    makenullStack(pS);
    while(n > 0) {
        int temp = n % 16;
        if(temp < 10) {
            push(temp + '0', pS);
        } else {
            push(temp - 10 + 'A', pS);
        }
        n = n / 16;
    }
    while(emptyStack(S) == 0) {
        printf("%c", top(S));
        pop(pS);
    }
    
}

int ktChuoi() {
    Stack S;
    Stack *pS = &S;
    makenullStack(pS);
    char chuoi[100];
    fgets(chuoi, 100, stdin);
    if(chuoi[strlen(chuoi) - 1] == '\n') chuoi[strlen(chuoi) - 1] = '\0';
    int i = 0;
    while(chuoi[i] != '\0') {
        if(chuoi[i] == '(') {
            push('(', pS);
        } else if(chuoi[i] == ')') {
            if(emptyStack(S) == 1) {
                return 0;
            } else {
                pop(pS);
            }
        }
        i++;
    }
    if(emptyStack(S) == 1) {
        return 1;
    } else {
        return 0;
    }
}

float tinhGiatri(char st[]) {
    Stack S;
    makenullStack(&S);
    int i = 0;
    while(st[i] != '\0') {
        int temp = st[i] - '0';
        if(temp >= 0 && temp <= 9) {
            push(temp, &S);
        }
        float a = 0, b = 0;
        switch (st[i]) {
            case '+':
                a = top(S);
                pop(&S);
                b = top(S);
                pop(&S);
                push(b + a, &S);
                break;
            case '-':
                a = top(S);
                pop(&S);
                b = top(S);
                pop(&S);
                push(b - a, &S);
                break;
            case '/':
                a = top(S);
                pop(&S);
                b = top(S);
                pop(&S);
                push(b/a, &S);
                break;
            case '*':
                a = top(S);
                pop(&S);
                b = top(S);
                pop(&S);
                push(b * a, &S);
                break;
        }
        i++;
    }
    return top(S);
}

int main() {
    /*
    char trungto[30],hauto[30];
    fgets(trungto,30,stdin);
    if(trungto[strlen(trungto)-1]=='\n'){       //input ((2-3)+4) * (a - 3 * b)
        trungto[strlen(trungto)-1]='\0';
    }
    chuyenHauto(trungto,hauto);
    puts(hauto);
    */

    /*	
    int n;
    scanf("%d",&n);     //input 1234567
    inThaplucphan(n);
    */

    /*	
    if (ktChuoi()){
        printf("Chuoi ngoac dung");
    }                                      //input (((a * 2 - 4)*(3/4)(1+3*b)))
    else{
        printf("Chuoi ngoac khong dung");
    }
    */

    /*	
    char st[20];
    fgets(st,20,stdin);
    if(st[strlen(st)-1]=='\n'){         //input 28-45* +
        st[strlen(st)-1]='\0';
    }
    float gt=tinhGiatri(st);
    printf("%.1f",gt);
    */


    return 0;
}