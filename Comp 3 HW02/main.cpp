/***********************************************
Author: <Jacob Blumsack>
Date: <02/05/2020>
Purpose: <practice opening, closing and using strings in CPP>
Sources of Help: <classroom ppt.>
Time Spent: <1 hr>
***********************************************/

#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char* argv[]) {
	string word;						//for analyzing each word
	ifstream inStream;					//input stream declared
	inStream.open("input.txt");			//open file
	if (!inStream.is_open()) {
		cout << "File did not open correctly" << endl;
	}
	while (inStream >> word) {			
		if (word == "dislike") {		//only for words "dislike"
			word = "love";				//replace with "love"
		}
		cout << word << " ";
	}
	cout << endl;
	inStream.close();					//close file
	return 0;
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
Date: 02/05/2020
Name: Jacob Blumsack
*/