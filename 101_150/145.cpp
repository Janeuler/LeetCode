//
// Created by janeuler on 2024/8/18.
// 后序遍历
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
    std::vector<int> postorderTraversal(TreeNode *root) {

    }
};
