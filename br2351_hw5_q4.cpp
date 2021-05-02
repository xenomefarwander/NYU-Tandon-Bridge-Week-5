/* Question 4:
a. Implement a function:
void printDivisors(int num)
This function is given a positive integer num, and prints all of num’s divisors in an ascending
order, separated by a space.
For Example, if we call printDivisors(100), the expected output is:
1 2 4 5 10 20 25 50 100
Implementation requirement: Pay attention to the running time of your function. An
efficient implementation would run in Θ"√𝑛𝑢𝑚'.
b. Use the function above when implementing a program that reads from the user a positive
integer (≥2), and prints all it’s divisors.
Your program should interact with the user exactly as it shows in the following example:
Please enter a positive integer >= 2: 100
1 2 4 5 10 20 25 50 100
 */

#include <iostream>
#include <cmath>
using namespace std;

void printDivisors(int num);
/* This function is given a positive integer num, and prints all of num’s divisors in an ascending
order, separated by a space.
Implementation requirement: Pay attention to the running time of your function. An
efficient implementation would run in Θ(√𝑛𝑢𝑚).
 */

int main() {
    int inputInt;
    int i;

    cout << "Please enter a positive integer >= 2: ";
    cin >> inputInt;

    for (i = 2; i <= inputInt; i += 1){
        printDivisors(i);
        cout << endl;
    }

    return 0;
}

void printDivisors(int num){
    int i, j;

    for (i = 1; i <= sqrt(num); i +=1) {
        if (num % i == 0)
            cout << i << " ";
    }

    if (sqrt(num) == (int)sqrt(num))
        j = i - 2;
    else
        j = i - 1;

    for (i = j; i >= 1; i -=1){
        if (num % i == 0)
            cout << num/i << " ";
    }

    return;
}