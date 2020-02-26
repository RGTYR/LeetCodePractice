class Solution:
    def sumOfNum(self, n: int) -> int:
        sum = 0
        num = 0

        while n != 0:
            num = n % 10
            sum += num * num
            n //= 10
        
        return sum

    def isHappy(self, n: int) -> bool:
        fast = n
        slow = n

        while True:
            slow = self.sumOfNum(slow)
            fast = self.sumOfNum(self.sumOfNum(fast))

            if (slow == 1 or fast == 1):
                return True
            
            if (slow == fast):
                return False