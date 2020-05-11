class Solution {
	public double myPow(double x, int n) {
		double halfN;
 
		if (n == 0)
		{
			return 1;
		}

		halfN = myPow(x, n / 2);

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
}