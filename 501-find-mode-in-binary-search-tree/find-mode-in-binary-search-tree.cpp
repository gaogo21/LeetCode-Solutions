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
    vector<int> findMode(TreeNode* root) {
        vector<int> nums;
        vector<int> ret;
        unordered_map<int, int> countMap;
        Inorder(nums, root);
        
        // 统计每个数字的出现次数
        for (int num : nums) {
            countMap[num]++;
        }
        
        int maxCount = 0;
        // 找到最大出现次数
        for (const auto& pair : countMap) {
            if (pair.second > maxCount) {
                maxCount = pair.second;
            }
        }

        // 找到所有众数
        for (const auto& pair : countMap) {
            if (pair.second == maxCount) {
                ret.push_back(pair.first);
            }
        }

        return ret;
    }

    void Inorder(vector<int>& res, TreeNode* root) {
        if (root == nullptr)
            return;
        
        Inorder(res, root->left);
        res.push_back(root->val);
        Inorder(res, root->right);
    }
};
