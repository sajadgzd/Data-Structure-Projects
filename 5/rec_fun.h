// Sajad Gholamzadehrizi - sajad1993gh@gmail.com
//  rec_fun.h
//
// void binary_print(ostream& outs, unsigned int n)
// Postcondition: The function prints the value of n as a BINARY number to the ostream outs. If n is zero, then a single zero is printed; otherwise no leading zeros are printed in the output. The '\n' character is NOT printed at the end of the output.
// Example:
//  n=0  Output:0
//  n=4  Output:100
//  n=27 Output:11011
//
// void triangle(ostream& outs, unsigned int m, unsigned int n)
// Precondition: m <= n
// Postcondition: The function has printed a pattern of 2*(n-m+1) lines
// to the output stream outs. The first line contains m asterisks, the next
// line contains m+1 asterisks, and so on up to a line with n asterisks.
// Then the pattern is repeated backwards, going n back down to m.
// Example output:
//     triangle(cout, 3, 5) will print this to cout:
//     ***
//     ****
//     *****
//     *****
//     ****
//     ***
//
// double pow(double x, int n);
// Precondition: If x is zero, then n must be positive.
// Postcondition: The value returned is x raised to the power n.
//
// void indented_sentences(size_t m, size_t n);
// precondition: m <=n;
// postcondition: print out the above pattern by calling number from m to n


#ifndef SAJAD_REC_H
#define SAJAD_REC_H
#include <iostream>
#include <cstdlib>


namespace sajad_rec
{
	class rec
	{
	public:
    void binary_print(std::ostream& outs, unsigned int n);
    void triangle(std::ostream& outs, unsigned int m, unsigned int n);
    double pow(double x, int n);
    void indented_sentences(size_t m, size_t n);
	};
}

#endif
