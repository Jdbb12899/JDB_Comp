/***********************************************
Author: <Jacob Blumsack>
Date: <04/13/2020>
Purpose: <object oriented coding practice>
Sources of Help: <class lecture videos and ppts.>
***********************************************/

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

class Player {
public:
    virtual int getGuess();                                //declare virtual funct. getGuess
    int guess;
};

class HumanPlayer : public Player{
public:
    HumanPlayer() : Player() {};                           //Constructor for HumanPlayer
    int getGuess();                                        //getGuess
};

class ComputerPlayer : public Player {
public:
    ComputerPlayer() : Player() {};                        //Constructor for ComputerPlayer
    int getGuess();                                        //getGuess
    void setHigh(int High);                                //adjust high range
    void setLow(int Low);                                  //adjust low range
    int high = 100;                                        //default high range
    int low = 1;                                           //default low range
};

bool checkForWin(int guess, int answer, ComputerPlayer& CP)
{
    if (answer == guess)                                    //check if answer matches guess
    {
        cout << "You're right! You win!" << endl << endl;
        return true;
    }
    else if (answer < guess) {                                
        CP.setHigh(guess);                                  //set CP high range based off new info
        cout << "Your guess is too high." << endl;          //if answer is higher, tell user
    }
    else {
        CP.setLow(guess);                                   //set CP low range based off new info
        cout << "Your guess is too low." << endl;           //if answer is lower, tell user
    }
    return false;
}
// The play function takes as input two Player objects.
void play(Player& player1, Player& player2, ComputerPlayer& CP) {
    int answer = 0, guess = 0;
    answer = rand() % 100;
    bool win = false;

    while (!win)
    {
        cout << "Player 1's turn to guess." << endl;        //take turns having users guess
        guess = player1.getGuess();
        win = checkForWin(guess, answer, CP);
        if (win) return;

        cout << "Player 2's turn to guess." << endl;        //as long as user1 is not correct, go to next user
        guess = player2.getGuess();
        win = checkForWin(guess, answer, CP);
    }
}

int main(int argc, char* argv[]) {
    //human and computer users for each required occasion
    HumanPlayer HP1;
    HumanPlayer HP2;
    ComputerPlayer CP;
    ComputerPlayer CP1;
    ComputerPlayer CP2;

    cout << "Human vs Human" << endl;
    play(HP1, HP2, CP);

    cout << "Human vs Computer" << endl;
    play(HP1, CP1, CP);

    cout << "Computer vs Computer" << endl;
    play(CP1, CP2, CP);
    return 0;
}

int Player::getGuess() {
    return 0;                                               //Player getGuess only returns 0
}

int HumanPlayer::getGuess() {
    cout << "Human Player enter a guess: ";                 //prompt Human User
    cin >> guess;                                           //retrieve guess
    return guess;                                           //return guess
}

int ComputerPlayer::getGuess() {
    return rand() % high + low;                             //Computer user's guess is random number
}

void ComputerPlayer::setHigh(int High) {
    high = High;                                            //set new high range
}

void ComputerPlayer::setLow(int Low) {
    low = Low;                                              //set new low range
}

/*
Computing III -- COMP.2010 Honor Statement
The practice of good ethical behavior is essential for maintaining
good order in the classroom, providing an enriching learning
experience for students, and as training as a practicing computing
professional upon graduation. This practice is manifested in the
University’s Academic Integrity policy. Students are expected to
strictly avoid academic dishonesty and adhere to the Academic
Integrity policy as outlined in the course catalog. Violations will
be dealt with as outlined therein.
All programming assignments in this class are to be done by the
student alone. No outside help is permitted except the instructor and
approved tutors.
I certify that the work submitted with this assignment is mine and was
generated in a manner consistent with this document, the course
academic policy on the course website on Blackboard, and the UMass
Lowell academic code.
Date: 04/13/2020
Name:Jacob Blumsack
*/