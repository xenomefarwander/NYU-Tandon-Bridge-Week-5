/*Question 5:
Consider the following definitions:
a. A proper divisor of a positive integer (≥ 2) is any of its divisors excluding the number itself.
For example, the proper divisors of 10 are: 1, 2 and 5.
b. A perfect number is a positive integer (≥ 2) that is equal to the sum of its proper divisors.
For example, 6 and 28 are perfect numbers, since:
6 = 1 + 2 + 3
28 = 1 + 2 + 4 + 7 + 14
Background of perfect numbers: https://en.wikipedia.org/wiki/Perfect_number
c. Amicable numbers are two different positive integer (≥ 2), so related that the sum of the
proper divisors of each is equal to the other number.
For example, 220 and 284 are amicable numbers, since:
284 = 1 + 2 + 4 + 5 + 10 + 11 + 20 + 22 + 44 + 55 + 110
220 = 1 + 2 + 4 + 71 + 142
Background of amicable numbers: https://en.wikipedia.org/wiki/Amicable_numbers

Write a function:
void analyzeDivisors(int num, int& outCountDivs, int& outSumDivs)
The function takes as an input a positive integer num (≥ 2), and updates two output
parameters with the number of num's proper divisors and their sum.
For example, if this function is called with num=12, since 1, 2, 3, 4 and 6 are 12s proper
divisors, the function would update the output parameters with the numbers 5 and 16.
Note: Pay attention to the running time of your function. An efficient implementation would
run in Θ"√𝑛𝑢𝑚'.
 */

#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int efficiencyCounter; // tracks number of calls to analyzeDivisors() across all functions
int sumDivs; // allows value of sumDivs from isPerfect() to be passed back to main() and to call testAmicableNumbers

void analyzeDivisors(int num, int& outCountDivs, int& outSumDivs);
/* Takes an integer and returns the number of its divisors and the sum of its divisors */

bool isPerfect(int num);
/* Takes an integer and returns true when the integer is a perfect number */

bool testAmicableNumbers(int num1, int sumDivsNum1);
/* Takes two non-perfect integers and returns true when the two numbers are amicable numbers 
 * AND num1 is less than sumDivsNum1 (to avoid finding the same pair twice when looping) */


int main() {

    int i, m;
    string perfectNumberList, amicableNumberList;
    efficiencyCounter = 0;

    cout << "Please enter a positive integer <=2: ";
    cin >> m;

    for (i = 2; i <= m; i += 1){
        if (isPerfect(i)) {
//            perfectNumberList += to_string(i) + "\n";
              cout << i << " is a perfect number" << endl;
        }
        else if (testAmicableNumbers(i, sumDivs)){
//            amicableNumberList += "(" + to_string(i) + ", " + to_string(sumDivs) + ")\n";
              cout << "(" << i << ", " << sumDivs << ") are amicable numbers" << endl;
        }
    }

//    cout << "Perfect numbers 1 to " << m << ":\n" << perfectNumberList << endl;
//    cout << "Amicable numbers 1 to " << m << ":\n" << amicableNumberList << endl;

    cout << "Efficiency counter: " << efficiencyCounter << endl;
    cout << "Input value of m: " << m << endl;
    return 0;
}

void analyzeDivisors(int num, int& outCountDivs, int& outSumDivs){
    int i;

    for (i = 1; i <= sqrt(num); i += 1){
        if (num % i == 0) {
            if (i == sqrt(num) || i == 1) {
                outCountDivs += 1;
                outSumDivs += i;
            } else {
                outCountDivs += 2;
                outSumDivs += i;
                outSumDivs += num / i;
            }
        }


    }

    return;
}

bool isPerfect(int num){
    // 1) if i = 220, then sumDivs will be 284
    // 2) take sumDivs for 220 (equal to 284); perform analyzeDivisors on sumDivs
    // 3) compare analyzeDivisors(sumDivs, , ) to  i... if analyzeDivisor(sumDivs) = i then
    // amicableNumbers prints the pair to the screen

    int countDivs;

    countDivs = 0;
    sumDivs = 0;
    analyzeDivisors(num, countDivs, sumDivs);
    efficiencyCounter += 1;

    if (num == sumDivs)
        return true;
    else
        return false;
}

bool testAmicableNumbers(int num1, int sumDivsNum1){

    int sumDivsNum2, countDivsNum2;

    countDivsNum2 = 0;
    sumDivsNum2 = 0;

    analyzeDivisors(sumDivsNum1, countDivsNum2, sumDivsNum2);
    efficiencyCounter += 1;

    if (num1 == sumDivsNum2 && num1 < sumDivsNum1) {
        return true;
    }
    else
        return false;
}