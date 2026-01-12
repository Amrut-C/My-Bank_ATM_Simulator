#include<stdio.h>
#include<string.h>
#include<stdlib.h>

double balance = 0.0;

void heading() {
    printf("\n\n\t\t\t\t\tWelcome To\n");
    printf("\t\t\t\t\tM Y B A N K . . ! !\n");
}

void check_balance() {
    printf("\n\n\tAccount Balance : $%lf", balance);
}

void deposit(double amount) {
    if (amount > 0) {
        balance += amount;
        printf("\n\n\tBALANCE AFTER DEPOSIT: $%lf", balance);
        printf("\n\n\tDEPOSIT SUCCESSFUL...!");
    } else {
        printf("\n\n\tInvalid deposit amount!");
    }
}

void withdraw(double amount) {
    if (amount > 0 && balance >= amount) {
        balance -= amount;
        printf("\n\n\tBALANCE AFTER WITHDRAW: $%.2lf", balance);
        printf("\n\n\tWITHDRAWAL SUCCESSFUL!");
    } else {
        printf("\n\n\tInsufficient funds or invalid amount!");
    }
}

void check_current_balance() {
    printf("\n\n\tCurrent BALANCE: $%lf", balance);
}

int main() {
    int choice;
    int flag = 1;
    double deposit_amount, withdraw_amount;
    

    FILE *ptr = fopen("/tmp/History.txt", "a+");  
    
   
    if (ptr == NULL) {
        ptr = fopen("History.txt", "w+");  // Creates in current di
    }
    
    if (ptr == NULL) {
        printf("\n\n\tWARNING: History disabled (no write access)");
        ptr = NULL;  
    }
    
    heading();
    
    do {
        printf("\n\n\tEnter choice:\n");
        printf("\n\n\t1. Check Balance\n\n\t2. Deposit\n\n\t3. Withdraw\n\n");
        printf("\t4. Transaction History (if available)\n\n\t0. Exit\n");
        scanf("%d", &choice);
        
        if (ptr != NULL) {
            fprintf(ptr, "\n=== Transaction #%d ===\n", choice);
        }
        
        switch(choice) {
            case 1:
                printf("\n\n\tACCOUNT NO: 27092006");
                printf("\n\tACCOUNT OWNER: AMRUT CHOUDHARI");
                if (ptr) fprintf(ptr, "Account: 27092006 | AMRUT CHOUDHARI\n");
                check_balance();
                printf("\n\n<>><><><><><><><><><><><><><><><><><><>");
                break;
                
            case 2:
                printf("\n\n\tACCOUNT NO: 27092006");
                printf("\n\tACCOUNT OWNER: AMRUT CHOUDHARI");
                check_current_balance();
                printf("\n\tEnter amount to deposit: $");
                scanf("%lf", &deposit_amount);
                deposit(deposit_amount);
                if (ptr) {
                    fprintf(ptr, "Deposited: $%lf | Balance: $%lf\n", 
                           deposit_amount, balance);
                }
                printf("\n-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.");
                break;
                
            case 3:
                printf("\n\n\tACCOUNT NO: 27092006");
                printf("\n\tACCOUNT OWNER: AMRUT CHOUDHARI");
                check_current_balance();
                printf("\n\tEnter withdrawal amount: $");
                scanf("%lf", &withdraw_amount);
                withdraw(withdraw_amount);
                if (ptr) {
                    fprintf(ptr, "Withdrew: $%lf | Balance: $%lf\n", 
                           withdraw_amount, balance);
                }
                printf("\n_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*");
                break;
                
            case 4:
                if (ptr != NULL) {
                    rewind(ptr);
                    printf("\n\n\tTRANSACTION HISTORY:\n");
                    printf("===================================\n");
                    char ch;
                    while ((ch = fgetc(ptr)) != EOF) {
                        putchar(ch);
                    }
                    printf("\n===================================\n");
                } else {
                    printf("\n\n\tHistory unavailable (file access denied)");
                }
                break;
                
            case 0:
                printf("\n\n\tTHANK YOU! EXITING...");
                flag = 0;
                break;
                
            default:
                printf("\n\n\tInvalid choice! Enter 0-4.");
        }
    } while (flag);
    
    if (ptr != NULL) {
        fclose(ptr);
    }
    return 0;
}

