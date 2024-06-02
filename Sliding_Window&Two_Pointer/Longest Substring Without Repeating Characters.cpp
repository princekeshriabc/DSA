int lengthOfLongestSubstring(string s)
{
    int l = 0, r = 0, maxlen = 0, len = 0;
    int n = s.size();
    vector<int> hash(256, -1);
    while (r < n)
    {
        if (hash[s[r]] != -1)
        {
            l = max(hash[s[r]] + 1, l);
        }
        hash[s[r]] = r; // char-> index
        len = r - l + 1;
        maxlen = max(maxlen, len);
        r++;
    }
    return maxlen;
}