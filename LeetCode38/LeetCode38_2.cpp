#include <string>
#include <sstream>

class Solution
{
public:
	string countAndSay(int n)
	{
		if (n == 1)
			return "1";

		std::string lastResult;
		lastResult = countAndSay(n - 1);
		std::stringstream result;

		int count = 0;
		int len = lastResult.length();

		for (int i = 0; i < len; i++)
		{
			if ((i < len - 1) && (lastResult[i] == lastResult[i + 1]))
			{
				count++;
			}
			else
			{
				result << count + 1;
				result << lastResult[i];
				count = 0;
			}
		}

		return result.str();
	}
};