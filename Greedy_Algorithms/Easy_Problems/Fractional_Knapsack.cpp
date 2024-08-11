// Fractional Knapsack
// https://www.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1
// // time complexity = O(nlog(n))
// space complexity = O(1)

class Solution
{
public:
    // Function to get the maximum total value in the knapsack.
    bool static comp(Item a, Item b)
    {
        if ((a.value / (double)a.weight) > (b.value / (double)b.weight))
            return true;
        return false;
    }
    double fractionalKnapsack(int w, Item arr[], int n)
    {
        // Your code here
        sort(arr, arr + n, comp);
        double sum = 0.0;
        for (int i = 0; i < n; i++)
        {
            if (w >= arr[i].weight)
            {
                sum += arr[i].value;
                w -= arr[i].weight;
            }
            else
            {
                sum += (arr[i].value / (double)arr[i].weight) * (double)w;
                break;
            }
        }
        return sum;
    }
};