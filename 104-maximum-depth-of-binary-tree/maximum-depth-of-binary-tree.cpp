/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode* root) {
        return dfs(root);
    }

    //一颗二叉树的最大深度 -> 左子树和右子树中最大的 + 1
    int dfs(TreeNode* root)
    {
        if (root == nullptr)
            return 0;
        
        int left = dfs(root->left);
        int right = dfs(root->right);

        return left > right ? left + 1 : right + 1;
    }
};