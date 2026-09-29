#include <stdio.h>
#include <math.h>

int main () {

    double radius = 0.0;
    double area = 0.0; //Diện tích hình tròn
    double surfaceArea = 0.0; //Diện tích bề mặt hình cầu
    double volume = 0.0; //Thể tích hình cầu
    double PI = 3.14159;

    printf("Enter the radius: ");
    scanf("%lf", &radius);

    area = PI * pow(radius, 2); //CT tính diện tích hình tròn
    surfaceArea = 4 * PI * pow(radius, 2); // CT tính diện tích bề mặt hình cầu
    volume = (4.0 / 3.0) * PI * pow(radius, 3);

    printf("Your area is: %.2lf\n", area);
    printf("Your surfaceArea is: %.2lf\n", surfaceArea);
    printf("Your volume is: %.2lf", volume);

    return 0; 
}