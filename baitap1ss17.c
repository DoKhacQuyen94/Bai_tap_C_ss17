#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void displayMenu(void);
void nhapMang(int**arr,int *soPhanTu);
void inMang(int **arr,int soPhanTu);
void doDaiMang(int soPhanTu);
void tongPhanTuMang(int **arr,int soPhanTu);
void phanTuLonNhat(int **arr,int soPhanTu);
int main(){
    int *arr;
    int choice;
    int soPhanTu=0;
    do{
        displayMenu();
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            nhapMang(&arr,&soPhanTu);
            break;
        case 2:
            inMang(&arr,soPhanTu);
            break;
        case 3:
            doDaiMang(soPhanTu);
            break;  
        case 4:
            tongPhanTuMang(&arr,soPhanTu);
            break;
        case 5:
            phanTuLonNhat(&arr,soPhanTu);
            break;
        case 6:
            printf("Bạn đã thoát\n");
            break;
        default:
            break;
        }
    } while (choice!=6);
    free(arr);
    return 0;
}
void displayMenu(void){
    printf("\n----------MENU----------\n");
    printf("1.Nhập vào số phần tử và từng phần tử\n");
    printf("2.Hiển thị các phần tử trong mảng\n");
    printf("3.Tính độ dài mảng\n");
    printf("4.Tính tổng các phần tử trong mảng\n");
    printf("5.Hiển thị phần tử lớn nhất\n");
    printf("6.Thoát\n");
    printf("Lựa chọn của bạn: ");
}
void nhapMang(int **arr, int *soPhanTu) {
    printf("Nhập vào số phần tử: ");
    scanf("%d", soPhanTu);
    *arr = (int *)malloc(*soPhanTu * sizeof(int));
    for (int i = 0; i < *soPhanTu; i++) {
        printf("Nhập phần tử thứ %d: ", i + 1);
        scanf("%d", (*arr) + i);
    }
    
}
void inMang(int **arr,int soPhanTu){
    printf("Phần tử của mảng: \n");
    for (int i = 0; i< soPhanTu; i++){
        printf("Phần tử thứ %d: %d\n",i+1,*((*arr) + i));
    }
}
void doDaiMang(int soPhanTu){
    printf("Mảng có độ dài là: %d", soPhanTu);

}
void tongPhanTuMang(int **arr,int soPhanTu){
    int sum=0;
    for (int i = 0; i< soPhanTu; i++){
        sum += *((*arr) + i);
    }
    printf("Tổng các phần tử trong mảng là: %d",sum);
}
void phanTuLonNhat(int **arr,int soPhanTu){
    int max=**arr;
    for (int i = 0; i< soPhanTu; i++){
        if (max <*((*arr) + i)){
            max =*((*arr) + i);  
        }
    
    }
    printf("Phần tử lớn nhất trong mảng là: %d",max);
}