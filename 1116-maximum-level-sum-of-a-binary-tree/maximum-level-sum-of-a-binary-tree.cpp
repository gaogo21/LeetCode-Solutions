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

 //比如有3，5，6都满足，只返回3
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        if (root == nullptr)
            return 0;
        
        queue<TreeNode*> q;
        q.push(root);

        //j表示层数
        int m = INT_MIN, j = 1, res = 0;
        while(q.size())
        {
            int sz = q.size();
            int tmp = 0;
            for (int i = 0; i < sz; ++ i)
            {
                TreeNode* t = q.front();
                q.pop();

                tmp += t->val;

                if (t->left)
                    q.push(t->left);
                if (t->right)
                    q.push(t->right);
            }
            //只有当大于的时候才记录值

            if (m < tmp)
            {
                m = tmp;
                res = j;
            }
            //这里的j必须在res = j之后，不然j的值就先变为下一层了，导致res比真实答案大1
            ++j;
        }
        return res;
    }
};