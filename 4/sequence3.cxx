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
//   1. The number of items in the sequence is stored in the member variable used;
//   2. If there is a current item, then it lies in data[current_index]; if there is
//   no current item, then current_index equals used.
//   3. The actual items of the sequence are stored in a partially filled dynamic array.
//      The array is dynamic, pointed to by the member variable data.
//      A larger dynamic array may be constructed if needed as the program runs.
//    4. The total size of the dynamic array(current capacity) is in the member variable capacity.
//    5.
//    6.
//
