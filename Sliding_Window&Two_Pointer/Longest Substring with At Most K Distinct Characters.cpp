//TC = O(n) SC = O(1)

int LongestSubstringwithAtMostK_DistinctCharacters(string s, int k)
{
    int l = 0, r = 0, mxlen = 0;
    unordered_map<char, int> mp;
    while(r<s.size()){
        mp[s[r]]++;
        if(mp.size()>k){
            mp[s[l]]--;
            if(mp[s[l]]==0){
                mp.erase(s[l]);
            }
            l++;
        }
        if(mp.size()<=k){
            maxlen = max(maxlen, r - l + 1);
        }
    }
    return maxlen;
}