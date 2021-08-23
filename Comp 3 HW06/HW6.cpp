/***********************************************
Author: <Jacob Blumsack>
Date: <03/18/2020>
Purpose: <Practice with dynamic arrays>
Sources of Help: <Lecture captures, class ppts, notes>
Time Spent: <2hrs>
***********************************************/

#include <iostream>
#include <cstdlib>

using namespace std;

class DynamicStringArray
{
public:
    //Constructors
    DynamicStringArray(void);
    DynamicStringArray(const DynamicStringArray& cpy);
    ~DynamicStringArray(void);
    int returnSize();
    void addEntry(string strng);
    bool deleteEntry(string strng);
    string getEntry(const int entry);
    DynamicStringArray& operator =(const DynamicStringArray& cpy);
private:
    string *dynamicArray;
    int size;
};

int main(int argc, char* argv[]) {
    DynamicStringArray strng1;
    DynamicStringArray strng2;
    strng2.addEntry("C");
    DynamicStringArray strng3(strng2);
    DynamicStringArray strng4;
    strng4.addEntry("D");
    //Test default constructor
    cout << "Default Constructor(size should equal 0): " << strng1.returnSize() << endl;
    //Test copy constructor
    cout << "Copy Conctructor(should equal strng1 (C): " << strng3.getEntry(0) << endl;
    //Test add entry
    strng1.addEntry("A");
    strng1.addEntry("B");
    //Test get entry
    cout << "Add Entry, Get Entry (A): " << strng1.getEntry(0) << endl;
    cout << "Add Entry, Get Entry (B): " << strng1.getEntry(1) << endl;
    //Test delete entry
    cout << "deleteEntry: " << strng1.deleteEntry("B") << endl;
    //Test return size
    cout << "returnSize: " << strng1.returnSize() << endl;
    cout << strng1.getEntry(1) << endl;
    //Test = operator overload
    strng4 = strng2;
    cout << "= operator (Should be C): " << strng4.getEntry(0) << endl;
    return 0;
}

DynamicStringArray::DynamicStringArray(void) {                              //default constructor sets nullptr and size to 0
    dynamicArray = nullptr;
    size = 0;
}

DynamicStringArray::DynamicStringArray(const DynamicStringArray& cpy) {     //copy constructor
    string* tmp;                                                            //tmp ptr
    tmp = nullptr;
    size = cpy.size;                                                        //copy size
    tmp = new string[size];
    tmp = cpy.dynamicArray;                                                 //copy original array
    dynamicArray = tmp;
}

DynamicStringArray::~DynamicStringArray(void) {
    delete[] dynamicArray;                                                  //destructor
}

int DynamicStringArray::returnSize() {
    return size;                                                            //return size
}

void DynamicStringArray::addEntry(string strng) {
    int i;
    string* ptr = dynamicArray;                                             //old array
    dynamicArray = new string[size + 1];                                    //make new array with space for new entry
    dynamicArray[size].assign(strng);
    for (i = 0; i < size; ++i) {                                            //copy all values from original
        dynamicArray[i] = ptr[i];
    }
    size++;
}

bool DynamicStringArray::deleteEntry(string strng) {
    int index;
    string* tmp;                                                            //tmp pointer
    tmp = nullptr;
    for (index = 0; index < size; ++index) {                                //check strng is in array
        if (strng == dynamicArray[index]) {
            break;
            return false;                                                   //if not, break and return bool false
        }
    }
    tmp = new string[size - 1];
    int j = 0;
    int k = 0;
    for (j = 0; j < size; ++j) {                                            //exclude entry to be deleted
        if (j != index) {
            tmp[k] = dynamicArray[j];
            ++k;
        }
    }
    delete[] dynamicArray;
    dynamicArray = tmp;
    --size;
    return true;
}

string DynamicStringArray::getEntry(const int entry) {
    if (entry >= size) {                                                    //check entry is in array
        cout << "Entry does not exist" << endl;                             //if not, it doesnt exist
        return 0;
    }
    else {
        return dynamicArray[entry];                                         //else return specified entry
    }
}

DynamicStringArray& DynamicStringArray::operator =(const DynamicStringArray& cpy) {
    int i;
    this->size = cpy.size;                                                  //copy size
    delete[] this->dynamicArray;
    dynamicArray = new string[cpy.size];
    for (i = 0; i < size; ++i)
        this->dynamicArray[i] = cpy.dynamicArray[i];                        //copy array
    return *this;
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
Date:03/18/2020
Name:Jacob Blumsack
*/