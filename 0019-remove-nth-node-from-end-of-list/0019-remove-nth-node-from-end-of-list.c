/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *removeNthFromEnd(struct ListNode *head, int n)
{
    struct ListNode *x = head;
    int count = 0;

    while (x != NULL)
    {
        count++;
        x = x->next;
    }

    if (count == n)
    {
        struct ListNode *newHead = head->next;

        return newHead;
    }

    int i = 0;
    x = head;

    while (x != NULL)
    {
        if (i == count - n - 1)
        {
            struct ListNode *target = x->next;
            if (target != NULL)
            {
                x->next = target->next; // Skip the target node
            }
            else
            {
                x->next = NULL; // Nothing after x
            }
            break;
        }
        i++;
        x = x->next;
    }

    return head;
}