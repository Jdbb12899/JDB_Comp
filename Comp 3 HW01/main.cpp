/***********************************************
Author: <Jacob Blumsack>
Date: <02/02/2020>
Purpose: <An introduction to cpp and its more commonly used terms>
Sources of Help: <Class ppts, and posted cpp files>
Time Spent: <2hrs>
***********************************************/

#include <iostream>

using namespace std;

int main(int argc, const char* argv[]) {
    int min_number, max_number, num_guesses, guess, counter, i = 0;
    char repeat = 'y';
        while (repeat == 'y' || repeat == 'Y') {   //replay or not
            cout << "First, let's set up the game." << endl;
            cout << "Please enter the minimum number, a positive integer:";
            cin >> min_number;
            while (min_number <= 0) {                   //ensure min number is in spec
                cout << "Please enter the minimum number, a positive integer:";
                cin >> min_number;
            }
            cout << "Please enter the maximum number, which is greater than the minimum and less than 1000:";
            cin >> max_number;
            while (max_number < min_number || max_number > 1000) {  //ensure max number is in spec
                cout << "Please enter the maximum number, which is greater than the minimum and less than 1000:";
                cin >> max_number;
            }
            cout << "Please enter the number of guesses allowed (less than 10):";
            cin >> num_guesses;
            while (num_guesses > 10) {                      //ensure guess number is in spec
                cout << "Please enter the number of guesses allowed (less than 10):";
                cin >> num_guesses;
            }
            int actual_number = rand() % ((max_number - min_number) + 1) + min_number;  //determine random number
            cout << "Now, I have a number between " << min_number << " and " << max_number << ". Can you guess my number? Please type your first guess." << endl;
            counter = num_guesses;
            while (counter != 0) { //while under guess limit
                cout << "? ";
                cin >> guess;
                if (guess < actual_number) {
                    cout << "Too low! Try again." << endl;
                }
                if (guess > actual_number) {
                    cout << "Too high! Try again." << endl;
                }
                if (guess == actual_number) {
                    cout << "Excellent! you guessed the number!" << endl;
                    cout << "would you like to play again (y or n)? "; //prompt on repeat or not
                    cin >> repeat;
                    if (repeat == 'n' || repeat == 'N') {
                        return 0;                                   //end if no repeat
                    }
                    counter = 1;
                }
                i++;
                counter--;
            }
            cout << "Sorry, you can't guess anymore. The number is: " << actual_number << "." << endl; //guess ran out without correct answer
            cout << "would you like to play again (y or n)? "; //prompt for repeat again
            cin >> repeat;
        }
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
Date:02/10/2020
Name:Jacob Blumsack
*/