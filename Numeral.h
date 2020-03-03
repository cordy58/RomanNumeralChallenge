#ifndef Numeral_h
#define Numeral_h

#include <string>
#include <sstream>
#include <vector>
#include <cmath>

using namespace std;

class Numeral {
    
private:
    const string valid = "IVXLCDM";
    const int I = 1;
    const int V = 5;
    const int X = 10;
    const int L = 50;
    const int C = 100;
    const int D = 500;
    const int M = 1000;
    vector<int> numeral;
    int modernNum = 0;
    
public:
    Numeral() {};
    ~Numeral() {};
    
    //valid_char checks to make sure all the characters in the string are appropriate.
    void valid_char(string number) {
        for (int i = 0; i < number.size(); i++) {
            if (valid.find(number.at(i)) == string::npos) {
                //If a char can't be found in valid, throw an error.
                throw (string(" Invalid Numeral."));
            }
        }
    }
    
    //set_numeral goes ahead and fills the vector because I found it easier to check other conditions after it was in vector form
    void set_numeral(string number) {
        //check in here to make sure it's valid chars
        valid_char(number);
        for (int i = 0; i < number.size(); i++) {
            if (number.at(i) == 'I') {
                numeral.push_back(I);
            }
            else if (number.at(i) == 'V') {
                numeral.push_back(V);
            }
            else if (number.at(i) == 'X') {
                numeral.push_back(X);
            }
            else if (number.at(i) == 'L') {
                numeral.push_back(L);
            }
            else if (number.at(i) == 'C') {
                numeral.push_back(C);
            }
            else if (number.at(i) == 'D') {
                numeral.push_back(D);
            }
            else if (number.at(i) == 'M') {
                numeral.push_back(M);
            }
        }
    };
    
     /*I in the middle of figuring out how I wanted to change this function from the other one in RomanNumeral.h when I hit 4 hours*/
    //valid_order makes sure any # preceding another one isn't too small.
    void valid_order() {
        int one;
        int two;
        if (numeral.size() > 1) {
           for (one = numeral.size() - 1; one >= 1; one--) {
               two = one - 1;
               //Between X and M b/c im using sqrt. X will throw an error because I < sqrtX, likewise w/M
               if (numeral.at(one) > X && numeral.at(one) < M) {
                   if (numeral.at(two) < sqrt(numeral.at(one))) {
                       throw (string(" Invalid Order"));
                   }
               }
               //Whatever is in front of X never matters. So no else for it. It's easiest to just set M manually.
               else if (numeral.at(one) == M) {
                   if (numeral.at(two) != D && numeral.at(two) != C) throw (string(" Invalid Order"));
               }
           }
        }
    }
    
    //invalid_repeat makes sure that there aren't more than 4 of any given # in a row by comparing the back 4 #s of the vector and iterating down until the end. also checks that there aren't more than 3 decreasing from right to left, i.e. IVX
    void invalid_repeat( ) {
        if (numeral.size() > 2) {
            for (int i = 3; i < numeral.size(); i++) {
                if (numeral.at(i) == numeral.at(i - 1) && numeral.at(i) == numeral.at(i - 2) && numeral.at(i) == numeral.at(i - 3)) {
                    throw (string(" Invalid. Too many numerals in a row."));
                }
            }
            int first, second, third;
            for (third = numeral.size() - 3; third >= 0; third--) {
                second = third + 1;
                first = third + 2;
                if (numeral.at(second) < numeral.at(first)) {
                    if (numeral.at(third) <= numeral.at(second)) {
                        throw (string(" Invalid. Set of 3 numerals are decreasing from right to left."));
                    }
                }
            }
        }
    }
    
    //roman_to_modern converts from roman to modern, and the subtractive notation is handled inside without a separate function, since at this point only valid sets of numerals should have made it through.
    int roman_to_modern() {
        valid_order();
        invalid_repeat();
        int temp = 0;
        while (!numeral.empty()) {
            temp = 0;
            temp = numeral.back();
            numeral.pop_back();
            if (!numeral.empty() && temp > numeral.back()) {
                temp -= numeral.back();
                numeral.pop_back();
                modernNum += temp;
            }
            else {
                modernNum += temp;
            }
        }
            return modernNum;
    }
    
    //overloads the << operator. Since all I wanted was to print off the moder translation, I just put in .roman_to_modern and that gets the only thing we want
    friend ostream& operator<< (ostream& os, Numeral& num) {
        os << " " << num.roman_to_modern();
        return os;
    }
    
};

#endif /* Numeral_h */
