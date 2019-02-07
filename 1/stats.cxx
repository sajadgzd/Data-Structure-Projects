
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
    //tinyest=0;
    //largest=0;
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
  {
    return count;
  }

  double statistician::sum() const
  {
    return total;
  }
  double statistician::mean() const
  {
    assert(count!=0);
    return total/count ;
  }

  double statistician::minimum() const
  {
    assert(count!=0);
    return tinyest;
  }

  double statistician::maximum() const
  {
  assert(count!=0);
  return largest;
  }

  statistician operator +
        (const statistician& s1, const statistician& s2)
        {
          statistician totalS;
          if (s1.length( ) == 0) return s2;
          if (s2.length( ) == 0) return s1;

          totalS.total = s1.total + s2.total;
          totalS.count = s1.count + s2.count;
          if(s1.tinyest<=s2.tinyest) totalS.tinyest = s1.tinyest;
          else totalS.tinyest = s2.tinyest;
          if(s1.largest>=s2.largest) totalS.largest = s1.largest;
          else totalS.largest = s2.largest;
          return totalS;
        }

  statistician operator *
        (double scale, const statistician& s)
        {
          statistician multipliedS;
          //if(s.count==0) return s;
          //else{
          multipliedS.total = scale * s.total;
          multipliedS.count = s.count;
          if(scale<0){
          multipliedS.tinyest = (scale) * s.largest;
          multipliedS.largest = (scale) * s.tinyest;
          }
          else {
          multipliedS.tinyest = (scale) * s.tinyest;
          multipliedS.largest = (scale) * s.largest;
          }

          return multipliedS;
          //}
        }

  bool operator ==
        (const statistician& s1, const statistician& s2)
  {
    if(s1.length()==0 && s2.length()==0){
      return true;
    }
    else {
      return
        (s1.length()==s2.length())
        &&
        (s1.mean()==s2.mean())
        &&
        (s1.minimum()==s2.minimum())
        &&
        (s1.maximum()==s2.maximum())
        &&
        (s1.sum()==s2.sum());
      }

  }


}
