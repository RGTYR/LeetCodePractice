#include <vector>
#include <algorithm>

class Solution
{
public:
    std::vector<int> dailyTemperatures(std::vector<int> &T)
    {
        std::vector<int> result(T.size(), 0);
        std::vector<std::pair<int, int>> container;

        for (int i = 0; i < T.size(); i++)
        {
            while (!container.empty())
            {
                if (T[i] > container.back().second)
                {
                    result[container.back().first] = i - container.back.first();
                    container.erase(container.end() - 1);
                }
                else
                {
                    break;
                }
            }
            container.push_back(std::make_pair(i, T[i]));
        }

        return result;
    }
};