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
    if (n > 1)
    {
      binary_print(outs , n/2);
    }
    if (n == 0 || n%2 == 0)
    {
  		outs<< 0;
  	}
  	else
    {
  		outs << 1;
  	}
  }

  void rec::triangle(ostream& outs, unsigned int m, unsigned int n)
  {
    assert(m <= n);
    if(m == n) {
        for (int i = 0; i < m; i++) outs << "*";
        outs << "\n";
      }
    else {
        for (int i = 0; i < m; i++) outs << "*";
        outs << "\n";
        triangle(outs, m + 1, n);
        for (int i = 0; i < m; i++) outs << "*";
        outs << "\n";
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
        cout << "This was written by calling number " << m << "\n";
        indented_sentences(m+1, n);
        for(size_t i = m; i > 1; i--) cout << " ";
        cout << "This was ALSO written by calling number " << m << "\n";
      }
    }

}
