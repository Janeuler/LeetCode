//
// Created by janeuler on 2024/8/17.
//
# include <cstddef>
# include <vector>
# include <algorithm>

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {
    }
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        //     std::vector<ListNode *> v;
        //
        //     ListNode *p = head;
        //     while (p != nullptr) {
        //         ListNode *tar = p;
        //         if (std::find(v.begin(), v.end(), tar) == v.end()) {
        //             v.push_back(tar);
        //         } else {
        //             return true;
        //         }
        //         p = p->next;
        //     }
        //     return false;
        // 快慢指针法
        ListNode *fast = head, *slow = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) return true;
        }
        return false;
    }
};
