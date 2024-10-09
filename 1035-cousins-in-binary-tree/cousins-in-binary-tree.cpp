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
    bool isCousins(TreeNode* root, int x, int y) {
        int p1 = 0, p2 = 0;   //计算x的父节点的层数 和 y的父节点的层数
        //1.一个函数找x
        TreeNode* parent1 = fun(root, x, p1);
        //2.一个函数找y
        TreeNode* parent2 = fun(root, y, p2);


        //除了要判断父节点是否相等，还得判断x和y是不是在同一层高度
        if (p1 == p2)
        {
            if (parent1->val != parent2->val)
                return true;
        }
        return false;
    }

    TreeNode* fun(TreeNode* root, int val, int& p)
    {
        if (root == nullptr)
            return nullptr;
        
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* parent = nullptr;

        while(q.size())
        {
            int sz = q.size();
            for (int i = 0; i < sz; ++ i)
            {
                TreeNode* t = q.front();
                q.pop();

                if (t->left)
                {
                    q.push(t->left);
                    if (t->left->val == val)
                    {
                        parent = t;
                        break;
                    }
                }
                if (t->right)
                {
                    q.push(t->right);
                    if(t->right->val == val)
                    {
                        parent = t;
                        break;
                    }
                }
            }
            if (parent != nullptr)
                break;
            ++p;
        }

        return parent;
    }

};