import java.util.*;

class Solution {
    public int[] dailyTemperatures(int[] T) {

        Stack<List<Integer>> container = new Stack<List<Integer>>(); 
        int [] result = new int[T.length];
        container.push(Arrays.asList(0, T[T.length-1]));
        int counter;

        for (int i = T.length - 2; i >= 0; i--)
        {
            counter = 1;

            while (!container.empty() && T[i] >= container.peek().get(1))
            {
                counter += container.peek().get(0);
                container.pop();
            }

            if (container.empty())
            {
                container.push(Arrays.asList(0, T[i]));
            }
            else
            {
                container.push(Arrays.asList(counter, T[i]));
                result[i] = counter;
            }
        }

        return result;
    }
}