// Minimum Platforms
// https://www.geeksforgeeks.org/problems/minimum-platforms-1587115620/1
// time complexity = O(nlog(n))
// space complexity = O(1)

class Solution
{
public:
    // Function to find the minimum number of platforms required at the
    // railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
        // Your code here
        sort(arr, arr + n);
        sort(dep, dep + n);
        int l = 0;
        int r = 0;
        int c = 0, mc = 0;
        while (l < n)
        {
            if (arr[l] <= dep[r])
            {
                c++;
                l++;
            }
            else
            {
                c--;
                r++;
            }
            mc = max(mc, c);
        }
        return mc;
    }
};