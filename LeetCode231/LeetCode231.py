import math

class Solution:
    def isPowerOfTwo(self, n: int) -> bool:
        if n <= 0:
            return False
        
        root = math.log2(n)

        if root - int(root) == 0:
            return True
        else:
            return False