double myPow(double x, int n)
{
	if (n == 0)
	{
		return 1;
	}

	double halfN = myPow(x, n / 2);

	if (n % 2 == 0)
	{
		return halfN * halfN;
	}
	else
	{
		if (n > 0)
		{
			return halfN * halfN * x;
		}
		else
		{
			return (halfN * halfN) / x;
		}
	}
}