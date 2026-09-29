#include <stdio.h>
int main() {
    /*
    Ta có khai báo

    int dùng để gọi số nguyên
    %d là định dạng số nguyên cho int

    float dùng để gọi số thập phân 
    %f là định dạng số thập phân cho float

    double dùng để khai báo số chính xác gấp đôi float (sau dấu phẩy từ 15-16 số)
    %lf (long float) là định dạng cho double

    char dùng để khai báo 1 kí tự và dùng dấu ''
    %c là định dạng cho char
      VD char name[]
    có [] là tạo 1 mảng giúp lưu trữ nhiều hơn 1 giá trị
    %s (string) là định dạng cho 1 dãy kí tự

    char = '\0'; là bất kì giá trị nào trong biến char đều trở thành tập rỗng
    */
  int age = 18;
  float gpa = 3.9;
  int quantity = 100;
  float temperature = 26.5;
  double pi = 3.14159265358979; 
  char name = 'A';
  printf("Hom nay toi %d tuoi\n", age);
  printf("Hoc ki nay toi co diem trung binh la%.1f\n", gpa);
   // Khi thêm ".1" vào %.1f thì làm tròn hàng phần chục
  printf("Cua hang chung ta co %d san pham\n", quantity);
  printf("Nhiet do trung binh ngoai troi la %.1f°C\n", temperature);
  // Để ghi kí hiệu độ ° thì giữ phím Alt và nhập bàn phím số là 0176
  printf("Ta co so Pi la %.14lf\n", pi);
  printf("Diem so DH toi mong muon la %c", name);
    return 0;
}