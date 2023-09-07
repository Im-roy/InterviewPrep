// URL: https://leetcode.com/problems/path-sum-ii/
class Solution {
public:
    vector<vector<int>> result;
    
    void helper(TreeNode *root, int targetSum, vector<int> temp) {
        if(root->left == NULL and root->right == NULL) {
            temp.push_back(root->val);
            if(targetSum == root->val) {
                result.push_back(temp);
            }
            temp.pop_back();
            return;
        }
        
        temp.push_back(root->val);
        if(root->left) {
            helper(root->left, targetSum - root->val, temp);
        }
        if(root->right) {
            helper(root->right, targetSum - root->val, temp);
        }
        temp.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(root == NULL)
            return {};
        helper(root, targetSum, {});
        return result;
    }
};