// TC = O(2k) SC = O(1)

int maxScore(vector<int> &cardPoints, int k)
{
    int lsum = 0, maxsum = 0;
    for (int i = 0; i < k; i++)
    {
        lsum += cardPoints[i];
    }
    maxsum = lsum;
    int j = cardPoints.size() - 1;
    for (int i = k - 1; i >= 0; i--)
    {
        lsum = lsum - cardPoints[i];
        lsum = lsum + cardPoints[j];
        j--;
        maxsum = max(maxsum, lsum);
    }
    return maxsum;
}