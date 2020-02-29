/* The gray code is a binary numeral system where two successive values differ in only one bit.

Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code. A gray code sequence must begin with 0.

Example 1:

Input: 2
Output: [0,1,3,2]
Explanation:
00 - 0
01 - 1
11 - 3
10 - 2

For a given n, a gray code sequence may not be uniquely defined.
For example, [0,2,3,1] is also a valid gray code sequence.

00 - 0
10 - 2
11 - 3
01 - 1
Example 2:

Input: 0
Output: [0]
Explanation: We define the gray code sequence to begin with 0.
             A gray code sequence of n has size = 2n, which for n = 0 the size is 20 = 1.
             Therefore, for n = 0 the gray code sequence is [0]. */

#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *grayCode(int n, int *returnSize)
{
	*returnSize = 1 << n;
	int * result = (int *)malloc(*returnSize * sizeof(int));

	// When n is less than 2
	result[0] = 0;
	if (*returnSize == 1)
		return result;

	result[1] = 1;
	if (*returnSize == 2)
		return result;

	// The start point
	// Used to traverse the array
	int currentSize = 2;
	int halfSize;

	// When n is greater than 1
	for (int i = 2; i <= n; i++)
	{
		int halfSize = currentSize;
		currentSize *= 2;

		int offset = 1 << (i - 1);
		for (int j = 0; j < halfSize; j++)
			result[halfSize + j] =
				result[halfSize - 1 - j] + offset;
	}

	return result;
}
