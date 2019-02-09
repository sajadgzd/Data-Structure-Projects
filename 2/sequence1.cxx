// FILE: sequence1.cxx
// CLASS IMPLEMENTED: sequence (see sequence1.h for documentation)
// INVARIANT for the sequence class:
//   1. The number of items in the sequence is stored in the member variable used;
//   2. For an empty sequence, we do not care what is stored in any of data; for a
//      non-empty sequence the items are stored in a sequence order from data[0] through
//      data[used-1], and we don't care what's in the rest of data.
//   3.If there is a current item, then it lies in data[current_index]; if there is
//   no current item, then current_index equals used.

#include <algorithm> // Provides copy function
#include <cassert>   // Provides assert function
#include "sequence1.h"
using namespace std;

namespace main_savitch_3
{
  const sequence::size_type sequence::CAPACITY;
  sequence::sequence()
  {
    used = 0;
  }
  void sequence::start()
  //     Postcondition: The first item on the sequence becomes the current item
  //     (but if the sequence is empty, then there is no current item).
  {
    current_index = 0;
  }
  void sequence::advance()
  //     Precondition: is_item returns true.
  //     Postcondition: If the current item was already the last item in the
  //     sequence, then there is no longer any current item. Otherwise, the new
  //     current item is the item immediately after the original current item.
  {
    assert(is_item());
    if(current_index>=used-1) current_index = used;
    else current_index++;

  }
  void sequence::insert(const value_type& entry)
  //     Precondition: size( ) < CAPACITY.
  //     Postcondition: A new copy of entry has been inserted in the sequence
  //     before the current item. If there was no current item, then the new entry
  //     has been inserted at the front of the sequence. In either case, the newly
  //     inserted item is now the current item of the sequence.
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
  //     Precondition: size( ) < CAPACITY.
  //     Postcondition: A new copy of entry has been inserted in the sequence after
  //     the current item. If there was no current item, then the new entry has
  //     been attached to the end of the sequence. In either case, the newly
  //     inserted item is now the current item of the sequence.
  {
    assert(size() < CAPACITY);
    size_type i;
    if(!is_item()) current_index = used;
    current_index++;
    for(i= used; i > current_index; i--){
      data[i]=data[i-1];
    }
    data[current_index]=entry;
    used++;
  }
  void sequence::remove_current()
  //     Precondition: is_item returns true.
  //     Postcondition: The current item has been removed from the sequence, and the
  //     item after this (if there is one) is now the new current item.
  {
    assert(is_item());
    size_type i;
    for(i = current_index+1 ; i< used ; i++){
      data[i-1]=data[i];
    }
    used--;
  }
  sequence::size_type sequence::size( ) const
  //   size_type size( ) const
  //     Postcondition: The return value is the number of items in the sequence.
  {
    return used;
  }
  bool sequence::is_item( ) const
  //     Postcondition: A true return value indicates that there is a valid
  //     "current" item that may be retrieved by activating the current
  //     member function (listed below). A false return value indicates that
  //     there is no valid current item.
  {
    if(current_index<used) return true;
    else return false;
  }
  sequence::value_type sequence::current( ) const
  //     Precondition: is_item( ) returns true.
  //     Postcondition: The item returned is the current item in the sequence.
  {
    assert(is_item());
    return data[current_index];
  }

}
