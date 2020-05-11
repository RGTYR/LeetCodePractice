#include <string>

class Solution
{
public:
	string countAndSay(int n)
	{
		std::string result = "";
		std::string lastResult = "";

		if (n == 1)
			return "1";

		lastResult = countAndSay(n - 1);

		int count = 1;
		for (int i = 0; i < lastResult.length(); i++)
		{
			if (i == lastResult.length())
			{
				result = result + std::to_string(count) + lastResult[i];
				break;
			}
				
			if (lastResult[i] == lastResult[i + 1])
			{
				count++;
				continue;
			}

			result = result + std::to_string(count) + lastResult[i];
			count = 1;
		}
        
        return result;
	}
};