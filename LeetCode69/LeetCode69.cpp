class Solution {
public:
	int mySqrt(int x)
	{
		unsigned long long range = x;
		range += 2;

		for (unsigned long long i = 0; i < range; i++)
		{
			unsigned long long num = i;
			unsigned long long square = num * num;

			if (x < square)
				return i - 1;
		}

		return NULL;
	}
};