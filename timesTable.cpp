////////////////////////////////////////////////////////////////////////////////
//
//  This is a simple command line program to create a visuospatial times table
//
//  It will take up to two command line arguments:
//    ARGUMENT 1: sets the size of the table (default is 5 for 5 x 5)
//    ARGUMENT 2: sets the character for each item (default is 'o')
//
//  AUTHOR: Jason R
//
////////////////////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

char* nItem(char ch, int n);
char* itemSpace(char ch);

////////////////////////////////////////////////////////////////////////////////
//  MAIN: reads arguments, prints out collections of itmes in nested for-loops
//
int main(int argc, char** argv) {

    //default values
    int x = 5;
    char c = 'o';

    //command line arguments
    if (argc >= 2) {
        x = atoi(argv[1]);
    }
    if (argc == 3) {
        c = argv[2][0];
    }

    //prints out collections of items
    cout << "\n\n";
    for (int k = 0; k < x; k++) {            //y-axis separated collections
        for (int j = x - k; j < x+1; j++) {  //height of each row
            cout << "   ";
            for (int i = 1; i < x+1; i++) {  //width of each column
                cout << nItems(c,i) << "  "; //collection string
            }
            cout << "\n";
        }
        cout << endl;
    }
    cout << "\n\n";
}

////////////////////////////////////////////////////////////////////////////////
//  NUMBER OF CHARACTERS: creates a string of a specified number of items
//
char* nItems(char ch, int n) {
    char* str = new char[n*2 + 2];
    for (int i = 0; i < n; i++)
        strcat(str, itemSpace(ch));
    return str;
}

////////////////////////////////////////////////////////////////////////////////
//  CHARACTER SPACE: creates a string of an item (character) followed by a space
//
char* itemSpace(char ch) {
    char* s = new char[3];
    s[0] = ch;
    s[1] = ' ';
    s[2] = '\0';
    return s;
}
