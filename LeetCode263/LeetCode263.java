class Solution {
    private int devideFactor(int num, int factor)
    {
        while (num % factor == 0)
        {
            num /= factor;
        }
    
        return num;
    }
    
    public boolean isUgly(int num) 
    {
        if (num <= 0)
            return false;

        num = devideFactor(num, 2);
        num = devideFactor(num, 3);
        num = devideFactor(num, 5);

        if (num == 1)
            return true;
        else
            return false;
    }
}