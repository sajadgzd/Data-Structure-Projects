 // Provided by:   ____________(Sajad Gholamzadehrizi)__________
 // Email Address: ____________(sajad1993gh@gmail.com)_________
 // FILE: sequence2.cxx
 // CLASS IMPLEMENTED: sequence (see sequence2.h for documentation)
 // INVARIANT for the sequence class:
 //   1. The number of items in the sequence is stored in the member variable used;
 //   2. If there is a current item, then it lies in data[current_index]; if there is
 //   no current item, then current_index equals used.
 //   3. The actual items of the sequence are stored in a partially filled dynamic array.
//      The array is dynamic, pointed to by the member variable data.
//      A larger dynamic array may be constructed if needed as the program runs.
//    4. The total size of the dynamic array(current capacity) is in the member variable capacity.

#include <algorithm>
#include <cassert>
#include "sequence2.h"
//
namespace main_savitch_4
{
  const sequence::size_type sequence::DEFAULT_CAPACITY;

	sequence::sequence(size_type initial_capacity)
	{
		data = new value_type [initial_capacity];
		capacity = initial_capacity;
		used = 0;
    current_index = 0;
	}

	sequence::sequence(const sequence& source)
	{
		if(this != &source) {
			data = new value_type [source.capacity];
			std::copy(source.data, source.data+source.used, data);
			capacity = source.capacity;
			used = source.used;
			if(source.is_item())
				current_index = source.current_index;
		}
	}

	sequence::~sequence()
	{
		delete [] data;
	}

	void sequence::resize(size_type new_capacity)
	{
    value_type *larger_array;
		if(new_capacity > used) {
			larger_array = new value_type [new_capacity];
			std::copy(data, data+used, larger_array);
			delete [] data;
			data = larger_array;
			capacity = new_capacity;
		}
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
		if( size() == capacity )
			resize(capacity+(0.1*capacity));
		if(!is_item())
      current_index = 0;
		for(size_type i = used; i > current_index; i--)
    {
			data[i] = data[i-1];
    }
		data[current_index] = entry;
		used++;
	}

	void sequence::attach(const value_type& entry)
	{
		if( size() == capacity )
			resize(capacity+(0.1*capacity));
		if(!is_item())
      current_index = used-1;
		current_index++;
    size_type i;
		for(i = used; i > current_index; i--)
			data[i] = data[i-1];
		data[current_index] = entry;
		used++;
	}

	void sequence::remove_current()
	{
		assert(is_item());
    size_type i;
		for(i = current_index; i < used-1; i++)
			data[i] = data[i+1];
		used--;
	}

	void sequence::operator=(const sequence& source)
	{
		if(this == &source) return;
		value_type *new_data = new value_type [source.capacity];
		std::copy(source.data, source.data+source.used, new_data);
		delete [] data;
		data = new_data;
		used = source.used;
		capacity = source.capacity;
		if(source.is_item())
			current_index = source.current_index;
		else
			current_index = used;
	}

  sequence::size_type sequence::size() const
  {
    return used;
  }

  bool sequence::is_item() const
  {
    if(current_index < used) return true;
    else return false;
  }

  sequence::value_type sequence::current() const
  {
    assert(is_item());
    return data[current_index];
  }

	void sequence::operator +=(const sequence& source)
	{
		if(capacity < used + source.used)
			resize(used + source.used);
    size_type i;
		for(i = used; i < used+source.used; i++)
			data[i] = source.data[i];
		used += source.used;
	}

	sequence::value_type sequence::operator[](size_type index) const
	{
		assert(index < used);
		return data[index];
	}

	sequence operator +(const sequence& source1, const sequence& source2)
	{
		sequence total = source1;
		total += source2;
		return total;
	}

}
