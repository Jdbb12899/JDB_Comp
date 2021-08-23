/***********************************************
Author: <Jacob Blumsack>
Date: <04/06/2020>
Purpose: <practice with classes and inheritance>
Sources of Help: <class lecture videos and ppts.>
***********************************************/

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

class Person
{
public:
    Person() : name("none") {};                                                     //default constructor
    Person(string theName) : name(theName) {};                                      //constuctor
    Person(const Person& theObject);                                                //copy constuctor
    string getName() const;
    Person& operator=(const Person& rtSide);                                        //overload assignment operator
    friend istream& operator >>(istream& inStream, Person& personObject);
    friend ostream& operator <<(ostream& outStream, const Person& pObject);
private:
    string name;
};

class Vehicle
{
public:
    Vehicle() :manufacturer("Unknown Manufactory"), cylinders(0), owner("Unknown Owner") {};          //default constructor
    Vehicle(string aManufacturer, int numCylinders, const Person& anOwner) : manufacturer(aManufacturer), cylinders(numCylinders), owner(anOwner) {};//constuctor
    Vehicle(const Vehicle& type);                                                   //copy constuctor
    Vehicle& operator =(const Vehicle& vehicle);                                    //overload assignment operator
    string getManufacturer();
    int getCylinders();
    Person getOwner();
    friend ostream& operator <<(ostream& outStream, const Vehicle& vObject);
private:
    string manufacturer;
    int cylinders;
    Person owner;
};


class Truck : public Vehicle {
public:
    Truck();                                                                        //default constructor
    Truck(double aLoadCapacity, int aTowingCapacity, string aManufacturer, int numCylinders, const Person& anOwner);//constuctor
    Truck(const Truck& truck);                                                      //copy constuctor
    Truck& operator =(const Truck& truck);                                          //overload assignment operator
    double getLoadCapacity();
    int getTowingCapacity();                                                        //no setters as these variables cannot be modified
    friend ostream& operator <<(ostream& outStream, const Truck& tObject);
private:
    double loadCapacity;
    int towingCapacity;
    Vehicle vehicle;
};

int main(int argc, char* argv[]) {
    //Testing Person Class
    Person own1;
    Person own2("Jacob");
    Person own3(own2);
    Person own4;
    Person own5;
    cout << "Testing default constructor: the person is: " << own1 << endl;
    cout << "Testing constructor(string): I am: " << own2 << endl;
    cout << "Testing copy constructor: another me is: " << own3 << endl;
    cout << "Testing >> overloading: Enter your name: ";
    cin >> own4;
    cout << "You're: " << own4 << endl;
    own5 = own4;
    cout << "Testing = overloading: Another you is: " << own5 << endl << endl;

    //Testing Vehicle Class
    Vehicle v1;
    Vehicle v2("Ford Van", 8, own2);
    Vehicle v3(v2);
    Vehicle v4;
    cout << "Testing default constructor: the Vehicle is: " << v1 << endl;
    cout << "Testing constructor(args): for my car: " << v2 << endl;
    cout << "Testing copy constructor: my second same car: " << v3 << endl;
    v4 = v3;
    cout << "Testing = overloading: " << v4 << endl << endl;

    //Testing Truck Class
    Truck t1;
    Truck t2(250, 2000, "Mac", 8, own2);
    Truck t3(t2);
    Truck t4;
    cout << "Testing default constructor: the Truck is: " << t1 << endl;
    cout << "Testing constructor(args): for a truck: " << t2 << endl;
    cout << "Testing copy constructor: copied truck: " << t3 << endl;
    t4 = t2;
    cout << "Testing = overloading: " << t4 << endl;
    return 0;
}

//Vehicle class functions
Vehicle::Vehicle(const Vehicle& type) {
    manufacturer = type.manufacturer;                                               //set manufacturer to copy
    cylinders = type.cylinders;                                                     //copy over cylinders
    owner = type.owner;                                                             //copy over owner
}
Vehicle& Vehicle::operator =(const Vehicle& vehicle) {
    this->manufacturer = vehicle.manufacturer;                                      //set manufacturer equal
    this->cylinders = vehicle.cylinders;                                            //set cylinders equal
    this->owner = vehicle.owner;                                                    //set owners equal
    return *this;
}
string Vehicle::getManufacturer() {
    return manufacturer;                                                            //return manufacturer
}
int Vehicle::getCylinders() {
    return cylinders;                                                               //return cylinders
}
Person Vehicle::getOwner() {
    return owner;                                                                   //return owner
}
ostream& operator <<(ostream& outStream, const Vehicle& vObject) {
    outStream << vObject.manufacturer;                                              //output manu.
    cout << ", ";                                   
    outStream << vObject.cylinders;                                                 //output numcylinders
    cout << " cylinders, belongs to: ";
    outStream << vObject.owner;                                                     //ouput owner
    return outStream;
}

//Person class functions
Person::Person(const Person& theObject) {
    name = theObject.name;                                                          //set name equal to copy
}
string Person::getName() const {
    return name;                                                                    //return name
}
Person& Person::operator=(const Person& rtSide) {
    this->name = rtSide.name;                                                       //set names equal
    return *this;
}
istream& operator >>(istream& inStream, Person& personObject) {
    getline(inStream, personObject.name);                                           //input object name
    return inStream;
}
ostream& operator <<(ostream& outStream, const Person& pObject) {   
    outStream << pObject.name;                                                      //output object name
    return outStream;
}

//Truck class functions
Truck::Truck() {
    loadCapacity = 0.0;                                                             //set loadcap to 0
    towingCapacity = 0;                                                             //set towcap to 0
    Vehicle vehicle;                                                                //default constructor for Vehicle class
}
Truck::Truck(double aLoadCapacity, int aTowingCapacity, string aManufacturer, int numCylinders, const Person& anOwner) {
    loadCapacity = aLoadCapacity;                                                   //set to input load capacity
    towingCapacity = aTowingCapacity;                                               //set to input towing capacity
    Vehicle vehicle(aManufacturer, numCylinders, anOwner);                          //set input for Vehicle object variables
}
Truck::Truck(const Truck& aTruck) {
    loadCapacity = aTruck.loadCapacity;                                              //copy load capacity
    towingCapacity = aTruck.towingCapacity;                                          //copy towing capacity
    vehicle = aTruck.vehicle;
}
Truck& Truck::operator =(const Truck& truck) {
    loadCapacity = truck.loadCapacity;                                              //set load capacity equal
    towingCapacity = truck.towingCapacity;                                          //set towing capacity equal
    Vehicle::operator=(truck);                                                      //set Vehicle objects equal
    return *this;
}
double Truck::getLoadCapacity() {
    return loadCapacity;                                                            //return laod capacity
}
int Truck::getTowingCapacity() {
    return towingCapacity;                                                          //return towing capacity
}
ostream& operator <<(ostream& outStream, const Truck& tObject) {
    outStream << tObject.vehicle;                                                   //output vehicle class
    cout << ", load capacity(tons): ";
    outStream << tObject.loadCapacity;                                              //output loadcap
    cout << ", towing capacity(pounds): ";
    outStream << tObject.towingCapacity;                                            //output towcap
    return outStream;
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
Date:04/06/2020
Name:Jacob Blumsack
*/