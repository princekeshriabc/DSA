// Maximum Sum Combination
// https://www.interviewbit.com/problems/maximum-sum-combinations/

vector<int> Solution::solve(vector<int> &A, vector<int> &B, int C)
{
    vector<int> ans;
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    priority_queue<pair<int, pair<int, int>>> p;
    for (int i = 0; i < A.size(); i++)
    {
        p.push({A[i] + B[B.size() - 1], {i, B.size() - 1}});
    }
    while (C--)
    {
        auto it = p.top();
        int sum = it.first;
        int x = it.second.first;
        int y = it.second.second;
        ans.push_back(sum);
        p.pop();
        p.push({A[x] + B[y - 1], {x, y - 1}});
    }
    return ans;
}
