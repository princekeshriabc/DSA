// Replace elements by its rank in the array
// https://www.geeksforgeeks.org/problems/replace-elements-by-its-rank-in-the-array/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=replace-elements-by-its-rank-in-the-array

vector<int> replaceWithRank(vector<int> &arr, int N)
{

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> p;

    for (int i = 0; i < N; i++)
    {
        p.push({arr[i], i});
    }
    int j = 1;
    vector<int> ans(N);
    while (!p.empty())
    {
        auto it = p.top();
        p.pop();
        int num = it.first;
        int pos = it.second;
        ans[pos] = j;
        if (p.top().first == num)
            continue;
        j++;
    }
    return ans;
}