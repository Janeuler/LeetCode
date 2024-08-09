//
// Created by janeuler on 2024/8/9.
//

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {
    }

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {
    }

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {
    }
};

class Solution {
public:
    int sumNumbers(TreeNode *root) {
        int sum = 0;
        preOrder(root, sum, 0);
        return sum;
    }

private:
    void preOrder(TreeNode *node, int &sum, int curVal) {
        if (!node) return;
        curVal += 9 * curVal;
        curVal += node->val;
        if (!node->left && !node->right) {
            sum += curVal;
        }
        preOrder(node->left, sum, curVal);
        preOrder(node->right, sum, curVal);
    }
};
