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
    bool isValidBST(TreeNode* root) {
        vector<int> res;
        Inorder(res, root);

        //判断中序遍历的结果是否有序
        for (int i = 0; i < res.size() - 1; ++ i)
        {
            if (res[i + 1] <= res[i])
                return false;
        }
        return true;
    }

    //中序遍历
    void Inorder(vector<int>& res, TreeNode* root)
    {
        if (root == nullptr)
            return;
        
        Inorder(res, root->left);
        res.push_back(root->val);
        Inorder(res, root->right);
    }
    //直接中序遍历，如果不是正确的，就返回false
};