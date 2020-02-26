class Solution {
    public int nthUglyNumber(int n) {
        int [] sequence = new int[1690];
		sequence[0] = 1;

		// The pointer point to the position of sequence
		int pointerTwo = 0;
		int pointerThree = 0;
		int pointerFive = 0;

		// Next Number
		// The result of multiplication
		// The number will be placed in a sorted position
		int nextNumTwo = 2;
		int nextNumThree = 3;
		int nextNumFive = 5;
		int nextNum;

		for (int i = 1; i < n; i++)
		{
			// Get the minimum number of three next numbers
			nextNum = Math.min(nextNumTwo, Math.min(nextNumThree, nextNumFive));
			sequence[i] = nextNum;

			// Update the next number when it is placed in the sorted sequence
			if (nextNum == nextNumTwo)
				nextNumTwo = sequence[++pointerTwo] * 2;

			if (nextNum == nextNumThree)
				nextNumThree = sequence[++pointerThree] * 3;

			if (nextNum == nextNumFive)
				nextNumFive = sequence[++pointerFive] * 5;
		}

		return sequence[n - 1];
    }
}