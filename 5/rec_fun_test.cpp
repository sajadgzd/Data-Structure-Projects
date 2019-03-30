#include <iostream>     // Provides cout and cin
#include <cstdlib>      // Provides EXIT_SUCCESS
#include "rec_fun.h"

using namespace std;
using namespace sajad_rec;

int main()
{
	int inputNumber;
	rec_fun recursion;
	double base, exponent;

	cout << "Input a number to convert to binary:" << endl;
	cin >> inputNumber;
	cout << "Output in Binary:";
	recursion.binary_print(cout, inputNumber);

	cout << "\n\nTriangle(cout, 3, 5) will print this to cout:" << endl;
	recursion.traingle(cout, 3, 9);

	cout << "\n\nA recursive function to indent a sentence with starting point at 1 and max depth of 4" << endl;
	recursion.indented_sentences(1, 4);

	cout << "\nPlease input a base for the power recursive function" << endl;
	cin >> base;

	cout << "\nPlease input an exponent for the power recursive function" << endl;
	cin >> exponent;
	cout << recursion.pow(base, exponent) << endl;

	return 0;

}
