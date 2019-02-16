 a constructor, start, insert, advance, and current

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

 #include <cassert>   // Provides assert function . k
 using namespace std;

 namespace main_savitch_4
 {
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
   



}
