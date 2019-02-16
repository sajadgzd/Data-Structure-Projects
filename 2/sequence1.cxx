// Provided by:   ____________(Sajad Gholamzadehrizi)__________
// Email Address: ____________(sajad1993gh@gmail.com)_________
// FILE: sequence1.cxx
// CLASS IMPLEMENTED: sequence (see sequence1.h for documentation)
// INVARIANT for the sequence class:
//   1. The number of items in the sequence is stored in the member variable used;
//   2. For an empty sequence, we do not care what is stored in any of data; for a
//      non-empty sequence the items are stored in a sequence order from data[0] through
//      data[used-1], and we don't care what's in the rest of data.
//   3.If there is a current item, then it lies in data[current_index]; if there is
//   no current item, then current_index equals used.

#include <cassert>   // Provides assert function . k
using namespace std;

namespace main_savitch_3
{
  const sequence::size_type sequence::CAPACITY;
  sequence::sequence()
  {
    used = 0;
    current_index = 0;
  }
  void sequence::start()
  {
    current_index = 0;
  }
  void sequence::advance()
  {
    assert(is_item());
    current_index++;


  }
  void sequence::insert(const value_type& entry)
  {
    assert(size() < CAPACITY);
    size_type i;
    if(!is_item()) current_index = 0;
    for(i= used; i > current_index; i--){
      data[i]=data[i-1];
    }
    data[current_index]=entry;
    used++;
  }
  void sequence::attach(const value_type& entry)
  {
    assert(size() < CAPACITY);
    size_type i;
    if(!is_item()) current_index = used-1;
    current_index++;
    for(i= used; i > current_index; i--){
      data[i]=data[i-1];
    }
    data[current_index]=entry;
    used++;
  }
  void sequence::remove_current()
  {
    assert(is_item());
    size_type i;
    for(i = current_index+1 ; i< used ; i++){
      data[i-1]=data[i];
    }
    used--;
  }
  sequence::size_type sequence::size( ) const
  {
    return used;
  }
  bool sequence::is_item( ) const
  {
    if(current_index < used) return true;
    else return false;
  }
  sequence::value_type sequence::current( ) const
  {
    assert(is_item());
    return data[current_index];
  }

}
