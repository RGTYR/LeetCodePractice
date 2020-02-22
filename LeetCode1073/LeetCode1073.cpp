#include <vector>

class Solution {
public:
    vector<int> addNegabinary(std::vector<int>& arr1, std::vector<int>& arr2) {
        std::vector<int> result;
        
        int i = arr1.size() - 1;
        int j = arr2.size() - 1;
        int length = i > j ? i: j;
        int carry = 0;

        while (length >= 0 || carry != 0)
        {
            int term1 = i >= 0 ? arr1[i] : 0;
            int term2 = j >= 0 ? arr2[j] : 0;

            int sum = term1 + term2 + carry;
            carry = 0;
            
            if (sum > 1)
            {
                sum -= 2;
                carry = -1;
            }
            else if (sum < 0)
            {
                sum += 2;
                carry = 1;
            }

            result.push_back(sum);
            i--;
            j--;
            length--;
        }

        std::reverse(result.begin(), result.end());
        
        while (result[0] == 0 && result.size() > 1)
        {
            result.erase(result.begin());
        }

        return result;
    }
};