// TC = O(n) SC = O(1)

int numberOfSubstrings(string s)
{
    vector<int> mp(3, -1);
    int result = 0;
    for (int i = 0; i < s.size(); i++)
    {
        mp[s[i] - 'a'] = i;

        if (mp[0] != -1 && mp[1] != -1 && mp[2] != -1)
        {
            result += (1 + min(mp[0], min(mp[1], mp[2])));
        }
    }
    return result;
}