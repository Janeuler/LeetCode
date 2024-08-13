#include <vector>
#include <queue>
#include <stdio.h>
#include <unordered_map>

class Node {
public:
    int val;
    std::vector<Node *> neighbors;

    Node() {
        val = 0;
        neighbors = std::vector<Node *>();
    }

    Node(int _val) {
        val = _val;
        neighbors = std::vector<Node *>();
    }

    Node(int _val, std::vector<Node *> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    Node *cloneGraph(Node *node) {
        if (node == nullptr) return nullptr;

        std::queue<Node *> q;
        std::unordered_map<Node *, Node *> m;

        q.push(node);
        m[node] = new Node(node->val);

        while (!q.empty()) {
            Node *currentNode = q.front();
            q.pop();
            for (auto &x: currentNode->neighbors) {
                if (m.find(x) == m.end()) {
                    // create this elment, then connect relationship with the neighboring Node.
                    m[x] = new Node(x->val);
                    q.push(x);
                }
                m[currentNode]->neighbors.push_back(m[x]);
            }
        }

        return m[node];
    }
};
