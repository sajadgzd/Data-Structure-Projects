//You will write all of this file, which will have the invariant of the sequence class,
//the implementations of all the member functions of the sequence class,
//and the Big-Os of these functions.
//You should write the time analysis in the comment lines of each function.  The breakdowns of points (of 100) will be the followings:
//Basis points (70) if your implementation passes the seq_ex3 exam
//Invariant of the class (5 points)
//Run time analysis (15 points)
//Other implementation details such as compiling warning, code styles and efficiency, etc. (10 points)

// Provided by:   ____________(Sajad Gholamzadehrizi)__________
// Email Address: ____________(sajad1993gh@gmail.com)_________
// FILE: sequence3.cxx
// CLASS IMPLEMENTED: sequence (see sequence3.h for documentation)
// INVARIANT for the sequence class:
//   1. The items in the sequence are stored on a linked list;
//   2. The head pointer of the list is stored in the member variable head_ptr;
//   3. The tail pointer of the list is stored in the member variable tail_ptr;
//   4. The total number of items in the list is stored in the member variable
//     many_nodes.
//   5. The current node is pointed by a pointer which is a member variable named
//      cursor
//   6. The node before the current node is pointed by a pointer that us a member variable
//      named precursor
#include <cassert>
#include "sequence3.h"
#include "node1.h"
using namespace std;
namespace main_savitch_5
{
    sequence::sequence()
    {
      many_nodes = 0;
      head_ptr = NULL;
      tail_ptr = NULL;
      cursor = NULL;
      precursor = NULL;
    }
    sequence::sequence(const sequence& source)
    {
      list_copy(source.head_ptr, head_ptr, tail_ptr);
      many_nodes = source.many_nodes;
      head_ptr = source.head_ptr;
      tail_ptr = source.tail_ptr;
    }

    sequence::~sequence()
    {
      list_clear(head_ptr);
      many_nodes = 0;
      head_ptr = NULL;
      tail_ptr = NULL;
      cursor = NULL;
      precursor = NULL;
    }

    void sequence::start()
    {
      cursor = head_ptr;
      precursor = NULL;
    }

    void sequence::advance()
    {
      assert(is_item());
      cursor = cursor->link();
    }

    void sequence::insert(const value_type& entry)
    {
      list_insert(precursor, entry);
      many_nodes++;
      cursor = precursor;
    }

    void sequence::attach(const value_type& entry)
    {
      list_insert(cursor->link(), entry);
      many_nodes++;
      cursor = precursor;
    }

    void sequence::remove_current( )
    {
      assert(is_item());
      list_remove(precursor);
      cursor = cursor -> link();
    }

    void sequence::operator =(const sequence& source)
    {
      if (this == &source)
            return;

      list_clear(head_ptr);
      many_nodes = 0;
      head_ptr = NULL;
      tail_ptr = NULL;
      cursor = NULL;
      precursor = NULL;

      list_copy(source.head_ptr, head_ptr, tail_ptr);
      many_nodes = source.many_nodes;
      head_ptr = source.head_ptr;
      tail_ptr = source.tail_ptr;
    }

    sequence::size_t sequence::size( ) const
    {

    }

    bool sequence::is_item( ) const
    {

    }

    sequence::value_type sequence::current( ) const
    {
      
    }













}
