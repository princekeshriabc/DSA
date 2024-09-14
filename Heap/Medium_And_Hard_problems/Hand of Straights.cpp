// Hand of Straights
// https://leetcode.com/problems/hand-of-straights/solutions/5784230/simple-solution-in-c-map/

// Time complexity:O(n(log(n))+n∗groupSize)
// Space complexity : O(n)

class Solution
{
public:
    bool isNStraightHand(vector<int> &hand, int groupSize)
    {
        int n = hand.size();
        if (n % groupSize != 0)
            return false;
        map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            mp[hand[i]]++;
        }
        while (mp.size())
        {
            int currcard = mp.begin()->first;
            for (int i = 0; i < groupSize; i++)
            {
                if (mp[currcard + i] == 0)
                    return false;
                mp[currcard + i]--;
                if (mp[currcard + i] < 1)
                {
                    mp.erase(currcard + i);
                }
            }
        }
        return true;
    }
};