 //a constructor, start, insert, advance, and current

 // Provided by:   ____________(Sajad Gholamzadehrizi)__________
 // Email Address: ____________(sajad1993gh@gmail.com)_________
 // FILE: sequence2.cxx
 // CLASS IMPLEMENTED: sequence (see sequence2.h for documentation)
 // INVARIANT for the sequence class:
 //   1. The number of items in the sequence is stored in the member variable used;
 //   2. For an empty sequence, we do not care what is stored in any of data; for a
 //      non-empty sequence the items are stored in a sequence order from data[0] through
 //      data[used-1], and we don't care what's in the rest of data.
 //   3.If there is a current item, then it lies in data[current_index]; if there is
 //   no current item, then current_index equals used.
 //   4. The actual items of the sequence are stored in a partially filled dynamic array.
//      The array is dynamic, pointed to by the member variable data.
//    5. The total size of the dynamic array in the member variable capacity.

 #include <cassert>   // Provides assert function
 #include <algorithm> // Provides copy function
 #include "sequence2.h"
 using namespace std;

 namespace main_savitch_4
 {
   const sequence::size_type sequence::DEFAULT_CAPACITY;
   sequence::sequence(size_type initial_capacity)
   {
   data = new value_type[initial_capacity];
   capacity = initial_capacity;
   used = 0;
   current_index = 0;
   }

   sequence::sequence(const sequence& source)
   {
     data = new value_type[source.capacity];
     capacity = source.capacity;
     used = source.used;
     copy(source.data, source.data + used, data);
   }

   sequence::~sequence()
   {
     delete[] data;
   }

   void sequence::start()
   {
     current_index = 0;
   }

   //
   void sequence::advance()
   {
     assert(is_item());
     current_index++;
   }

   void sequence::insert(const value_type& entry)
   {
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
     size_type i;
     if(!is_item()) current_index = used-1;
     current_index++;
     for(i= used; i > current_index; i--)
     {
       data[i]=data[i-1];
     }
     data[current_index]=entry;
     used++;
   }

   void sequence::remove_current()
   {
     assert(is_item());
     size_type i;
     for(i = current_index+1 ; i< used ; i++)
     {
       data[i-1]=data[i];
     }
     used--;
   }

   void resize(size_type new_capacity)
   //library facility used: algorithm
   {
     value_type* larger_array;
     if(new_capacity == capacity)
      return;
     if(new_capacity<used)
      new_capacity == used;
     larger_array = new value_type[new_capacity];
     copy(data, data+used, larger_array)
     delete[] data;
     data = larger_array;
     capacity = new_capacity;
   }

   void sequence::operator =(const sequence& source)
   //library facility used: algorithm
   {
     value_type *new_data;
     //check for possible self assignment:
     if(this == &source)
      return;
     if(capacity != source.capacity)
     {
      new_data = new value_type[source.capacity];
      delete[] data;
      data = new_data;
      capacity = source.capacity;
     }
     used = source.used;
     copy(source.data, source.data + used, data);
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
