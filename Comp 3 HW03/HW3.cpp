/***********************************************
Author: <Jacob Blumsack>
Date: <02/09/2020>
Purpose: <Practicing use of classes and their members>
Sources of Help: <Lecture Notes, PPT, and sample code from class>
Time Spent: <1.5 hrs>
***********************************************/
#include <iostream>

using namespace std;

class Point {
public:
    void Move_Point(int& moveX, int& moveY);  //Function will move the point horizontally and vertically
    void Rotate_Point(int &x, int &y);        //Function will rotate the point 90 degrees

    //mutators
    void Set_X(int x1);                     //set the private variable x
    void Set_Y(int y1);                     //set the private variable y

    //accessors
    int RetrieveX(void);                    //retrieve private variable x
    int RetrieveY(void);                    //retrieve private variable y
private:
    int x;                                  //private variable x
    int y;                                  //private variable y
};

int main(int argc, char* argv[])
{
    Point New_Point;
    int x;
    int y;
    int moveX = 0;
    int moveY = 0;
    int choice;
    cout << "Enter an x coordinate" << endl;
    cin >> x;
    New_Point.Set_X(x);
    cout << "Enter a y coordinate" << endl;
    cin >> y;
    New_Point.Set_Y(y);
    cout << "The point you entered is (" << x << "," << y << ")" << endl;
    cout << "Enter 1 if you would like to rotate the point 90 degrees clockwise about the origin or enter 2 if you would like to move the point by a set distance. Enter 3 if you would like to exit;" << endl;
    cin >> choice;
    if (choice == 3) {
        return 0;
    }
    while (choice != 3) {
        
        if (choice == 1) {
            New_Point.Rotate_Point(x,y);
            cout << "Your new point is (" << x << "," << y << ")" << endl;
        }
        else {
            cout << "How far would you like to move the point horizontally(x)?" << endl;
            cin >> moveX;
            cout << "How far would you like to move the point vertically(y)?" << endl;
            cin >> moveY;
            New_Point.Move_Point(moveX, moveY);
            cout << "Your new point is (" << moveX << "," << moveY << ")" << endl;
        }
    cout << "Enter 1 if you would like to rotate the point 90 degrees clockwise about the origin or enter 2 if you would like to move the point by a set distance. Enter 3 if you would like to exit;" << endl;
    cin >> choice;
    }
    return 0;
}

void Point::Set_X(int x1) {                     //set the private variable x
    x = x1;
}
void Point::Set_Y(int y1) {                     //set the private variable y
    y = y1;
}
void Point::Rotate_Point(int &x, int &y) {
    if ((x >= 0) && (y >= 0)) {                 //if pos,pos make pos,neg
        y = y * -1;
        return;
    }
    cout << "Hi";
    if ((x >= 0) && (y <= 0)) {                 //if pos,neg make neg, neg
        x = x * -1;
        return;
    }
    if ((x <= 0) && (y <= 0)) {                 //if neg, neg make neg, pos
        y = y * -1;
        return;
    }
    if ((x <= 0) && (y >= 0)) {                 //if neg, pos make pos, pos
        x = x * -1;
        return;
    }
    Set_X(x);
    Set_Y(y);
}
void Point::Move_Point(int& moveX, int& moveY) {
    moveX = moveX + Point::x;
    moveY = moveY + Point::y;
    Set_X(moveX);
    Set_Y(moveY);
    return;
}
int Point::RetrieveX(void) {
    return x;
}
int Point::RetrieveY(void) {
    return y;
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
Date:02/09/2020
Name:Jacob Blumsack
*/