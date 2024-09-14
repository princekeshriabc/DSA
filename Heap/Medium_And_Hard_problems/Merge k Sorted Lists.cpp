// Merge k Sorted Lists
// https://leetcode.com/problems/merge-k-sorted-lists/solutions/5775119/simple-solution-customization-of-minheap-beats-100/

// Time complexity : O(nk(log(k)))
// Space complexity : O(k)

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    class compare
    {
    public:
        bool operator()(ListNode *a, ListNode *b)
        {
            return a->val > b->val;
        }
    };
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        priority_queue<ListNode *, vector<ListNode *>, compare> p;
        for (auto l : lists)
            if (l)
                p.push(l);
        ListNode *root = new ListNode(-1);
        ListNode *tail = root;
        ListNode *temp;
        while (!p.empty())
        {
            temp = p.top();
            p.pop();
            tail->next = temp;
            tail = tail->next;
            if (temp->next)
            {
                p.push(temp->next);
            }
        }
        return root->next;
    }
};