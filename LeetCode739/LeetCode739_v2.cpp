#include <vector>
#include <stack>
#include <algorithm>

class Solution
{
public:
    std::vector<int> dailyTemperatures(std::vector<int> &T)
    {
        std::vector<int> result(T.size(), 0);
        std::stack<std::pair<int, int>> container;
        container.push(std::make_pair(T.back(), 0));

        int counter;
        for (int i = T.size() - 2; i >= 0; i--)
        {
            counter = 1;

            while (!container.empty() && T[i] >= container.top())
            {
                counter += container.top().second;
                container.pop();
            }

            if (container.empty())
            {
                container.push(std::make_pair([i], 0));
            }
            else
            {
                container.push(std::make_pair(T[i], counter));
                result[i] = counter;
            }
        }

        return result;
    }
};