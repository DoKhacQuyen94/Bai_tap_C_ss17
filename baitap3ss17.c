#include <stdio.h>
#include <string.h>
#include <ctype.h>
void nhapChuoi(char *str);
int demSoTu(char *str);
void inHoa(char *str);
void soSanh(char *str, char *newStr);
int demSoTu(char *str);
void inChuoiDaoNguoc(char *str);
void themChuoiVaoChuoiBanDau(char *str, char * newStr);
int main() {
    char str[1000];
    char newStr[1000];
    int choice;

    do {
        printf("\nMENU\n");
        printf("1. Nhập vào chuỗi\n");
        printf("2. In ra chuỗi đảo ngược\n");
        printf("3. Đếm số lượng từ trong chuỗi\n");
        printf("4. Nhập vào chuỗi khác, so sánh chuỗi đó với chuỗi ban đầu\n");
        printf("5. In hoa tất cả chữ cái trong chuỗi\n");
        printf("6. Nhập vào chuỗi khác và thêm chuỗi đó vào chuỗi ban đầu\n");
        printf("7. Thoát\n");
        printf("Lựa chọn của bạn: ");
        scanf("%d", &choice);
        getchar(); 

        switch (choice) {
            case 1:
                nhapChuoi(str);
                break;
            case 2:
                inChuoiDaoNguoc(str);
                printf("Chuỗi đảo ngược: %s\n", str);
                break;
            case 3:
                printf("Số lượng từ trong chuỗi: %d\n", demSoTu(str));
                break;
            case 4:
                soSanh(str,newStr);
                break;
            case 5:
                inHoa(str);
                printf("Chuỗi in hoa: %s\n", str);
                break;
            case 6:
                themChuoiVaoChuoiBanDau(str,newStr);
                break;
            case 7:
                printf("Thoát chương trình.\n");
                break;
            default:
                printf("Lựa chọn không hợp lệ. Vui lòng chọn lại.\n");
        }
    } while (choice != 7);

    return 0;
}

void nhapChuoi(char *str) {
    printf("Nhap vao chuoi: ");
    fgets(str, 100, stdin);
}
void inChuoiDaoNguoc(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}
int demSoTu(char *str) {
    int count = 0;
    int inWord = 0;
    while (*str !='\0') {
        if (isspace(*str)) {
            inWord = 0;
        } else if (!inWord) {
            inWord = 1;
            count++;
        }
        str++;
    }
    return count;
}

void inHoa(char *str) {
    while (*str) {
        *str = toupper(*str);
        str++;
    }
}
void soSanh(char *str, char *newStr){
    printf("Nhập vào chuỗi khác: ");
    fgets(newStr, sizeof(newStr), stdin);
    newStr[strcspn(newStr, "\n")] = '\0'; 
    if (strlen(newStr) > strlen(str)) {
        printf("Chuỗi mới dài hơn chuỗi ban đầu.\n");
    } else if (strlen(newStr) < strlen(str)) {
        printf("Chuỗi mới ngắn hơn chuỗi ban đầu.\n");
    } else {
        printf("Chuỗi mới có độ dài bằng chuỗi ban đầu.\n");
    }
}
void themChuoiVaoChuoiBanDau(char *str, char * newStr){
    printf("Nhập vào chuỗi khác: ");
    fgets(newStr, sizeof(newStr), stdin);
    newStr[strcspn(newStr, "\n")] = '\0';
    strcat(str, newStr);
    printf("Chuỗi sau khi thêm: %s\n", str);
}