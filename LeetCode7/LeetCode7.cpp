#include <iostream>
#include <string>

class Solution {
public:
    int reverse(int x) {
        long long result = 0;

        if (x > INT32_MAX || x < INT32_MIN)
            return result;
        
        if (x >= 0)
        {
            std::string temp = std::to_string(x);
            std::reverse(temp.begin(), temp.end());
            result = std::stoll(temp);
        }
        else
        {
            std::string temp = std::to_string(x);
            temp.erase(0, 1);
            std::reverse(temp.begin(), temp.end());
            temp.insert(0, "-");
            result = std::stoll(temp);
        }
        
        if (result > INT32_MAX || result < INT32_MIN)
            return 0;
        
        return result;
    }
};

int main()
{
    Solution sol;
    
}


