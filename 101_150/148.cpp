//
// Created by janeuler on 2024/8/19.
// 链表的归并排序算法
//
struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {
    }

    ListNode(int x) : val(x), next(nullptr) {
    }

    ListNode(int x, ListNode *next) : val(x), next(next) {
    }
};

class Solution {
public:
    ListNode *sortList(ListNode *head) {
        if (!head || !head->next)
            return head;

        ListNode *fast = head, *slow = head;
        ListNode *prev = head;
        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        prev->next = nullptr;

        ListNode *p1 = sortList(head);
        ListNode *p2 = sortList(slow);

        return merge(p1, p2);
    }

private:
    ListNode *merge(ListNode *p1, ListNode *p2) {
        ListNode dummy(0);
        ListNode *head = &dummy;
        ListNode *tail = &dummy;

        while (p1 && p2) {
            if (p1->val < p2->val) {
                tail->next = p1;
                p1 = p1->next;
            } else {
                tail->next = p2;
                p2 = p2->next;
            }
            tail = tail->next;
        }

        tail->next = p1 ? p1 : p2;

        ListNode *ans = dummy.next;
        delete head;
        return ans;
    }
};
