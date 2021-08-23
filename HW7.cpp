/***********************************************
Author: <Jacob Blumsack>
Date: <03/30/2020>
Purpose: <Using STL library and maps>
Sources of Help: <Lecture captures, class ppts, notes>
Time Spent: <2hrs>
***********************************************/

#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <iterator>

using namespace std;

int main(int argc, char* argv[]) {
    string name;
    string name2;
    int rating = 0;
    int num_of_reviews;
    int numRatings = 0;
    int sums;

    ifstream input;                                                     //set in path
    input.open("HW7.txt");                                              //open file HW7.txt
    if (!input) {
        cout << "File could not be opened!" << endl;                    //check if open
        exit(1);                                                        //if not, exit
    }
    input >> num_of_reviews;                                            //take first number of file as number of reviews
    input.ignore();

    multimap<string, int> movie;                                        //(movie name, rating)
    map<string, int> ratings;                                           //(movieName, num rating)
    map<string, int> sum;                                               //(movieName, sum ratings)

    while (getline(input, name)) {
        input >> rating;
        movie.emplace(name, rating);                                    //for movie map, place each review with corresponding name
        input.ignore();
    }

    map<string, int>::iterator it3;                                     //iterator for ratings
    for (it3 = movie.begin(); it3 != movie.end(); ++it3) {
        string name1 = (*it3).first;
        numRatings = movie.count(name1);
        ratings.emplace(name1, numRatings);                             //Set the number of ratings per movie title
    }

    map<string, int>::iterator it1;                                     //iterator for ratings
    for (it1 = ratings.begin(); it1 != ratings.end(); ++it1) {
        map<string, int>::iterator it4;                                 //iterator for sums
        sums = 0;                                                       //reset sum for each movie title
        for (it4 = movie.begin(); it4 != movie.end(); ++it4) {
            if ((*it1).first == (*it4).first) {
                sums = sums + it4->second;                              //when titles match, add the ratings to get the total per title
            };
        }
        string name1 = (*it1).first;
        sum.emplace(name1, sums);                                       //set sum of ratings per title
    }

    map<string, int>::iterator it6;
    map<string, int>::iterator it2;
    for (it2 = ratings.begin(), it6 = sum.begin(); it2 != ratings.end(); ++it2, ++it6) {
        double x = (*it6).second;                                       //double val for sum of ratings
        double y = (*it2).second;                                       //double val for total ratings
        cout << (*it2).first << ": " << (*it2).second << " review(s), average of " << floor((x / y) * 10) / 10 << "/5" << endl; //calc avg with floor at 1 decimal
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
Date:03/30/2020
Name:Jacob Blumsack
*/