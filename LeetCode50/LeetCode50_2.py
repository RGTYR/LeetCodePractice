class Solution:
	def myPow( self, x: float, n: int ) -> float:
		if n == 0:
			return 1

		halfN = self.myPow(x, n // 2 if n > 0 else int(n / 2))

		if n % 2 == 0:
			return halfN * halfN

		if n > 0:
			return halfN * halfN * x

		if n < 0:
			return ( halfN * halfN ) / x