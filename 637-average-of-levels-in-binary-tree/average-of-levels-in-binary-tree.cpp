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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        if (root == nullptr)
            return res;
        
        queue<TreeNode*> q;
        q.push(root);

        while(q.size())
        {
            //vector<double> tmp;
            double tmp = 0.0;
            int sz = q.size();
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

            tmp /= sz;
            res.push_back(tmp);
        }

        return res;
    }
};