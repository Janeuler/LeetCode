

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *removeElements(ListNode *head, int val)
    {
        ListNode *prev, *cur = head;
        ListNode *dummy = new ListNode();
        prev = dummy;
        dummy->next = head;
        while (cur)
        {

            if (cur->val == val)
            {
                prev->next = cur->next;
                cur = cur->next;
            }
            else
            {
                cur = cur->next;
                prev = prev->next;
            }
        }

        head = dummy->next;
        delete dummy;
        return head;
    }
};