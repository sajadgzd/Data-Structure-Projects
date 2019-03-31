#include <iostream>
#include <cstdlib>
#include "rec_fun.h"

using namespace std;
using namespace sajad_rec;

int main()
{
	rec recursion;

	cout << "binary_print(cout, 4):"<<"\n";
	recursion.binary_print(cout, 4);

	cout << "\nTriangle(cout, 3, 5):" << "\n";
	recursion.triangle(cout, 3, 5);

	cout << "\npow(5, 3):" << "\t";
	cout << recursion.pow(5, 3) << "\n";

  cout << "\nindented_sentences(1, 4)" << "\n";
  recursion.indented_sentences(1, 4);

}
