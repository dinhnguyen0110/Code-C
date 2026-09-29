#include <stdio.h>
#include <string.h>
#include <malloc.h>

int main () {
    int x = 1;
    int y = 0;
    if(y++) {
        printf("%d\n", y);
    }
    printf("%d", ++x);
    return 0;
}