#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

//functions here
int getMenuChoice() {
    int choice;
    printf("CHOOSE FROM THE FOLLOWING\n");
    printf("1 -> Fast Cash\t\tWithdraw <- 2\n");
    printf("3 -> Deposit\t\tCheck Balance <- 4\n");
    printf("5 -> Get Card Back\n");

    printf("\nEnter choice: ");
    scanf("%d", &choice);

    return choice;
}

void getCardBack() {
    int isQuit = 0;
    printf("\nTHANK FOR USING OUR VIRTUAL BANK SYSTEM\n\n");
    printf("Goodbye!\n\n");
    
    printf("type anything then press ENTER to exit\n");
    scanf("%d", &isQuit);
    exit(0);
}

int fastCash() {
    int choice;
    printf("\nChoose an option to withdraw\n");
    printf("1 --> $20.00\t\t$40.00  <-- 2\n");
    printf("3 --> $80.00\t\t$100.00 <-- 4\n");

    printf("\nEnter Choice:  ");
    scanf("%d", &choice);

    return choice;

}

double withdraw() {
    double choice;
    printf("\nHow much money would you like to withdraw?:  ");
    scanf("%lf", &choice);

    return choice;

}

double deposit() {
    double choice;
    printf("\nHow much would you like to deposit?:  ");
    scanf("%lf", &choice);
    
    return choice;
}

void checkBalance(double balance) {
    printf("\nYour Balance: $%lf\n", balance);

}




int main() {


//variables
double balance = 1000;
char pin[5] = "0000";
int validPin = 0;
int chances = 1;
int wantReceipt = 0;
int menuChoice = 0;
double withdrawAmnt = 0;
double depositAmnt = 0;
int fastCashAmnt = 0;
int loopChecker = 0; // loop checker
int loopChecker2 = 0;
int random;







//keep checking for valid pin
while(validPin != 1){
    // 3 chances to enter pin correctly or exit the program
    if(chances > 3){
        printf("\nSorry you can't continue, contact your bank for assistance!\n\n");
        printf("type anything, then press ENTER to exit\n");
        scanf("%d", random);
        exit(0);
    }
    // prompt for pin
    printf("Please enter your 4 digit pin number: ");
    scanf("%s", pin);
        //check for valid pin length
        if (strlen(pin) != 4) {
            printf("\nInvalid PIN, try again . . .\n");
            chances = chances + 1;
        }
        else {
            printf("\nDo you want a receipt? ( 1 for YES and 2 for NO ): ");
            scanf("%d", &wantReceipt);
            validPin = 1; // Set validPin to 1 to exit the loop (valid pin found)
        }
}
    



//loop options until user wants to exit....
while (menuChoice != 5) {
    printf("\n");
    menuChoice = getMenuChoice(menuChoice);

    // menu choices here...
    //fast cash menu choice
    if (menuChoice == 1) {
        fastCashAmnt = fastCash();
        while (loopChecker != 1) {
            if (fastCashAmnt > balance) {
                printf("Not enough money in your account to withdraw!!\n");
            }
            else {
                    if (fastCashAmnt == 1)
                    {
                        printf("\nWithdrawing $20.....Success!\tTake your cash!!\n");
                        balance = balance - 20;
                    }
                    else if (fastCashAmnt == 2) {
                        printf("\nWithdrawing $40.....Success!\tTake your cash!!\n");
                        balance = balance - 40;
                    }
                    else if (fastCashAmnt == 3) {
                        printf("\nWithdrawing $80.....Success!\tTake your cash!!\n");
                        balance = balance - 80;
                    }
                    else if (fastCashAmnt == 4) {
                        printf("\nWithdrawing $100.....Success!\tTake your cash!!\n");
                        balance = balance - 100;
                    }
                    printf("\nYour new balance is... $%lf\n" , balance);
                loopChecker = 1;
            }
        }
        loopChecker = 0; //reset loop checker for more iterations
    }



    // withdraw menu choice
    else if (menuChoice == 2) {

        //checking if right amount of money in balance to withdraw
        while (loopChecker != 1) {
            withdrawAmnt = withdraw();
            if (withdrawAmnt > balance) {
                printf("Not enough money in your account to withdraw!!\n");
            }
            else {
                printf("\nWithdrawing $%lf.....Success!\tTake your cash!!\n", withdrawAmnt);
                balance = balance - withdrawAmnt;
                printf("\nYour new balance is... $%lf\n" , balance);
                loopChecker = 1;
            }
        }
        loopChecker = 0; //reset loop checker for more iterations 
    }
    //deposit menu choice
    else if (menuChoice == 3) {
        //deposit code
        depositAmnt = deposit();
        balance = balance + depositAmnt;
        printf("\nDepositing $%lf... COMPLETE! Your new balance is... $%lf\n", depositAmnt, balance);
    }

    // check balance menu choice
    else if (menuChoice == 4) {
        checkBalance(balance);
    }


    // get card back menu choice
    else if (menuChoice == 5) {

        if (wantReceipt == 1) {
        printf("\nPrinting Receipt....\n\n");
    }
        getCardBack();

    }
}
    
    return 0;
}