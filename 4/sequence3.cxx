// Provided by:   ____________(Sajad Gholamzadehrizi)__________
// Email Address: ____________(sajad1993gh@gmail.com)_________
// FILE: sequence3.cxx
// CLASS IMPLEMENTED: sequence (see sequence3.h for documentation)
// INVARIANT for the sequence class:
//   1. The items in the sequence are stored on a linked list;
//   2. The head pointer of the list is stored in the member variable head_ptr;
//   3. The tail pointer of the list is stored in the member variable tail_ptr;
//   4. The total number of items in the list is stored in the member variable
//      many_nodes.
//   5. The current node is pointed by a pointer which is stored in the member variable
//      cursor
//   6. The node before the current node is pointed by a pointer that is stored
//       in the member variable precursor
#include <cassert>
#include <cstdlib>
#include "sequence3.h"
#include "node1.h"
using namespace std;

namespace main_savitch_5
{
    sequence::sequence()
    // Time analysis: Constant - O(1)
    {
        head_ptr = NULL;
        tail_ptr = NULL;
        cursor = NULL;
        precursor = NULL;
        many_nodes = 0;
    }

    sequence::sequence(const sequence &source)
    // Time analysis: Linear - O(n)
    {
        list_copy(source.head_ptr, head_ptr, tail_ptr);
        many_nodes = source.many_nodes;
        if (source.precursor == NULL)
        {
            if (source.cursor == NULL)
            {
                cursor = NULL;
            }
            else
            {
                cursor = head_ptr;
            }
            precursor = NULL;
        }
        else
        {
            if (source.precursor == NULL)
            {
                 cursor = head_ptr;
                 precursor = NULL;
            }
            else
            {
            node* src_pter;
            src_pter = source.head_ptr;
            precursor = head_ptr;
                 while (src_pter != source.precursor)
                 {
                       src_pter = src_pter->link();
                       precursor = precursor->link();
                 }
                 cursor = precursor->link();
            }
        }
    }

    void sequence::operator =(const sequence &source)
    // Time analysis: Linear - O(n)
    {
            if(this == &source)
            return;

            list_copy(source.head_ptr, head_ptr, tail_ptr);
            many_nodes = source.many_nodes;
            if (source.precursor == NULL)
            {
                if (source.cursor == NULL)
                {
                    cursor = NULL;
                }
                else
                {
                    cursor = head_ptr;
                }
                precursor = NULL;
            }
            else
            {
                if (source.precursor == NULL)
                {
                     cursor = head_ptr;
                     precursor = NULL;
                   }
                else
                {
                node* src_pter;
                src_pter = source.head_ptr;
                precursor = head_ptr;
                     while (src_pter != source.precursor)
                     {
                           src_pter = src_pter->link();
                           precursor = precursor->link();
                     }
                     cursor = precursor->link();
                  }
            }
    }

    sequence::~sequence()
    // Time analysis: Linear - O(n)
    {
        list_clear(head_ptr);
        tail_ptr = NULL;
        cursor = NULL;
        precursor = NULL;
        many_nodes = 0;
    }

    void sequence::start()
    // Time analysis: Constant - O(1)
    {
        precursor = NULL;
        cursor = head_ptr;
    }

    void sequence::advance()
    // Time analysis: Constant - O(1)
    {
        assert(is_item());
        precursor = cursor;
        cursor = cursor->link();
    }

    void sequence::insert(const sequence::value_type& entry)
    // Time analysis: Constant - O(1)
    {
        if (is_item())
          {
            if (precursor == NULL)   //if the cursor is pointing at the head
              {
                list_head_insert(head_ptr, entry);
                precursor = NULL;
                cursor = head_ptr;
              }
              else                   //if the cursor is somewhere in the middle
                {
                  list_insert(precursor, entry);
                  cursor = precursor->link();
                }
           }
        else
          {
              if (many_nodes == 0)
                {
                  list_head_insert(head_ptr, entry);
                  precursor = NULL;
                  cursor = head_ptr;
                  tail_ptr = head_ptr;
                }
              else            //if the cursor if out of the list
                {
                  list_head_insert(head_ptr, entry);
                  precursor = NULL;
                  cursor = head_ptr;
                }
           }
        many_nodes++;
    }

    void sequence::attach(const sequence::value_type& entry)
    // Time analysis: Constant - O(1)
    {
        if (is_item())
          {
              if (cursor == tail_ptr)
                {
                  list_insert(cursor, entry);
                  precursor = cursor;
                  cursor = cursor->link();
                  tail_ptr = cursor;
                }
              else
                {
                  list_insert(cursor, entry);
                  precursor = cursor;
                  cursor = cursor->link();
                }
           }
        else
          {
            if (many_nodes == 0)
                {
                  list_head_insert(head_ptr, entry);
                  precursor = NULL;
                  cursor = head_ptr;
                  tail_ptr = head_ptr;
                }
            else    // if the cursor is run out of the list
                {
                  list_insert(precursor, entry);
                  tail_ptr = tail_ptr->link();
                  cursor = tail_ptr;
                }
           }
        many_nodes++;
    }

    void sequence::remove_current()
    // Time analysis: Constant - O(1)
    {
      assert(is_item());
      if (precursor == NULL)    //if the cursor is pointing at the head
        {
          list_head_remove(head_ptr);
          cursor = head_ptr;
        }
      else
        {
          cursor = cursor->link();
          list_remove(precursor);
        }
      many_nodes--;
    }

    sequence::size_type sequence::size() const
    // Time analysis: Constant - O(1)
    {
        return many_nodes;
    }

    bool sequence::is_item() const
    // Time analysis: Constant - O(1)
    {
        return (cursor != NULL);
    }

    sequence::value_type sequence::current() const
    // Time analysis: Constant - O(1)
    {
        assert(is_item());
        return cursor->data();
    }

}
