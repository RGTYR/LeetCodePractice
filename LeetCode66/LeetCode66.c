/* Given a non-empty array of digits representing a non-negative integer, plus one to the integer.

The digits are stored such that the most significant digit is at the head of the list, and each element in the array contain a single digit.

You may assume the integer does not contain any leading zero, except the number 0 itself.

Example 1:

Input: [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.
Example 2:

Input: [4,3,2,1]
Output: [4,3,2,2]
Explanation: The array represents the integer 4321. */

#include <string.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *plusOne(int *digits, int digitsSize, int *returnSize)
{
	digits[digitsSize - 1] += 1;
	int carry = 0;

	for (int i = digitsSize - 1; i >= 0; i--)
	{
		digits[i] += carry;
		carry = 0;

		if (digits[i] >= 10)
		{
			digits[i] -= 10;
			carry = 1;
		}

		if (carry == 0)
			break;
	}

	if (carry == 1)
	{	
		int * result = malloc((digitsSize + 1) * sizeof(int));
		result[0] = 1;
		for (int i = 1; i < digitsSize + 1; i++)
		{
			result[i] = digits[i-1];
		}
		*returnSize = digitsSize + 1;
		return result;
	}
	*returnSize = digitsSize;
	return digits;
}
