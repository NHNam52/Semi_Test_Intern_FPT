#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <stdint.h>

int option1 = 0, option2 = 0;
int temp = 0;
int m, n, z, k = 0, ena = 0, check = 0, i = -1;
int x1 = 0, x2 = 0, x3 = 0, x4 = 0, x5 = 0, x6 = 0;

typedef struct{
  char id[30];
  char name[50];
  char password[30];
  char age[3];
  bool sex;
  int money;
} account;              

  account cus[100];

// MENU
void main_menu(){
  system("cls");
  printf("\n_____________*TECHCOMBANK WELCOME!*_____________");
  printf("\n");
  printf("\n                  1. SIGN UP                      \n");
  printf("\n                  2. SIGN IN                      \n");
  printf("\n                  3. SHUTDOWN                     \n");
  printf("\n________________________________________________");
  printf("\n");
  printf("\nPLEASE SELECT !                                ");
}

// OPTIONS
void sub_menu(){
  system("cls");
  printf("\n____________________ OPTIONS ____________________\n");
  printf("\n1. INFOMATION AND BALANCE.\n");
  printf("\n2. WITHDRAW CASH.\n");
  printf("\n3. DEPOSIT.\n");
  printf("\n4. UPDATE PERSONAL INFOMATION.\n");
  printf("\n5. SIGN OUT.\n");
  printf("\n_________________________________________________\n");
  printf("\nPLEASE SELECT !                                 "); 
}

// 1. ĐĂNG KÝ
void registration(){
  i++;
  system("cls");
  printf("\n____________________ SIGN UP ____________________\n");
  printf("\n");
  printf("ID                           :     ");
  scanf("%s", &cus[i].id);
  printf("\nPASSWORD                     :     ");
  scanf("%s", &cus[i].password);
  printf("\n");
  printf("NAME                         :     ");
  scanf("\n");
  scanf("%[^\n]s", &cus[i].name);
  printf("\nAGE                          :     ");
  scanf("%s", &cus[i].age);
  printf("\nSEX (0.MALE / 1.FEMALE)      :     ");
  scanf("%d", &cus[i].sex);
  printf("\nDEPOSITS                     :     ");
  scanf("%d", &cus[i].money);
  printf("____________________________________");
  printf("\n\nSAVE AND LEAVE (1)           :     "); 
}

// 1. KIỂM TRA TÀI KHOẢN
void balance(){
      system("cls");
      printf("\n____________________ INFOMATION AND BALANCE ____________________\n");
      printf("\nID                  :     %s\n", cus[i].id);
      printf("\nNAME                :     %s\n",cus[i].name);
      printf("\nAGE                 :     %s\n",cus[i].age);
      printf("\nSEX                 :     ");
      if(cus[i].sex == 0) printf("MALE");
      else printf("FEMALE");
      printf("\n\nCURRENT BALANCE     :     %d VND\n", cus[i].money);
}

// SỐ TỜ TIỀN CẦN THỐI
int remoney(int cash){
  temp = 0;
  x1 = 0, x2 = 0, x3 = 0, x4 = 0, x5 = 0, x6 = 0;
  x1 = cash / 500000;
  temp = cash % 500000;
  if(temp >=  200000 || temp < 500000){
    x2 = temp / 200000;
    temp = temp % 200000;
  }
  if(temp >= 100000 || temp < 200000){
    x3 = temp / 100000;
    temp = temp % 100000; 
  }
  if(temp >= 50000 || temp < 100000){
  x4 = temp / 50000;
  temp = temp % 50000; 
  }
  if(temp >= 20000 || temp < 50000){
  x5 = temp / 20000;
  temp = temp % 20000; 
  }
  if(temp >= 10000 || temp < 20000){
  x6 = temp / 10000;
  }
  printf(" %d  -  500.000  |  %d  -  200.000  |  %d  -  100.000  |  %d  -  50.000  |  %d  -  20.000  |  %d  -  10.000\n", x1, x2, x3, x4, x5, x6); 
}

// 2. RÚT TIỀN MẶT
void cashing(){
  bool com = 0;
  int money1 = 0;
    system("cls");
    printf("\n___________________________________ NOTICE ___________________________________\n");
    printf("\n> THE AMOUNT TO WITHDRAW IS A MULTIPLE OF 10000 VND <");
    printf("\n> THE MINIMUM AMOUNT REMAINING IN THE ACCOUNT MUST BE GREATER THAN 50000 <\n");
    printf("______________________________________________________________________________\n");
    printf("\nENTER THE AMOUNT TO WITHDRAW CASH     :     ");
    scanf("%d", &money1);
    int temp = cus[i].money - money1;
    if(temp >= 50000){
      if(money1 % 10000 != 0){
        printf("\n> FAIL! THE AMOUNT TO BE WITHDRAWN IS INVALID\n");
        Sleep(4000);
        return cashing();
      }
      else{
        cus[i].money -= money1;
        system("cls");
        printf("\n___________________________________ WITHDRAW CASH ___________________________________\n");
        printf("\n                             WITHDRAW CASH SUCCESSFULLY !\n");
        printf("\n                             CURRENT BALANCE: %d VND", cus[i].money);
        printf("\n\n____________________________________ CASH OPTION ____________________________________\n\n");
        remoney(money1);

        com = 1;
        }  
      }
      else{
        printf("\n> FAIL! THE AMOUNT TO BE WITHDRAWN EXCEEDS THE SPECIFIED BALANCE !\n");
        Sleep(4000);
      }
  if(com == 0){
    return cashing();
  }
}

// 3. NỘP TIỀN
void deposit(){
  int money2;
  system("cls");
  printf("\n______________________________ DEPOSIT ______________________________\n");
  printf("\nPLEASE ENTER THE AMOUNT     :     ");
  scanf("%d", &money2);
  cus[i].money += money2;
  system("cls");
  printf("\n______________________________ DEPOSIT ______________________________\n");
  printf("\n                       DEPOSIT SUCCESSFULLY !\n");
  printf("\n                       CURRENT BALANCE : %d VND", cus[i].money);
}

// 4. CẬP NHẬT
void update(){
  int up = 0;
  char pass1[30], pass2[30];
    system("cls");
    printf("\n______________________________ UPDATE ______________________________\n");
    printf("\nPLEASE SELECT THE INFORMATION WANT TO UPDATE :\n");
    printf("\n1. ID\n");
    printf("\n2. NAME\n");
    printf("\n3. PASSWORD\n");
    printf("\n4. AGE\n");
    printf("\n5. SEX\n");
    printf("______________________\n");
    printf("\nPLEASE SELECT !      ");
    scanf("%d", &up);
    switch(up){
        case 1: system("cls");
                printf("\nNEW ID: ");
                scanf("\n");
                scanf("%[^\n]s", &cus[i].id);
                printf("\nUPDATE SUCCESSFULLY!\n");
                break;

        case 2: system("cls");
                printf("\nNEW NAME: ");
                scanf("\n");
                scanf("%[^\n]s", &cus[i].name);
                printf("\nUPDATE SUCCESSFULLY!\n");
                break;

        case 3: system("cls");
                printf("\nNEW PASSWORD             : ");
                scanf("%s", &pass1);
                printf("\nCONFIRM NEW PASSWORD     : ");
                scanf("%s", &pass2);
                if(strcmp(pass1,pass2)==0){
                  strcpy(cus[i].password, pass2);
                  printf("\nUPDATE SUCCESSFULLY!\n");
                }
                else{
                  printf("\nUPDATE FAILURE!\n");
                }
                break;

        case 4: system("cls");
                printf("\nNEW AGE: ");
                scanf("%s", &cus[i].age);
                printf("\nUPDATE SUCCESSFULLY!\n");
                break;
        
        case 5: system("cls");
                printf("\nNEW SEX: 0. MALE   1. FEMALE  ");
                scanf("%d", &cus[i].sex);
                printf("\nUPDATE SUCCESSFULLY!\n");
                break;

        default: printf("PLEASE SELECT THE INFORMATION WANT TO UPDATE :\n");
                 scanf("%d", &up);
                 break;
    }
}

void dangnhap1(){
  while(k==0){
          sub_menu(); 
          scanf("%d", &option2);
          switch (option2)
          {
            case 1: balance();
                    printf("\n__________________________________________\n");
                    printf("\nDO YOU WANT TO EXIT ? PRESS (1)          ");
                    scanf("%d", &z);
                    if(z == 1) break;

            case 2: cashing();
                    printf("\n__________________________________________\n");
                    printf("\nDO YOU WANT TO EXIT ? PRESS (1)          ");
                    scanf("%d", &z);
                    if(z == 1) break;
            
            case 3: deposit();
                    printf("\n__________________________________________\n");
                    printf("\nDO YOU WANT TO EXIT ? PRESS (1)          ");
                    scanf("%d", &z);
                    if(z == 1) break;

            case 4: update();
                    printf("\n__________________________________________\n");
                    printf("\nDO YOU WANT TO EXIT ? PRESS (1)          ");
                    scanf("%d", &z);
                    if(z == 1) break;

            case 5: system("cls");
                    printf("\n_______________________________________________________\n");
                    printf("\nARE YOU SURE YOU WANT TO SIGN OUT ? PRESS (1)         ");
                    scanf("%d", &z);
                    if(z == 1){
                      k = 1;
                      main_menu();
                      break;
                    }
            if(k==1){
               break;
            }
           
          }
          }
}

// 2. ĐĂNG NHẬP
void access(){
  i = 0;
  check = 0;
  char id[30];
  char password[30];
  system("cls");
  printf("\n____________________ SIGN IN ____________________\n");
  printf("\nID                  :          ");
  scanf("%s", &id);
  printf("\nPASSWORD            :          ");
  scanf("%s", &password);
  while(i < 100){
    if(strcmp(id,cus[i].id)==0 && strcmp(password,cus[i].password)==0){
      system("cls");
      printf("\n____________________ ANNOUNCEMENT ____________________\n");
      printf("\n\n                SIGN IN SUCCESSFULLY!\n");
      Sleep(2000);
      check = 1;
      dangnhap1();
      break;
    }
    i++;
  }
  
    if(check != 1){
      system("cls");
      printf("____________________ WARRNING ____________________\n");
      printf("\n\n         SIGN IN FAILED. PLEASE TRY AGAIN!\n");
      Sleep(2000);
      return access();  
    } 
}
int main(){
ena = 0;
main_menu();
do{
  k = 0;
  scanf("%d", &option1);
  switch(option1){
  case 1: registration();
          scanf("%d", &m);
          switch(m){
            case 1: system("cls");
                    printf("\n____________________ SIGN UP ____________________\n");
                    printf("\n");
                    printf("\n              SIGN UP SUCCESSFULLY!\n\n");
                    Sleep(1500);
                    main_menu();
                    break;
            case 2: main_menu();
                    break;
          }
  break;
  case 2: access();
          break;

  case 3: system("cls");
          printf("\n_______________________________________________________\n");
          printf("\nARE YOU SURE YOU WANT TO SHUTDOWN ? PRESS (1)         ");
          scanf("%d", &z);
          if(z == 1){
          ena = 1;
          break;
          }
}
}
while(ena == 0);
  return 0;
}