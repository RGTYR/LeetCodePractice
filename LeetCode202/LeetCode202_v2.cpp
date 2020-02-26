class Solution
{
private:
    int sumOfNum(int n)
    {
        int num = 0;
        int sum = 0;

        while (n != 0)
        {
            num = n % 10;
            sum += num * num;
            n /= 10;
        }

        return sum;
    }

public:
    bool isHappy(int n)
    {
        int slow = n;
        int fast = n;

        do
        {
            slow = sumOfNum(slow);
            fast = sumOfNum(sumOfNum(fast));

            if (slow == 1 || fast == 1)
                return true;
        } while (slow != fast);

        return false;
    }
};