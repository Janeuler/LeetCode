/*最sb的一集，连中序遍历都能忘掉。。。然后也是看答案写出来的，啊，什么时候能不看答案自己想出来实现的代码啊！！！！*/

#include <vector>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class BSTIterator
{
private:
    std::vector<int> v;
    int index = 0;
    void inOrderTraversal(TreeNode *node)
    {
        if (node == nullptr)
        {
            return;
        }
        inOrderTraversal(node->left);
        v.push_back(node->val);
        inOrderTraversal(node->right);
    }

public:
    BSTIterator(TreeNode *root)
    {
        inOrderTraversal(root);
    }

    int next()
    {
        return v[index++];
    }

    bool hasNext()
    {
        return index < v.size();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */