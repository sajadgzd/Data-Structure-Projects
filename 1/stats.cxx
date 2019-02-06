
#include <iostream>
//#include <math.h>
#include <cassert>
#include "stats.h"
using namespace std;

namespace main_savitch_2C
{
  statistician::statistician()
  {
    count= 0;
    total= 0;
    //tinyest;
    //largest;
  }

  void statistician::next(double r)
  {
    if(count == 0){
      tinyest = r ;
      largest = r ;
    }
    total += r;
    count++;
    if(r<tinyest){
      tinyest = r;
    }
    else if(r>largest){
      largest = r;
    }

  }

  void statistician::reset( )
  {
    count = 0;
    total = 0;
    tinyest = 0;
    largest = 0;
  }

  int statistician::length() const
  //     Postcondition: The return value is the length of the sequence that has
  //     been given to the statistician (i.e., the number of times that the
  //     next(r) function has been activated).
  {
    return count;
  }

  double statistician::sum() const
  {
    return total;
  }
  double statistician::mean() const
    //     Precondition: length( ) > 0
    //     Postcondition: The return value is the arithmetic mean (i.e., the
    //     average of all the numbers in the statistician's sequence).
  {
    assert(count>0);
    return total/count ;
  }

  double statistician::minimum() const
//     Precondition: length( ) > 0
//     Postcondition: The return value is the tinyest number in the
//     statistician's sequence.
  {
    assert(count>0);
    //return
  }

  double statistician::maximum() const
  {
  //assert();
  }

  statistician operator +
        (const statistician& s1, const statistician& s2)
        {

        }

  statistician operator *
        (double scale, const statistician& s)
        {

        }

  bool operator ==(const statistician& s1, const statistician& s2)
  {

  }


}
