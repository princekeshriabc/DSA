// Valid Parenthesis String
// https://leetcode.com/problems/valid-parenthesis-string/solutions/5616367/simple-solution-in-c-striver/
// time complexity = O(n)
// space complexity = O(1)

class Solution
{
public:
    bool checkValidString(string s)
    {
        int n = s.size();
        int mini = 0, maxi = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(')
            {
                mini++;
                maxi++;
            }
            else if (s[i] == ')')
            {
                mini--;
                maxi--;
            }
            else
            {
                mini--;
                maxi++;
            }
            if (mini < 0)
                mini = 0;
            if (maxi < 0)
                return false;
        }
        return mini == 0;
    }
};