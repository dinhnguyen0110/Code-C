#include <stdio.h>
#include <windows.h> // Thư viện cho windows

int main () {

    for (int i = 10; i >= 0; i--) {
        Sleep(1000); //Vòng lặp sẽ dừng 1000 mili giây sau khi xong 1 lần
        printf("%d\n", i);
    }
    printf("HAPPY NEW YEAR!");
}