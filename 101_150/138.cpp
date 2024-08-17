//
// Created by janeuler on 2024/8/16.
//

# include <cstddef>
# include <unordered_map>

class Node {
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};


class Solution {
public:
    Node *copyRandomList(Node *head) {
        if (head == nullptr) return nullptr;
        std::unordered_map<Node *, Node *> nodeMap;
        Node *curNode = head;
        Node *preNode = head;
        nodeMap[curNode] = new Node(curNode->val);
        curNode = curNode->next;

        while (curNode != nullptr) {
            nodeMap[curNode] = new Node(curNode->val);
            nodeMap[preNode]->next = nodeMap[curNode];
            preNode = curNode;
            curNode = curNode->next;
        }
        nodeMap[preNode]->next = nullptr;

        curNode = head;
        while (curNode) {
            if (curNode->random != nullptr)
                nodeMap[curNode]->random = nodeMap[curNode->random];
            curNode = curNode->next;
        }

        return nodeMap[head];
    }
};
