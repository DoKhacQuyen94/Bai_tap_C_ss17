#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
void displayMenu(void);
void nhapChuoi(char *chuoi);
void inChuoi(char *chuoi);
void demChuCai(char *chuoi);
void demChuSo(char *chuoi);
void demKyTuDacBiet(char *chuoi);
int main(){
    char chuoi[100] = "";
    int choice;
    do
    {
        displayMenu();
        scanf("%d",&choice);
        getchar();
        switch (choice){
        case 1:
            nhapChuoi(chuoi);
            break;
        case 2:
            inChuoi(chuoi);
            break;
        case 3: 
            demChuCai(chuoi);
            break;
        case 4:
            demChuSo(chuoi);
            break;
        case 5:
            demKyTuDacBiet(chuoi);
            break;
        default:
            break;
        }
    } while (choice !=6);

    return 0 ;
}
void displayMenu(void){
    printf("\n----------MENU----------\n");
    printf("1.Nhập vào chuỗi\n");
    printf("2.In ra chuỗi\n");
    printf("3.Đếm số lượng chữ cái trong chuỗi và in ra\n");
    printf("4.Đếm số lượng chữ số trong chuỗi và in ra\n");
    printf("5.Đếm số lượng ký tự đặc biệt trong chuỗi và in ra\n");
    printf("6.Thoát\n");
    printf("Lựa chọn của bạn: ");
}
void nhapChuoi(char *chuoi) {
    printf("Nhap vao chuoi: ");
    fgets(chuoi, 100, stdin);
}
void inChuoi(char *chuoi){
    printf("Chuoi hien tai: %s\n", chuoi);
}
void demChuCai(char *chuoi) {
    int count = 0;
    while (*chuoi != '\0') {
        if(isalpha(*chuoi)){
            count++;
        }
        chuoi++;
    }
    printf("So luong chu cai: %d\n", count);
}
void demKyTuDacBiet(char *chuoi) {
    int count = 0;
    while (*chuoi != '\0') {
        if (!isalpha(*chuoi) && !isdigit(*chuoi) && !isspace(*chuoi)) {
            count++;
        }
        chuoi++;
    }
    printf("So luong ky tu dac biet: %d\n", count);
}
void demChuSo(char *chuoi) {
    int count = 0;
    while (*chuoi != '\0') {
        if (isdigit(*chuoi)) {
            count++;
        }
        chuoi++;
    }
    printf("So luong chu so: %d\n", count);
}
