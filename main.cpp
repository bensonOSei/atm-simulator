#include <iostream>

using namespace std;
void topMenu();
void signin();
void deposit();
void withdraw();
void balance();


//Array index represents account numbers AND array elements represents account balance
int account[10] = {1000,1000,1000,1000,1000,1000,1000,1000,1000,1000}; 
int enteredId = -1, depositAmnt, withdrawAmnt;

//error message to show when there is an invalid input
void errorMsg() {
    cout << "INVALID INPUT, PLEASE TRY AGAIN \n";
}


//validation of sign in before you perform any transaction
void signinValid() {
    if (enteredId == -1) {
        cout << "PLEASE SIGN IN TO GET ACCESS \n";
        topMenu();
    }
}

//the main function
int main()
{
    //calling the first menu
    topMenu();

    return 0;
}

//the initial menu users will see
void topMenu() {

    int option;//to accept option inputs

    start:
    cout << "IGNORE OPTION .1 IF ALREADY SINGED IN \n";
    cout << "\n";
    cout << "1. SIGN IN \n";
    cout << "2. BALANCE \n";
    cout << "3. DEPOSIT \n";
    cout << "4. WITHDRAW \n";
    cout << "5. EXIT \n";

    cin >> option;

    if (option == 1) {
        signin();
    }
    else if (option == 2) {
        balance();
    }
    else if (option == 3) {
        deposit();
    }
    else if (option == 4) {
        withdraw();
    }
    else if (option == 5) {
        exit(0);
    }
    else {
        cout << "Invalid Input, try again \n";
        goto start;
    }
}

//to complete the sign in task
void signin() {
    cout << "PLEASE ENTER YOUR ID: ";
    cin >> enteredId;

    //sign in input validation
    if (enteredId > 9) {
        cout << "Invalid Id, Try again \n";
        topMenu();
    }

    else {

        topMenu();
    }
}

//function for checking balance
void balance() {
    signinValid();
    cout << "Your current balance is " << account[enteredId]<< "USD"<< endl;
    if (account[enteredId] < 100) {
        cout << "LOW BALANCE \n";
    }
    topMenu();
}


//function for making deposits
void deposit() {

    int newBalance;
    signinValid();

    cout << "HOW MUCH DO YOU WISH TO DEPOSIT? \n";
    cin >> depositAmnt;

    //Deposit validation
    if (depositAmnt < 0) {
        for (int tries = 1; tries < 3; tries++) {
            cout << "INVALID AMOUNT \n";
            cout << "PLEASE TRY AGAIN \n";

            cout << "ENTER AMOUNT TO DEPOSIT: ";
            cin >> depositAmnt;

            if (tries == 2) {
                cout << "SESSION TERMINATED \n";
                topMenu();
            }
        }
    }

    else {
        newBalance = depositAmnt + account[enteredId];
        account[enteredId] = newBalance;

        cout << "YOUR NEW BALANCE IS "<< account[enteredId]<< endl;
    }

    topMenu();
}

//function for making withdrawals
void withdraw() {
    int newBalance;

    signinValid();
    cout << "HOW MUCH DO YOU WISH TO WITHDRAW? \n";
    cin >> withdrawAmnt;

    newBalance = account[enteredId] - withdrawAmnt;
    account[enteredId] = newBalance;
    cout << "CURRENT BALANCE IS " << account[enteredId] << " USD \n";

    topMenu();
}
