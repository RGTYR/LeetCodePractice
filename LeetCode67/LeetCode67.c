/* Given two binary strings, return their sum (also a binary string).

The input strings are both non-empty and contains only characters 1 or 0.

Example 1:

Input: a = "11", b = "1"
Output: "100"
Example 2:

Input: a = "1010", b = "1011"
Output: "10101" */

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

char *addBinary(char *a, char *b)
{
	size_t i = strlen(a) - 1;
	size_t j = strlen(b) - 1;
	size_t length = i > j ? i : j;
	int carry = 0;

	char *result;
	result = (char*) calloc(length + 1, 1);

	printf("%d, %d\n", i, j);

	int term1, term2, sum;
	while (length >= 0)
	{
		term1 = i >= 0 && a[i] == '1' ? 1 : 0;
		term2 = j >= 0 && b[j] == '1' ? 1 : 0;
		sum = term1 + term2 + carry;

		carry = 0;

		if (sum > 1)
		{
			sum -= 2;
			carry = 1;
		}

		result[length] = sum == 1 ? '1' : '0';
		printf("%d: %c\n", length, result[length]);

		i--;
		j--;
		length--;
	}		

	if (carry == 1)
	{
		char *result_ = malloc((strlen(result) + 1) * sizeof(char));
		result_[0] = '1';
		printf("Test\n");
		strcpy(result_ + 1, result);
		free(result);
		return result_;
	}

	return result;
}
