//
// Created by janeuler on 2024/8/19.
// 链表的插入排序算法
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
    ListNode *insertionSortList(ListNode *head) {
        if (head == nullptr || head->next == nullptr) return head;

        ListNode *pre = head, *cur = head->next;
        while (cur) {
            if (cur->val < pre->val) {
                pre->next = cur->next;
                ListNode *node = cur;
                cur = cur->next;
                ListNode *p1 = head, *p2 = nullptr;
                while (p1 && node->val > p1->val) {
                    p2 = p1;
                    p1 = p1->next;
                }
                if (p2 == nullptr) {
                    node->next = head;
                    head = node;
                } else {
                    p2->next = node;
                    node->next = p1;
                }
            } else {
                cur = cur->next;
                pre = pre->next;
            }
        }
        return head;
    }
};
