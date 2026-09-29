#include <stdio.h>
#include <math.h>

void triangle (float a, float b, float c, float max); 

int main () {

    float a, b, c;
    float max;
    printf("Nhap do dai lan luot 3 canh a, b ,c: \n");
    scanf("%f%f%f", &a, &b, &c);

    triangle(a, b, c, max); //Thuật toán để kiểm tra tam giác

    return 0;
}

void triangle (float a, float b, float c, float max) {

    //Tìm cạnh lớn nhất
    if (a == b && b == c && a ==c) {
        printf("3 canh co do dai bang nhau\n");
    } else if (a >= b && a >= c) {
        printf("a la canh lon nhat la %.2f\n", a);
        max = a;
    } else if (b >= c ) {
        printf("b la canh lon nhat la %.2f\n", b);
        max = b;
    } else {
        printf("c la canh lon nhat la %.2f\n", c);
        max = c;
    }

    //Kiểm tra có tạo thành một tam giác không
    if( a == max) {
        if (a <= b + c ){
            printf("3 canh a b c tao thanh mot tam giac ABC\n");
        } else {
            printf("3 canh a, b, c khong tao thanh mot tam giac\n");
        }
    } else if (b == max) {
         if (b <= a + c ){
            printf("3 canh a b c tao thanh mot tam giac ABC\n");
        } else {
            printf("3 canh a, b, c khong tao thanh mot tam giac\n");
        }
    } else if (c == max) {
         if (c <= b + a ){
            printf("3 canh a b c tao thanh mot tam giac ABC\n");
        } else {
            printf("3 canh a, b, c khong tao thanh mot tam giac\n");
        }
    }

    //Kiểm tra có phải tam giác đặc biệt không
    if ( a == b && a == c && b == c) {
        printf("ABC la tam giac deu\n");  
    } else if (b == c) {
        printf("ABC la tam giac can dinh A\n");
    } else if (a == c) {
        printf("ABC la tam giac can dinh B\n");
    } else if (a == b) {
        printf("ABC la tam giac can dinh C\n");
    } else if (a == sqrt(pow(b, 2) + pow(c, 2))) {
        printf("ABC la tam giac vuong tai B\n");
    } else if (b == sqrt(pow(a, 2) + pow(c, 2))) {
        printf("ABC la tam giac vuong tai B\n");
    } else if (c == sqrt(pow(b, 2) + pow(a, 2))) {
        printf("ABC la tam giac vuong tai C\n");
    } else {
        printf("ABC la tam giac thuong\n");
    }
 }