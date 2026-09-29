#include <stdio.h>
#include <string.h> // Cách fix hàm fgets

int main () {
    int age = 0;
    float gpa = 0.0f;
    char grade = '\0';
    char name[30] = "";
    printf("Enter your age: ");
    scanf("%d", &age);

    printf("Enter your gpa: ");
    scanf("%f", &gpa ); 

    printf("Enter your grade: ");
    scanf(" %c", &grade); // MẸO thêm khoảng trống trước %c để máy không tự nhập số vào bộ nhớ đệm

    getchar(); //Hàm này dùng để xóa kí tự dòng mới tự động thêm vào name
    printf("Enter your name: ");
    fgets(name, sizeof(name), stdin);
    /*scanf(" %s", &name); 
    scanf không thể đọc được khoảng trống, dấu cách
    
    Để có thể nhập tên đầy đủ cần hàm fgets (file get string)

    fgets(biến, size của biến, stdin); (stdin là standard input)
    MẸO để không phải nhập thủ công của kích thước biến là sử dụng 
    sizeof(tên biến)
    */

    /* Khi sử dụng hàm fgets thì sẽ để lại 1 dòng trống phía dưới tên khi in ra.
    Vì sau đuôi của hàm fgets là \n nên sẽ xuống dòng
    */
    // Cách fix
    name[strlen(name)-1] = '\0'; 
    // Ta gán cái đuôi của fgets là \0 để xóa cái xuống dòng

    printf("%s\n", name);
    printf("%d\n", age);
    printf("%.2f\n", gpa);
    printf("%c\n", grade);
    

    return 0;
}