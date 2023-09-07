// URL: https://leetcode.com/problems/path-sum/

class Solution {
public:
    
    bool solve(TreeNode* root, int targetSum) {
        if(root->left == NULL and root->right == NULL)
            return root->val == targetSum;
        
        bool ans = false;
        if(root->left) 
            ans |= solve(root->left, targetSum - root->val);
        if(root->right) 
            ans |= solve(root->right, targetSum - root->val);
        
        return ans;
    }
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root)
            return false;
        
        return solve(root, targetSum);
    }
};