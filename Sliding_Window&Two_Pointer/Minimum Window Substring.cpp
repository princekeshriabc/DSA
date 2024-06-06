// TC = O(n) SC =O(n)

string minWindow(string s, string t)
{
    if (s.empty() || t.empty() || s.length() < t.length())
    {
        return "";
    }
    int sindex = -1, minlen = INT_MAX, c = 0, l = 0, r = 0;
    unordered_map<char, int> mp;
    for (int i = 0; i < t.size(); i++)
    {
        mp[t[i]]++;
    }
    while (r < s.size())
    {
        if (mp[s[r]] > 0)
            c++;
        mp[s[r]]--;

        while (c == t.size())
        {
            if (r - l + 1 < minlen)
            {
                minlen = r - l + 1;
                sindex = l;
            }
            mp[s[l]]++;
            if (mp[s[l]] > 0)
            {
                c--;
            }
            l++;
        }
        r++;
    }
    return sindex == -1 ? "" : s.substr(sindex, minlen);
}