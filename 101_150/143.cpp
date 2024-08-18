//
// Created by janeuler on 2024/8/18.
// 思路：快慢指针法：如果链表的长度是2k + 1，则最后slow会位于第k + 1的节点的位置，如果链表的长度是2k，则slow将位于第k + 1的位置
// 然后将后部分的链表实现反转，将第二个链表的每个元素依次插入到第一个链表中间。
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
    void reorderList(ListNode *head) {
        ListNode *fast = head, *slow = head;

        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }

        ListNode *cur = slow->next;
        slow->next = nullptr;
        ListNode *prev = nullptr;
        while (cur) {
            ListNode *next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        ListNode *second = prev;
        ListNode *first = head;

        while (second) {
            ListNode *next1 = first->next;
            ListNode *next2 = second->next;

            first->next = second;
            second->next = next1;
            first = next1;
            second = next2;
        }
    }
};
