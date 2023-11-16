/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

void gameOver(int bal) {
    int balance = bal;
    cout << setfill('*') << setw(55) << "" << endl;
    cout << '*' << "      THANKS FOR PLAYING! Your final balance was: $" << balance << " " << '*' << endl;
    cout << setfill('*') << setw(55) << "" << endl;
}

int main()
{
    // my variables muhaha
    string name;
    int balance = 0;
    int bet = 0;
    bool Playing = true;
    srand(time(0));
    int guessNumber = 0;
    int winNumber = 0;
    string playOrLa;
    
    
    // start menu stuff
    cout << setfill('*') << setw(42) << "" << endl;
    cout << setfill(' ') << setw(20) << left << '*' << setw(21) << "CASINO GAME" << '*' << endl;
    cout << setfill('*') << setw(42) << "" << endl;
    
    // more start menu stuff but inputs
    cout << "Enter your name: ";
    cin >> name; // could use getline(cin, name)
    cout << "\nEnter deposit amount to play game: ";
    cin >> balance;

    // more start menu stuff + rules
    cout << setfill('*') << setw(42) << "" << endl;
    cout << setfill(' ') << setw(21) << left << '*' << setw(20) << "GAME RULES" << '*' << endl;
    cout << setfill('*') << setw(42) << "" << endl;
    
    cout << "1. Choose any number between 1 and 10.\n";
    cout << "2. If you win you will get 10 times the amount of money you bet.\n";
    cout << "3. If you bet on the wrong number, you will lose the amount of money you bet.\n";
    
    // while playing
    while(Playing == true) {
        cout << endl << "Your current balance is $ " << balance << endl;
        cout << name << ", enter the amount you wish to bet: $";
        cin >> bet;
        balance = balance - bet; // takes bet separately
        cout << "Guess a number to bet on between 1 - 10: ";
        cin >> guessNumber;
        winNumber = rand()%10+1;
        // winNumber = 5; this is for testing
        if(winNumber == guessNumber) {
            cout << "You won! You got a 10x multiplier on your bet and won $" << (bet*10) << endl;
            bet = bet * 10;
            balance = balance + bet;
            bet = 0;
        } else {
            cout << "Bad luck! You lost $" << bet << endl;
            bet = 0;
        }
        cout << endl <<"The winning number was: " << winNumber << endl;
        if (balance <= 0) {
            cout << "You have no more money left to play.\n" << endl;
            Playing = false;
            gameOver(balance);
        } else {
            cout << "Do you wish to play again? (Y/N): ";
            cin >> playOrLa;
            if (playOrLa == "Y" || playOrLa == "y") {
                Playing = true;
            } else {
                Playing = false;
                gameOver(balance);
            }
        }
        
    }

    return 0;
}
