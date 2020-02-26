class Solution:
    def isUgly(self, num: int) -> bool:
        if num <= 0:
            return False

        num = self.devideFactor(num, 2)
        num = self.devideFactor(num, 3)
        num = self.devideFactor(num, 5)

        if num == 1:
            return True
        else:
            return False
        
    def devideFactor(self, num: int, factor: int) -> int:
        while num % factor == 0:
            num /= factor
        
        return num