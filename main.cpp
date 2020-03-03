#include <iostream>
#include <fstream>
#include <sstream>

#include "Numeral.h"
using namespace std;

int main(int argc, const char * argv[]) {
    
    //Open input and output files for reading in and out our numbers. 
    if (argc < 3)
    {
       cerr << "Please provide name of input and output files";
       return 1;
    }
    cout << "Input file: " << argv[1] << endl;
    ifstream in(argv[1]);
    if (!in)
    {
       cerr << "Unable to open " << argv[1] << " for input";
       return 2;
    }
    cout << "Output file: " << argv[2] << endl;
    ofstream out(argv[2]);
    if (!out)
    {
       in.close();
       cerr << "Unable to open " << argv[2] << " for output";
       return 3;
    }
    
    for (string line; getline(in, line);) {
        try {
            if (line.size() == 0) continue;
            out << endl << line;
            
            //Create a Numeral object. Since all we want to do is convert it then we never need it, I just make it a pointer and then delete it.
            Numeral *num = new Numeral();
            num->set_numeral(line);
            
            out << *num;
            
            //get rid of it since all we needed it for was to output the number. and memory leaks.
            delete num;
            
        } catch (string error) {
            out << error;
        }
    }
    
    
    return 0;
}
