/* Question 2:
 * Write a program that, prints a ‘pine tree’ consisting of triangles of increasing sizes, filled
 * with a character (eg. ‘*’ or ’+’ or ‘$’ etc).
 * Your program should interact with the user to read the number of triangles in the tree and
 * the character filling the tree.
 * */

#include <iostream>
using namespace std;

void printShiftedTriangle(int n, int m, char symbol);
//Prints an n-line triangle, filled with symbol characters, shifted m spaces from the left
//margin.

void printPineTree(int n, char symbol);
//It prints a sequence of n triangles of increasing sizes (the smallest triangle is a 2-line
//triangle), which form the shape of a pine tree. The triangles are filled with the symbol
//character.

int main() {
    int inputInt;
    char inputChar;

    cout << "Welcome to C.A. Pine Tree" << endl;
    cout << "Please enter a positive integer: ";
    cin >> inputInt;
    cout << "Thanks. Now please enter any single character: ";
    cin >> inputChar;
    printPineTree(inputInt, inputChar);

    return 0;
}

void printShiftedTriangle(int n, int m, char symbol){
    int lineCount, spaceCount, charCount;
    int centerAlign;
    int lineTotalChars;

    for(lineCount = 1; lineCount <= n; lineCount +=1) { 
        // First for loop prints to triangle's left margin (num of min spaces for all lines in given triangle)
        for(spaceCount = 1; spaceCount <= m; spaceCount += 1){
            cout << " ";
        }

        // Second for loop prints the remaining spaces specific to each line
        centerAlign = n - lineCount;
        for (spaceCount = 1; spaceCount <= centerAlign; spaceCount +=1){
            cout << " ";
        }

        // Third for loop prints the appropriate num of symbols to the screen
        lineTotalChars = (2 * lineCount) -1;
        for (charCount = 1; charCount <= lineTotalChars; charCount +=1){
            cout << symbol;
        }

        cout << endl;
    }
    return;
}

void printPineTree(int n, char symbol){
    // Prints n number of triangles, calculates number of spaces and lines to print.

    int currTriangle; // num input by user
    int numOfLinesToPrint; // initialize at 2 and increment by 1 every iteration
    int spaces; // num of spaces to print left-side for each triangle

    for(currTriangle = 1; currTriangle <= n; currTriangle += 1){
        spaces = n - currTriangle;
        numOfLinesToPrint = currTriangle + 1;
        printShiftedTriangle(numOfLinesToPrint, spaces, symbol);
    }
    return;
}
