/***********************************************
Author: <Jacob Blumsack>
Date: <02/25/2020>
Purpose: <Practice overloading functions and operators>
Sources of Help: <Lecture captures, class ppts, notes>
Time Spent: <2hrs>
***********************************************/

#include <iostream>
#include <cstdlib>

using namespace std;

class Rational
{
public:
    //Constructors
    Rational();
    Rational(int wholeNumber);
    Rational(int x, int y);

    friend ostream& operator<<(ostream& outstream, const Rational& r);
    friend istream& operator>>(istream& instream, Rational& r);
    friend bool operator==(const Rational& r1, const Rational& r2);
    friend bool operator<(const Rational& r1, const Rational& r2);
    friend bool operator<=(const Rational& r1, const Rational& r2);
    friend bool operator>(const Rational& r1, const Rational& r2);
    friend bool operator>=(const Rational& r1, const Rational& r2);
    friend const Rational operator+(const Rational& r1, const Rational& r2);
    friend const Rational operator-(const Rational& r1, const Rational& r2);
    friend const Rational operator*(const Rational& r1, const Rational& r2);
    friend const Rational operator/(const Rational& r1, const Rational& r2);
    //friend void simplify(Rational& r1);

private:
    int numerator;
    int denominator;
};

int main(int argc, char* argv[]) {
    Rational A;
    cout << "Default constructor A is:" << A << endl;
    Rational B(2);
    cout << "Whole number constructor B is:" << B << endl;
    Rational C(1, 2);
    cout << "Rational constructor C is:" << C << endl;
    Rational D(2, 4);
    cout << "Rational constructor D is (Simplification of 2/4 built into constructor):" << D << endl;
    cout << "Enter a fractional value (to reset value of B) in the format of x/y:";
    cin >> B;
    cout << "The new value for B is:" << B << endl;
    Rational E(1, 3);
    Rational F(1, 5);
    cout << E << " + " << F << " is " << (E + F) << endl;
    cout << E << " - " << F << " is " << (E - F) << endl;
    cout << E << " * " << F << " is " << (E * F) << endl;
    cout << E << " / " << F << " is " << (E / F) << endl;
    
    cout << "(1/5 < 1/3)" << endl;
    if ((F < E) == true) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }

    cout << "(1/2 <= 2/4)" << endl;
    if ((C <= D) == true) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }

    cout << "(1/3 > 1/5)" << endl;
    if ((E > F) == true) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }

    cout << "(2/4 >= 1/2)" << endl;
    if ((D <= C) == true) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }

    cout << "(1/2 == 2/4)" << endl;
    if ((C == D) == true) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
}

/*                                                  //simplify function placed directly into constructor
void simplify(Rational& r1) {
    int i;
    for (i = (r1.numerator * r1.denominator); i > 1; --i) {
        if ((r1.denominator % i == 0) && (r1.numerator % i == 0)) {
            r1.denominator = r1.denominator / i;
            r1.numerator = r1.numerator / i;
        }
    }
}
*/

Rational::Rational() {                                                      //default constructor for Rational
    numerator = 0;      
    denominator = 1;
}
Rational::Rational(int wholeNumber) {                                           //set whole number amounts for Rational
    numerator = wholeNumber;
    denominator = 1;
}
Rational::Rational(int x, int y) {                                              //set any rational
    int i;
    numerator = x;
    if (y == 0) {
        cout << "denominator cannot equal 0!" << endl;                          //denominator cannot be 0 for fractions
        exit(0);
    }
    else {
        denominator = y;
    }
    for (i = (numerator * denominator); i > 1; --i) {
        if ((denominator % i == 0) && (numerator % i == 0)) {
            denominator = denominator / i;
            numerator = numerator / i;
        }
    }
}

ostream& operator<<(ostream& outstream, const Rational& r) {
    outstream << r.numerator;                                       //output numerator
    if (r.denominator != 1) {                                       //if denominator is 1, it is a wholenumber
        outstream << "/" << r.denominator;                          //else it is a fraction
    }
    return outstream;
}

istream& operator>>(istream& instream, Rational& r) {
    char tmp;
    instream >> r.numerator >> tmp >> r.denominator;                //only accept input character in x/y fraction format
    return instream;
}

bool operator==(const Rational& r1, const Rational& r2) {
    return ((r1.numerator == r2.numerator) && (r1.denominator == r2.denominator));   //return true if numerators are equal and denominators are equal
}

bool operator<(const Rational& r1, const Rational& r2) {
    int R1 = (r1.numerator * r2.denominator);                   //cross multiply to determine less than
    int R2 = (r1.denominator * r2.numerator);
    return (R1 < R2);
}

bool operator<=(const Rational& r1, const Rational& r2) {
    int R1 = (r1.numerator * r2.denominator);                   //cross multiply to determine less than or equal to
    int R2 = (r1.denominator * r2.numerator);
    return ((R1 < R2) || (R1 == R2));
}

bool operator>(const Rational& r1, const Rational& r2) {
    int R1 = (r1.numerator * r2.denominator);                   //cross multiply to determine greater than
    int R2 = (r1.denominator * r2.numerator);
    return (R1 > R2);
}

bool operator>=(const Rational& r1, const Rational& r2) {
    int R1 = (r1.numerator * r2.denominator);                   //cross multiply to determine greater than or equal to
    int R2 = (r1.denominator * r2.numerator);
    return ((R1 > R2) || (R1 == R2));
}

const Rational operator+(const Rational& r1, const Rational& r2) {
    Rational sum;
    sum.numerator = (r1.numerator * r2.denominator) + (r2.numerator * r1.denominator);          //sets sum numerator to addition of two fractions given gcd
    sum.denominator = r1.denominator * r2.denominator;                                          //sets denominator to gcd
    return sum;                                                                                 //sum of two fractions returned
}

const Rational operator-(const Rational& r1, const Rational& r2) {
    Rational difference;
    difference.numerator = (r1.numerator * r2.denominator) - (r2.numerator * r1.denominator);   //sets numerator two subtraction of two rationals given gcd
    difference.denominator = r1.denominator * r2.denominator;                                   //sets denominator to gcd
    return difference;                                                                          //difference of two fractions returned
}

const Rational operator*(const Rational& r1, const Rational& r2) {      
    Rational product;
    product.numerator = r1.numerator * r2.numerator;                                            //numerator is product of two numerators
    product.denominator = r1.denominator * r2.denominator;                                      //sets denominator to gcd
    return product;                                                                             //product of two fractions returned
}

const Rational operator/(const Rational& r1, const Rational& r2) {
    Rational quotient;
    quotient.numerator = r1.numerator * r2.denominator;                                         //quotient calculated via product of the inverse
    quotient.denominator = r1.denominator * r2.numerator;
    return quotient;                                                                            //quotient of two fractions returned
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
Date:02/25/2020
Name:Jacob Blumsack
*/