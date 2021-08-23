/***********************************************
Author: <Jacob Blumsack>
Date: <04/22/2020>
Purpose: <Help reinforce the rules of the big three>
Sources of Help: <class lecture videos and ppts.>
***********************************************/

#include <iostream>
#include <string>
#include <exception>

using namespace std;

void testPFArrayD(void);
void testException(void);

//Objects of this class are partially filled arrays of doubles.
class PFArrayD {
public:
    PFArrayD() : capacity(50), used(0), a(0) {                      //Initializes with a capacity of 50.
        a = new double[capacity];
    };
    PFArrayD(int capacityValue) : capacity(capacityValue), used(0), a(0) {
        a = new double[capacity];
    };
    PFArrayD(const PFArrayD& pfaObject);                            //copy constructor
    void addElement(double element);                                //Precondition: The array is not full.Postcondition: The element has been added.
    bool full() const { return (capacity == used); }                //Returns true if the array is full, false otherwise.
    int getCapacity() const { return capacity; }                    //return capacity
    int getNumberUsed() const { return used; }                      //return used
    void emptyArray() { used = 0; }                                 //Empties the array.
    double& operator[](int index);                                  //Read and change access to elements 0 through numberUsed - 1.
    PFArrayD& operator =(const PFArrayD& rightSide);                //assignment operator
    ~PFArrayD();                                                    ///destructor
private:
    double* a;                                                      //for an array of doubles.
    int capacity;                                                   //for the size of the array.
    int used;                                                       //for the number of array positions currently in use.

};

class OutOfRange {
public:
    OutOfRange(string errorMessage, int indexVal) : message(errorMessage), indexValue(indexVal) {};//constructor for outofrange
    virtual const char* what() const throw() { return message.c_str(); }
    int index() { return indexValue; }                              //returns indexvalue
    string err() { return message; }                                //returns message
private:
    int indexValue;                                                 //stores index of error message
    string message;                                                 //stores error message
};

int main(int argc, char* argv[])
{
    cout << "This program tests the class PFArrayD.\n";

    char ans;
    do
    {
        testPFArrayD();
        cout << "Test again? (y/n) ";
        cin >> ans;
    } while ((ans == 'y') || (ans == 'Y'));
    testException();
    return 0;
}

void testPFArrayD()
{
    int cap;
    cout << "Enter capacity of this super array: ";
    cin >> cap;
    PFArrayD temp(cap);

    cout << "Enter up to " << cap << " nonnegative numbers.\n";
    cout << "Place a negative number at the end.\n";

    double next;
    cin >> next;
    while ((next >= 0) && (!temp.full()))
    {
        temp.addElement(next);
        cin >> next;
    }

    cout << "You entered the following "
        << temp.getNumberUsed() << " numbers:\n";
    int index;
    int count = temp.getNumberUsed();
    for (index = 0; index < count; index++)
        cout << temp[index] << " ";
    cout << endl;
    cout << "(plus a sentinel value.)\n";
}

PFArrayD::PFArrayD(const PFArrayD& pfaObject) {
    int i;
    capacity = pfaObject.getCapacity();                             //set capacities equal
    used = pfaObject.getNumberUsed();                               //set used equal
    a = new double[capacity];                                       //set the new double value
    for (i = 0; i < used; ++i) {
        a[i] = pfaObject.a[i];                                      //set each used array value
    }
}

void PFArrayD::addElement(double element) throw (OutOfRange){
    if (used >= capacity) {                                         //check array has enough capacity
        throw OutOfRange("ERROR: Not enough capacity to add element!", 0); //throw exception when out of range
    }
    else {
        a[used] = element;                                          //if there is enough capacity, add the element into the array
        ++used;                                                     //increment used to reflect new number of used
    }
}

double& PFArrayD::operator[](int index) throw (OutOfRange) {
    if (index >= used) {                                            //check to see if there is a used value for given index
        throw OutOfRange("ERROR: No value at given index!", index); //throw exception when out of range
    }
    else {
        return a[index];                                            //if index has used value, return value
    }
}

PFArrayD& PFArrayD::operator =(const PFArrayD& rightSide) {
    delete[] a;                                                     //delete a values
    a = new double[rightSide.capacity];
    capacity = rightSide.capacity;                                  //copy over capacity
    used = rightSide.used;                                          //copy over number used
    for (int i = 0; i < used; i++) {                                //copy over each a value
        a[i] = rightSide.a[i];                                      //set each index val equal
    }
    return *this;                                                   //return copy
}

PFArrayD::~PFArrayD() {
    delete[] a;                                                     //destructor for a
}

void testException() {
    cout << endl <<"Test Exception function" << endl;
    PFArrayD testArray(3);                                          //declare array
    cout << "Array filled to capacity and then attempt to add past capacity" << endl;
    testArray.addElement(1);
    testArray.addElement(2);
    testArray.addElement(-2);                                       //fill array to capacity

    try {
        testArray.addElement(3);                                    //add past capacity of array
    }
    catch (OutOfRange& i) {
        cout << i.what();                                           //return message
    }
    cout << "Referencing an invalid index now" << endl;
    try {
        cout << testArray[10];                                      //attempt to acces value less index
    }
    catch (OutOfRange& i) {
        cout << i.what();                                           //return message
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
Date:04/22/2020
Name:Jacob Blumsack
*/