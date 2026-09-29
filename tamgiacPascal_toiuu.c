#include <stdio.h>

int main() {
    int a[] = {1, 2, 3, 4, 5};
    int *p = a;

    int x = *p++ + *(p + 1);
    int y = (*p)++ + *++p;
    int z = *p + *(p - 2);

    printf("%d %d %d\n", x, y, z);
    printf("%d %d %d %d %d", a[0], a[1], a[2], a[3], a[4]);

    return 0;
}