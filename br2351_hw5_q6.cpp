/*Question 6:
 * The number e is an important mathematical constant that is the base of the natural logarithm. e
 * also arises in the study of compound interest, and in many other applications.
 * Background of e: https://en.wikipedia.org/wiki/E_(mathematical_constant)
 *
 *
 * The value of e is approximately equal to 2.71828. We can get an approximate value of e, by
 * calculating only a partial sum of the infinite sum above (the more addends we add, the better
 * approximation we get).
 * Implement the function:
 * double eApprox(int n)
 * This function is given a positive integer n, and returns an approximation of e, calculated by the
 * sum of the first (n+1) addends of the infinite sum above.
 * */

#include <iostream>
using namespace std;

double eApprox(int n);

int main() {

    int n;

    /* Uncomment lines below to test and track precision */
//    cout.precision(30);
//    for (int n = 1; n <= 15; n++) {
//        cout << "n = " << n << '\t' << eApprox(n) << endl;
//    }

    cout << "Please enter a positive integer n: " << endl;
    cin >> n;

    cout << "Value of e (approximated by calculating partial sum of the first " << (n+1) << " terms in infinite sum):" << endl;
    cout << eApprox(n) << endl;

    return 0;
}

double eApprox (int n){
    int i;
    double currFact;
    double eSum;

    eSum = 1.0;
    currFact = 1.0;

    for (i = 1; i <= n; i += 1){
        currFact *= i;
        eSum += 1.0 / currFact;
    }

    return eSum;
}
