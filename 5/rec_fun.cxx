// Sajad Gholamzadehrizi - sajad1993gh@gmail.com
// rec_fun.cxx

#include <iostream>
#include <cassert>
#include <cstdlib>  // Provides NULL, rand, size_t
#include "rec_fun.h"
using namespace std;

namespace sajad_rec
{

  void rec::binary_print(ostream& outs, unsigned int n)
  {
    if (n == 0 || n == 1) cout << n;
    else {
      binary_print(outs, n/2);  // reduce n by order of 2
      binary_print(outs, n%2);  // print binary for that power of 2
    }
  }

  void rec::triangle(ostream& outs, unsigned int m, unsigned int n)
  {
    assert(m <= n);
    if(m == n) {
        for (int i = 0; i < m; i++) cout << "*";
        cout << endl;
      } else {
        for (int i = 0; i < m; i++) cout << "*";
        cout << endl;
        triangle(outs, m + 1, n);
        for (int i = 0; i < m; i++) cout << "*";
        cout << endl;
      }
    }

    double rec::pow(double x, int n)
    {
      if (x == 0) assert(n > 0);
      if (n == 0) return 1;
      if (n == 1) return x;
      else if(n < 0) return (1 / pow(x,-n));
      else if(n > 0 && n % 2 == 0) return (pow(x, n/2) * pow(x, n/2));
      else return (x*pow(x, n/2) * pow(x, n/2));
    }

    void rec::indented_sentences(size_t m, size_t n)
    {
      assert(m <= n+1);
      if (m <= n) {
        for(size_t i = m; i > 1; i--) cout << " ";
        cout << "This was written by calling number " << m << endl;
        indented_sentences(m+1, n);
        for(size_t i = m; i > 1; i--) cout << " ";
        cout << "This was ALSO written by calling number " << m << endl;
      }
    }

}
