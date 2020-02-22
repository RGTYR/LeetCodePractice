#include <vector>
#include <math.h>

class Solution {
private:
    static std::vector<int> powerOfTwo;

public:
    Solution()
    {
        powerOfTwo.push_back(1);
    }

    bool isPowerOfTwo(int n) {
        int i = powerOfTwo.size() - 1;

        while (powerOfTwo[i] < n)
        {
            i++;
            powerOfTwo.push_back((int)pow(2,i));
        }

        for (i = 0; i < powerOfTwo.size(); i++)
            if (powerOfTwo[i] == n)
                return true;

        return false;
        
    }
};

std::vector<int> Solution::powerOfTwo;
