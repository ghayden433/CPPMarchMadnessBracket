#include <iostream>
using namespace std;
#include <time.h>  
#include <iomanip> 


int main() {
    srand (time(NULL));
    int dividend;
    int winner;
    int Teams[16] = {1, 16, 8, 9, 5, 12, 4, 13, 6, 11, 3, 14, 7, 10, 2, 15 };
    int Winnersrnd1[8];
    int Winnersrnd2[4];
    int Winnersrnd3[2];

    //for loop loops for every other Teams seed number
    for (int i = 0; i < 16; i = i + 2) {
        // dividend is the total of the two teams seed number, and it is used to be a divisor for prabbility
        dividend = Teams[i] + Teams[i + 1];
        //generates a random number from 1-17 
        int rando = (rand()%17) + 1;
        //if the random number chosen is less than the lower seed then the higher seed wins (lower seed has better probability to win)
        //for some reason I chose to add 100 to the value in order to denote a win, its used to check later.
        if (rando <= Teams[i]) {
            Teams[i + 1] = Teams[i + 1] + 100;
        }
        //vice verse of the if
        else {
            Teams[i] = Teams[i] + 100;
        }
    }

    //for every other element in teams
    for (int i = 0; i < 16; i = i + 2) {
        //if the team checked this iteration is a winner add them to the round 1 winner array 
        //remove 100 from the elment so they're not a winner this round  
        //print the winning seed number in parentheses and // then the loser: (win) // lose 
        if (Teams[i] > 50) {
            Winnersrnd1[i / 2] = Teams[i] - 100;
            cout << "(" << Teams[i] - 100 << ")" << " // " << Teams[i + 1] << "     ";
        }
        //same as the if statement above but if the other team is selected
        //printed as lose // (win)
        else {
            Winnersrnd1[i / 2] = Teams[i + 1] - 100;
            cout << Teams[i] << " // " << "(" << Teams[i + 1] - 100 << ")" << "     ";
        }
    }
    
    //output formatting to space the rounds out and center them
    cout << endl << endl << endl << "       ";




    for (int i = 0; i < 8; i = i + 2) {
        dividend = Winnersrnd1[i] + Winnersrnd1[i + 1];
        int rando = (rand() % dividend) + 1;
        if (rando <= Winnersrnd1[i]) {
            Winnersrnd1[i + 1] = Winnersrnd1[i + 1] + 100;
        }
        else {
            Winnersrnd1[i] = Winnersrnd1[i] + 100;
        }
    }


    for (int i = 0; i < 8; i = i + 2) {
        if (Winnersrnd1[i] > 50) {
            Winnersrnd2[i / 2] = Winnersrnd1[i] - 100;
            cout << "(" << Winnersrnd1[i] - 100 << ")" << " // " << Winnersrnd1[i + 1] << setw(20) << setfill(' ');
        }
        else {
            Winnersrnd2[i / 2] = Winnersrnd1[i + 1] - 100;
            cout << Winnersrnd1[i] << " // " << "(" << Winnersrnd1[i + 1] - 100 << ")" << setw(20) << setfill(' ');
        }
    }

    cout << endl << endl << endl << "                      ";



    for (int i = 0; i < 4; i = i + 2) {
        dividend = Winnersrnd2[i] + Winnersrnd2[i + 1];
        int rando = rand() % dividend;
        if (rando <= Winnersrnd2[i]) {
            Winnersrnd2[i] = Winnersrnd2[i] + 100;
        }
        else {
            Winnersrnd2[i + 1] = Winnersrnd2[i + 1] + 100;
        }
    }


    for (int i = 0; i < 4; i = i + 2) {
        if (Winnersrnd2[i] > 50) {
            Winnersrnd3[i / 2] = Winnersrnd2[i] - 100;
            cout << "(" << Winnersrnd2[i] - 100 << ")" << " // " << Winnersrnd2[i + 1] << setw(48) << setfill(' ');
        }
        else {
            Winnersrnd3[i / 2] = Winnersrnd2[i + 1] - 100;
            cout << Winnersrnd2[i] << " // " << "(" << Winnersrnd2[i + 1] - 100 << ")" << setw(48) << setfill(' ');
        }
    }


    cout << endl << endl << endl << "                                                 ";

    dividend = Winnersrnd3[0] + Winnersrnd3[1];
    int rando = (rand() % dividend) + 1;
    if (rando <= Winnersrnd3[0]) {
        cout << "(" << Winnersrnd3[0] << ")" << " // " << Winnersrnd3[1];
    }
    else {
        cout << Winnersrnd3[0] << " // " << "(" << Winnersrnd3[1] << ")";
    }


    cout << endl << endl << endl << endl << endl;

    return 0;
}
