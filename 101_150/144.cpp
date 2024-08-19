//
// Created by janeuler on 2024/8/18.
// 前序遍历
//

# include <vector>
# include <stack>

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
    std::vector<int> preorderTraversal(TreeNode *root) {
        std::stack<TreeNode *> s;
        std::vector<int> res;
        if (root == nullptr) return res;
        s.push(root);
        while (!s.empty()) {
            TreeNode *cur = s.top();
            s.pop();
            res.push_back(cur->val);
            if (cur->right) {
                s.push(cur->right);
            }
            if (cur->left) {
                s.push(cur->left);
            }
        }
        return res;
    }
};
