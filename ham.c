#include <stdio.h>

void win(char name[], int age, float score); // Gọi hàm nguyên mẫu (Có tác dụng như khai báo)

int main () {
    
    char name[] = "Nguyen";
    int age = 18;
    float score = 9.75;
    win(name, age, score);
    return 0;
}

void win(char name[], int age, float score) {
    printf("Hello %s\n", name);
    printf("You will turn %d next year\n", age);
    printf("Your score today is %.2f, it is a great one\n", score);
    printf("\n");
 }