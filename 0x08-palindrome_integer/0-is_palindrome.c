#include "palindrome.h"

/**
 * is_palindrome - checks whether or not a given
 * unsigned integer is a palindrome.
 * @n: number to be checked
 * Desc: Entry
 * Returnr - returns whether or not a number is a palimdromic number.
 **/
int is_palindrome(unsigned long n)
{
	unsigned long i, j = 0;

	i = n;

	while (i != 0)
	{
		j = j * 10;
		j = j + i % 10;
		i = i / 10;
	}
	if (n == j)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}