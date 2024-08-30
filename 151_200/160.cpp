#include <unordered_set>
#include <cstddef>

struct ListNode
{
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL)
    {
    }
};

// class Solution
// {
// public:
//     ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
//     {
//         std::unordered_set<ListNode *> set;
//         ListNode *pA = headA;
//         while (pA != nullptr)
//         {
//             set.insert(pA);
//             pA = pA->next;
//         }

//         ListNode *pB = headB;
//         while (pB != nullptr)
//         {
//             if (set.find(pB) != set.end())
//             {
//                 return pB;
//             }
//             pB = pB->next;
//         }
//         return NULL;
//     }
// };

// 如果同时pa 和 pb为nullptr，怎么说明不相交

class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode *p1, *p2;
        p1 = headA;
        p2 = headB;

        if (!p1 || !p2)
            return NULL;

        while (p1 != p2)
        {
            p1 = p1 ? p1->next : headB;
            p2 = p2 ? p2->next : headA;
        }
        return p1;
    }
};
