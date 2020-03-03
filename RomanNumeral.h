/*#ifndef RomanNumeral_h
#define RomanNumeral_h

#include <string>
#include <sstream>
#include <fstream>
#include <stack>
#include <cmath>

using namespace std;

class RomanNumeral {
    
private:
    const string valid = "IVXLCDM";
    const int I = 1;
    const int V = 5;
    const int X = 10;
    const int L = 50;
    const int C = 100;
    const int D = 500;
    const int M = 1000;
    stack<int> numeral; //convert to vector
    int modernNum = 0;
    
public:
    RomanNumeral() {};
    ~RomanNumeral() {};
    
    void valid_num(string number) {
        for (int i = 0; i < number.size(); i++) {
            if (valid.find(number.at(i)) == string::npos) {
                throw (string(" Invalid Numeral."));
            }
        }
    }
    
    void valid_order(string number) {
        bool valid = true;
        if (number.size() > 1) {
           for (int i = 1; i < number.size(); i++) {
                if (number.at(i) == 'L') {
                    if (number.at(i-1) == 'I') {
                        valid = false;
                        break;
                    }
                }
                else if (number.at(i) == 'C') {
                    if (number.at(i - 1) == 'I' || number.at(i - 1) == 'V') {
                        valid = false;
                        break;
                    }
                }
                else if (number.at(i) == 'D') {
                    if (number.at(i - 1) == 'I' || number.at(i - 1) == 'V' || number.at(i - 1) == 'X') {
                        valid = false;
                        break;
                    }
                }
                else if (number.at(i) == 'M') {
                    if (number.at(i - 1) == 'I' || number.at(i - 1) == 'V' || number.at(i - 1) == 'X' || number.at(i - 1) == 'L') {
                        valid = false;
                        break;
                    }
                }
            }
            if (valid == false) throw (string(" Invalid Order"));
        }
    }
    
    void valid_repeat(string number) {
        if (number.size() > 2) {
            string num;
            for (int i = 3; i < number.size(); i++) {
                if (number.at(i) == number.at(i - 1) && number.at(i) == number.at(i - 2) && number.at(i) == number.at(i - 3)) {
                    throw (string(" Invalid. Too many numerals in a row."));
                }
            }
        }
    }
    
    void set_numeral(string number) {
        valid_num(number);
        valid_repeat(number);
        for (int i = 0; i < number.size(); i++) {
            if (number.at(i) == 'I') {
                numeral.push(I);
            }
            else if (number.at(i) == 'V') {
                numeral.push(V);
            }
            else if (number.at(i) == 'X') {
                numeral.push(X);
            }
            else if (number.at(i) == 'L') {
                if (i != 0) {
                    valid_order(number);
                }
                numeral.push(L);
            }
            else if (number.at(i) == 'C') {
                if (i != 0) {
                    valid_order(number);
                }
                numeral.push(C);
            }
            else if (number.at(i) == 'D') {
                if (i != 0) {
                    valid_order(number);
                }
                numeral.push(D);
            }
            else if (number.at(i) == 'M') {
                if (i != 0) {
                    valid_order(number);
                }
                numeral.push(M);
            }
        }
    };
    
    int roman_to_modern() {
        int temp = 0;
        while (!numeral.empty()) {
            temp = 0;
            temp = numeral.top();
            numeral.pop();
            if (!numeral.empty() && temp > numeral.top()) {
                temp -= numeral.top();
                numeral.pop();
                modernNum += temp;
            }
            else {
                modernNum += temp;
            }
        }
            return modernNum;
    }
    
    friend ostream& operator<< (ostream& os, RomanNumeral& num) {
        os << " " << num.roman_to_modern();
        return os;
    }
    
};

#endif*/ /* RomanNumeral_h */
