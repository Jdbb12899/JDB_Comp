/***********************************************
Author: <Jacob Blumsack>
Date: <02/10/2020>
Purpose: <Practicing use of classes, structures and the language that goes with them>
Sources of Help: <Lecture Notes, PPT, and sample code from class>
Time Spent: <2.5 hrs>
***********************************************/
#include <iostream>
#include <string>
#include <cmath>
#include <sstream>

using namespace std;

class ZipCode {
public:
    //Constructors
    ZipCode(int zipcode);                           //constructor accepts int
    ZipCode(string barcode);                        //constructor accepts string

    //Mutators
    void setZipCode(int);                           //set zip
    void setBarCode(string barcode);                //set bar

    //Accessors
    int getZipCode();                               //get zip
    string getBarCode();                            //get bar

private:
    int zip_code;                                   //only store zip code, input of barcode will be converted
    int converttoZipCode(string barcode) const;
    string converttoBarCode(int zipcode) const;
};

int main(int argc, char* argv[]) {
    ZipCode zip(99504), zip2("100101010011100001100110001"), zip3(12345), zip4(67890);
    cout << zip.getZipCode() << "'s bar code is '" << zip.getBarCode() << "'" << endl;
    cout << zip2.getZipCode() << "'s bar code is '" << zip2.getBarCode() << "'" << endl;
    cout << zip3.getZipCode() << "'s bar code is '" << zip3.getBarCode() << "'" << endl;
    cout << zip4.getZipCode() << "'s bar code is '" << zip4.getBarCode() << "'" << endl;
    cout << endl;

    // Test a range of values by first constructing a zip code
    // with an integer, then retrieving the bar code and using
    // that to construct another ZipCode.
    int zip_int = 0;
    for (int i = 0; i < 25; i++) {

        // Make an aribrary 5-digit zip code integer, and use it
        // to construct a ZipCode
        int five_digit_zip = (zip_int * zip_int) % 100000;
        ZipCode z1(five_digit_zip);

        // Construct a second ZipCode from the first's bar code

        string z1_barcode = z1.getBarCode();

        ZipCode z2(z1_barcode);
 

        cout.width(3);
        cout << (i + 1) << ": ";
        cout.width(5);
        cout << z2.getZipCode() << " has code '" << z1_barcode << "'";

        if ((z1_barcode == z2.getBarCode()) && (z1.getZipCode() == z2.getZipCode()) && (z2.getZipCode() == five_digit_zip)) {
            cout << " [OK]" << endl;
        }
        else {
            cout << " [ERR]" << endl;
        }

        // Increment the test value arbitrarily
        zip_int += (233 + zip_int % 7);
    }
    cout << endl;

    // Test some error conditions. This test assumes that
    // ZipCode will simply set its value to a flag that indicates
    // an error, and will not exit the program.
    int BAD_ZIP_COUNT = 2;
    string bad_zips[][2] = {
        { "100101010011100001100110000", "bad start/end character" },
        { "100101010011100001100110021", "bad digit" },
    };
    for (int i = 0; i < BAD_ZIP_COUNT; i++) {
        cout << "Testing: " << bad_zips[i][1] << " " << bad_zips[i][0] << endl;
        ZipCode test(bad_zips[i][0]);
        cout << endl;
    }

    cout << "Enter a character to quit." << endl;
    char c;
    cin >> c;
    return 0;
}
ZipCode::ZipCode(int zipcode) {
    setZipCode(zipcode);
}
ZipCode::ZipCode(string barcode) {
    setBarCode(barcode);
}
void ZipCode::setZipCode(int zipcode) {
    zip_code = zipcode;
}
void ZipCode::setBarCode(string barcode) {
    int zipcode = converttoZipCode(barcode);            //only zipcode stored, barcode is converted
    zip_code = zipcode;
}
int ZipCode::getZipCode() {
    return zip_code;
}
string ZipCode::getBarCode() {
    string barcode = converttoBarCode(zip_code);        //zipcode stored, so conversion needed to retrieve barcode
    return barcode;
}
int ZipCode::converttoZipCode(string barcode) const{
    char arr[5];
    int check = 0;
    int zipcode;
    int zip = 0;	
    int mult = 1;		
    int current = 1;	
    int tmp = 1;			
    int i = 0;

    arr[0] = barcode.at(0);
    arr[4] = barcode.at(26);
    if (arr[0] != 49 || arr[4] != 49) {                 //check barcode has 1 at beginning and end
        cout << "Wrong start/end character in the barcode!\n";
        return 0;
    }
    do {
        for (i = 0; i < 5; i++) {
            arr[i] = barcode.at(current);
            if (arr[i] != 49 && arr[i] != 48) {         //check barcode only contains 0s and 1s
                cout << "Wrong barcode! A barcode can only contain '0' and '1'.\n";
                return 0;
            }
            ++current;
        }
        for (i = 0; i < 5; i++) {
            if (arr[i] == '1') {            //go through array and convert to zipcode
                switch (i) {
                case 0:
                    check = check + 7;      //if bit is 1, add 7
                    break;
                case 1:
                    check = check + 4;      //if bit is 1, add 4
                    break;
                case 2:
                    check = check + 2;      //if bit is 1, add 2
                    break;
                case 3:
                    check = check + 1;      //if bit is 1, add 1
                    break;
                case 4:
                    check = check + 0;      //if bit is 1, add 0
                    break;
                }
            }
        }
        if (check != 11) {                      //otherwise 11 is 0
            zip = zip + (check * mult);         //conversion
        }
        mult = mult * 10;
        tmp = tmp + 1;
        check = 0;
    } 
    while (tmp < 6);
    zipcode = zip;
    return zip;
}
string ZipCode::converttoBarCode(int zipcode) const{
    string barcode;
    string zip;
    int arr[5];
    int i;

    for (int x = 0; x < 5; ++x) {                   //get each individual digit from int zipcode
        int temp = zipcode % 10; 
        zipcode /= 10;
        zip.push_back(temp + 48);                   //convert ascii to int
    }
    for (int x = 0; x < 5; x++) {
        arr[x] = (static_cast<int>(zip.at(x)) - 48);//place nums in array
    }
    for (i = 0; i != 5; i++) {                      //convert each num to corresponding sequence on bits
        switch (arr[i]) {
        case 0: barcode.insert(barcode.length(), "11000");
            break;
        case 1: barcode.insert(barcode.length(), "00010");
            break;
        case 2: barcode.insert(barcode.length(), "00100");
            break;
        case 3: barcode.insert(barcode.length(), "00110");
            break;
        case 4: barcode.insert(barcode.length(), "01000");
            break;
        case 5: barcode.insert(barcode.length(), "01010");
            break;
        case 6: barcode.insert(barcode.length(), "01100");
            break;
        case 7: barcode.insert(barcode.length(), "10000");
            break;
        case 8: barcode.insert(barcode.length(), "10010");
            break;
        case 9: barcode.insert(barcode.length(), "10100");
            break;
        }
    }
    barcode.insert(0, "1");                                 //insert 1 at beginning
    barcode.insert(barcode.length(), "1");                  //insert 1 at end
    return barcode;
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