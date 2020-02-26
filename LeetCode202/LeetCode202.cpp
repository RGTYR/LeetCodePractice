#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

class Solution
{
private:
	std::vector<int> numlist;

public:
	bool isHappy(int n)
	{
		int nextNum;
		std::string str = std::to_string(n);

		numlist.push_back(n);

		while (true)
		{
			nextNum = 0;
			for (int i = 0; i < str.length(); i++)
			{
				std::string letter = str.substr(i, 1);
				nextNum += pow(std::stoi(letter), 2);
			}

			for (int i = 0; i < numlist.size(); i++)
				if (numlist[i] == nextNum)
				{
					return false;
				}

			if (nextNum == 1)
				return true;

			numlist.push_back(nextNum);
			str = std::to_string(nextNum);
		}

		return true;
	}
};