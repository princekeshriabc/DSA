// Delete all occurrences of a key in DLL
// https://www.geeksforgeeks.org/problems/delete-all-occurrences-of-a-given-key-in-a-doubly-linked-list/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=delete-all-occurrences-of-a-given-key-in-a-doubly-linked-list
// time complexity = O(n)
// space complexity = O(1)

void deleteAllOccurOfX(struct Node **head_ref, int x)
{
    Node *temp = *head_ref;

    while (temp != NULL)
    {
        if (temp->data == x)
        {
            Node *nextNode = temp->next;
            Node *prevNode = temp->prev;

            if (prevNode != NULL)
            {
                prevNode->next = nextNode;
            }
            else
            {
                *head_ref = nextNode;
            }

            if (nextNode != NULL)
            {
                nextNode->prev = prevNode;
            }

            delete temp;
            temp = nextNode;
        }
        else
        {
            temp = temp->next;
        }
    }
}