#include <cmath>

class Solution {
public:
    bool isPowerOfTwo(int n) {
        long double root = std::log2l(n);

        if (root - (int)root == 0)
            return true;
        else
            return false;
    }
};