// FILE: sequence1.cxx
// CLASS IMPLEMENTED: sequence (see sequence1.h for documentation)
// INVARIANT for the bag class:
//   1. The number of items in the bag is in the member variable used;
//   2. For an empty bag, we do not care what is stored in any of data; for a
//      non-empty bag the items in the bag are stored in data[0] through
//      data[used-1], and we don't care what's in the rest of data.

#include <algorithm> // Provides copy function
#include <cassert>   // Provides assert function
#include "sequence1.h"
using namespace std;

namespace main_savitch_3
{
  const sequence::size_type sequence::CAPACITY;
  sequence::sequence()
  {

  }
  void sequence::start()
  //     Postcondition: The first item on the sequence becomes the current item
  //     (but if the sequence is empty, then there is no current item).
  {
    cur = first
  }
  void sequence::advance()
  //     Precondition: is_item returns true.
  //     Postcondition: If the current item was already the last item in the
  //     sequence, then there is no longer any current item. Otherwise, the new
  //     current item is the item immediately after the original current item.
  {
    cur = next

  }
  void sequence::insert(const value_type& entry)
  //     Precondition: size( ) < CAPACITY.
  //     Postcondition: A new copy of entry has been inserted in the sequence
  //     before the current item. If there was no current item, then the new entry
  //     has been inserted at the front of the sequence. In either case, the newly
  //     inserted item is now the current item of the sequence.
  {
    assert(size() < CAPACITY);
    cur = entry
  }
  void sequence::attach(const value_type& entry)
  //     Precondition: size( ) < CAPACITY.
  //     Postcondition: A new copy of entry has been inserted in the sequence after
  //     the current item. If there was no current item, then the new entry has
  //     been attached to the end of the sequence. In either case, the newly
  //     inserted item is now the current item of the sequence.
  {
    cur entry
  }
  void sequence::remove_current()
  //     Precondition: is_item returns true.
  //     Postcondition: The current item has been removed from the sequence, and the
  //     item after this (if there is one) is now the new current item.
  {
    assert(is_item());
    data[cur]=data[cur+1]

  }
  sequence::size_type sequence::size( ) const
  //   size_type size( ) const
  //     Postcondition: The return value is the number of items in the sequence.
  {
    return x;
  }
  bool sequence::is_item( ) const
  //     Postcondition: A true return value indicates that there is a valid
  //     "current" item that may be retrieved by activating the current
  //     member function (listed below). A false return value indicates that
  //     there is no valid current item.
  {

  }
  sequence::value_type sequence::current( ) const
  //     Precondition: is_item( ) returns true.
  //     Postcondition: The item returned is the current item in the sequence.
  {
    return cur
  }



}
