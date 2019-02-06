
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
    return tinyest;
  }

  double statistician::maximum() const
  {
  assert(count>0);
  return largest;
  }

  statistician operator +
        (const statistician& s1, const statistician& s2)
//     Postcondition: The statistician that is returned contains all the
//     numbers of the sequences of s1 and s2.

        {
          statistician totalS;
          totalS.total = s1.total + s2.total;
          return totalS;
        }

  statistician operator *
        (double scale, const statistician& s)
//     Postcondition: The statistician that is returned contains the same
//     numbers that s does, but each number has been multiplied by the
//     scale number.
        {
          statistician multipliedS;
          multipliedS.total = scale * s.total;
          multipliedS.count = scale * s.total;
          multipliedS.tinyest = scale * s.tinyest;
          multipliedS.largest = scale * s.largest;
          return multipliedS;

        }

  bool operator ==(const statistician& s1, const statistician& s2)
  //     Postcondition: The return value is true if s1 and s2 have the zero
  //     length. Also, if the length is greater than zero, then s1 and s2 must
  //     have the same length, the same  mean, the same minimum,
  //     the same maximum, and the same sum.
  {
    if(s1.length()==0 && s2.length()==0){
      return s1==s2;
    }



  }


}
