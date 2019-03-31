#include <iostream>
#include <cstdlib>
#include "rec_fun.h"

using namespace std;
using namespace sajad_rec;

int main()
{
	rec recursion;

	cout << "binary_print(cout, 44):"<<"\n";
	recursion.binary_print(cout, 44);

	cout << "\nTriangle(cout, 3, 5):" << "\n";
	recursion.triangle(cout, 3, 5);

	cout << "\nindented_sentences(1, 4)" << "\n";
	recursion.indented_sentences(1, 4);

	cout << "\npow(3, 3):" << "\t";
	cout << recursion.pow(3, 3) << "\n";

}
