// Candy
// https://leetcode.com/problems/candy/solutions/5624797/simple-solution-in-c-striver-approach/
// Time complexity =O(n)
// Space complexity =O(1)

class Solution
{
public:
    int candy(vector<int> &ratings)
    {
        int n = ratings.size();
        int i = 1;
        int sum = 1, peak, down;
        while (i < n)
        {
            if (ratings[i] == ratings[i - 1])
            {
                sum += 1;
                i++;
                continue;
            }
            peak = 1;
            while (i < n && ratings[i] > ratings[i - 1])
            {
                peak++;
                sum += peak;
                i++;
            }
            down = 1;
            while (i < n && ratings[i] < ratings[i - 1])
            {
                sum += down;
                i++;
                down++;
            }
            if (down > peak)
                sum += down - peak;
        }
        return sum;
    }
};