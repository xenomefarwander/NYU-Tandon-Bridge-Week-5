/* Question 5:
 * Takes an input n and searches for perfect numbers and amicable numbers across the range [2, n].
 * Two possible implementations: 
 * 1) (without string library) Prints numbers to screen as soon as they are found (good for very large numbers)
 * 2) (with string library) Saves each category of results to a string variable and outputs after looping is finished 
 * (looks nicer, but takes a very long time to output for large numbers)
 * 
 * Algorithm runtime: O(2n)
 */

#include <iostream>
#include <cmath>
// #include <string>
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
        else if (i > sumDivs){
            continue;
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

    int countDivs;

    sumDivs = 0; // declared in global variables so that main() can access and call function testAmicableNumbers()
    countDivs = 0;
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

    if (num1 == sumDivsNum2) {
        return true;
    }
    else
        return false;
}