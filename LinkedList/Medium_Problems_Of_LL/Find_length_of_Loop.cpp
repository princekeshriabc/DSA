// find the length of the loop when loop is present
// time complexity = O(n)
// space complexity = O(1)
// https://www.geeksforgeeks.org/problems/find-length-of-loop/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=find-length-of-loop

int countNodesinLoop(struct Node *head)
{
    // Code here
    int count = 0;
    Node *slow = head;
    Node *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            break;
    }
    while (fast != NULL && fast->next != NULL)
    {
        count++;
        slow = slow->next;
        if (slow == fast)
            return count;
    }
    return 0;
}