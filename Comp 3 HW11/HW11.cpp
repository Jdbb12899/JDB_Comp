/***********************************************
Author: <Jacob Blumsack>
Date: <04/29/2020>
Purpose: <Practice working withg STL and Algorithms>
Sources of Help: <class lecture videos and ppts.>
***********************************************/
#include <cstdlib>
#include <iostream>
#include <string>
#include <list>
#include <sstream>
#include <algorithm>

using namespace std;

list<string> generate_permutations(list<string> inList);
void print_permutations(list<string> aList);

int main(int argc, char* argv[])
{
    list<string> inputList;
    string aLine, aString;
    // read in strings from stdin
    cout << "Enter strings, separated by a space:";
    getline(cin, aLine); //read a line from keyboard
    istringstream iss(aLine); //convert aLine to an istringstream obj

        //parse each string
        while (iss >> aString)
        {
            inputList.push_back(aString);
        }

    auto permutations = generate_permutations(inputList);

    // print permutations to stdout
    print_permutations(permutations);

    return 0;
}

list<string> generate_permutations(list<string> inList) {           //take user given list, return sorted list with no duplicates
    list<string>::iterator it1;                                     //declare list iterator 
    inList.sort();                                                  //sort list so duplicates are next to each other
    inList.unique();                                                //remove duplicates                      
    cout << "All Permutations are: " << endl;                       
    for (it1 = inList.begin(); it1 != inList.end(); ++it1) {        //using iterator
        cout << *it1 << " ";                                        //list starting permutation
    }
    cout << endl;   
    return inList;                                                  //return list for print funct
}

void print_permutations(list<string> aList) {                       
    list<string>::iterator it2;                                     //declare iterator for permutation formation
    while (next_permutation(aList.begin(), aList.end())) {          //using next_permutation function to form each permutation for list
        for (it2 = aList.begin(); it2 != aList.end(); ++it2) {      //using iterator
            cout << *it2 << " ";                                    //print each element per permutation line
        }
        cout << endl;
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
Date:04/29/2020
Name:Jacob Blumsack
*/