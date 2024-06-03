// first solution TC= O(2N) but second solution TC = O(N)
// this question is available on GFG.

// first solution 

int totalFruits(int N, vector<int> &fruits) {  
    int l=0,r=0,maxlen=0;
    unordered_map<int, int> mpp;
    while(r<N){
        mpp[fruits[r]]++;
        if(mpp.size()>2){
            while(mpp.size()>2){
                mpp[fruits[l]]--;
                if(mpp[fruits[l]]==0) mpp.erase(fruits[l]);
                l++;
            }
        }
        if(mpp.size()<=2){
            maxlen = max(maxlen,r-l+1);
        }
        r++;
    }
    return maxlen;
}

// second solution is better than first 

int totalFruits(int N, vector<int> &fruits)
{
    int l = 0, r = 0, maxlen = 0;
    unordered_map<int, int> mpp;
    while (r < N)
    {
        mpp[fruits[r]]++;
        if (mpp.size() > 2)
        {
            mpp[fruits[l]]--;
            if (mpp[fruits[l]] == 0)
                mpp.erase(fruits[l]);
            l++;
        }
        if (mpp.size() <= 2)
        {
            maxlen = max(maxlen, r - l + 1);
        }
        r++;
    }
    return maxlen;
}