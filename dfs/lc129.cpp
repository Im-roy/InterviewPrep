// URL: https://leetcode.com/problems/sum-root-to-leaf-numbers/
class Solution {
public:
    
    int helper(TreeNode *root, int num) {
        if(root->left == NULL and root->right == NULL) {
            return 10*num + root->val;
        }
        
        int sum = 0;
        if(root->left) {
            sum += helper(root->left, num*10 + root->val);
        }
        if(root->right) {
            sum += helper(root->right, num*10 + root->val);
        }
        return sum;
    }
    
    int sumNumbers(TreeNode* root) {
        return helper(root, 0);
    }
};