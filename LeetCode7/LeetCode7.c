#include <string.h>
#include <stdlib.h>

int reverse(int x)
{
    bool negative = false;
    long result = 0;
    
    if (x > INT_MAX || x < INT_MIN)
        return result;

    if (x < 0)
    {
        negative = true;
        x = -x;
    }

    char* temp = lltoa(x);
    temp = strrev(temp);
    result = atoll(temp);
    
    if (negative)
        result = -result;

    if (result > INT_MAX || result < INT_MIN)
        return 0;

    return result;
}
