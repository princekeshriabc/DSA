// TC = O(26*(N+N)) , sc = O(26)
//better approach

int characterReplacement(string s, int k) { 
    int l=0,r=0,maxlen=0,maxf=0;
    vector<int> mp(26,0);
    while(r<s.length()){
        mp[s[r]-'A']++;
        maxf=max(maxf,mp[s[r]-'A']);
        while((r-l+1)-maxf >k){
            mp[s[l]-'A']--;
            maxf=0;
            for(int i=0;i<26;i++){
                maxf=max(maxf,mp[s[i]]);
            }
            l++;
        }
        if((r-l+1)-maxf <=k){
            maxlen = max(maxlen,r-l+1);
        }
        r++;
    }
    return maxlen;
}

// TC = O(N) , sc = O(26)
// optimal approach

int characterReplacement(string s, int k)
{ 
    int l = 0, r = 0, maxlen = 0, maxf = 0;
    vector<int> mp(26, 0);
    while (r < s.length())
    {
        mp[s[r] - 'A']++;
        maxf = max(maxf, mp[s[r] - 'A']);
        if (((r - l + 1) - maxf) > k)
        {
            mp[s[l] - 'A']--;
            l++;
        }
        if (((r - l + 1) - maxf) <= k)
        {
            maxlen = max(maxlen, r - l + 1);
        }
        r++;
    }
    return maxlen;
}