/* Given two binary strings, return their sum (also a binary string).

The input strings are both non-empty and contains only characters 1 or 0.

Example 1:

Input: a = "11", b = "1"
Output: "100"
Example 2:

Input: a = "1010", b = "1011"
Output: "10101" */

#include <string>

class Solution
{
public:
	std::string addBinary(std::string a, std::string b)
	{
		int i = a.size() - 1;
		int j = b.size() - 1;
		int length = i > j ? i : j;
		int carry = 0;

		std::string result;
		result.resize(length + 1);

		int term1, term2, sum;
		while (length >= 0)
		{
			term1 = i >=0 && a[i] == '1' ? 1 : 0;
			term2 = j >=0 && b[j] == '1' ? 1 : 0;
			sum = term1 + term2 + carry;

			carry = 0;

			if (sum > 1)
			{
				sum -= 2;
				carry = 1;
			}

			result[length] = sum == 1 ? '1' : '0';
			
			i--;
			j--;
			length--;
		}

		if (carry == 1)
			result.insert(0, "1");

		if (result.empty())
			result = "0";

		return result;
	}
};