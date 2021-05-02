/* Question 1:
 * The Fibonacci numbers sequence, Fn, is defined as follows:
 * F1 is 1, F2 is 1, and Fn = Fn-1 + Fn-2 for n = 3, 4, 5, ...
 * In other words, each number is the sum of the previous two numbers. The first 10 numbers
 * in Fibonacci sequence are: 1, 1, 2, 3, 5, 8, 13, 21, 34, 55
 * Note: Background of Fibonacci sequence: https://en.wikipedia.org/wiki/Fibonacci_number
 * 1. Write a function int fib(int n) that returns the n-th element of the Fibonacci
 * sequence.
 * 2. Write a program that prompts the user to enter a positive integer num, and then
 * prints the num’s elements in the Fibonacci sequence.
 *
 * */

#include <iostream>
using namespace std;

int fib(int num);
int getInt ();

int main() {
    int inputInt;

    inputInt = getInt();
    cout << fib(inputInt) << endl;

    return 0;
}

int fib(int num){
    int f1 = 1;
    int f2 = 1;
    int fibNum = 0;
    int count;

    if (num == 1 || num == 2)
        return 1;
    else{
        for(count = 3; count <= num; count += 1){
            fibNum = f1 + f2;
            f2 = f1;
            f1 = fibNum;
        }
        return fibNum;
    }
}

int getInt (){
    int input = 0;

    while(true){
        cout << "Please enter a positive integer: ";
        cin >> input;
        if(cin.fail() || input < 1) {
            cout << "Invalid input. Please try again\n";
            cin.clear();
            cin.ignore(256, '\n');
            continue;
        }
        else
            break;

    }
    return input;
}