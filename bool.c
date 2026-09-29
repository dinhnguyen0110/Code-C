#include <stdio.h>
#include <stdbool.h> // Sử dụng thư viện này để sử dụng bool

int main () {
    bool isOnline = true;
    /* bool là khai biến dạng đúng sai, xài %d
    Nếu đúng sẽ hiện giá trị là 1
    Nếu sai sẽ hiện giá trị là 0
     */
     if(isOnline){
        printf("You are ONLINE");
     }
     else{
        printf("You are OFFLINE");
     }
    return 0;
}