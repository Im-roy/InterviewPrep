//URL: https://leetcode.com/problems/diameter-of-binary-tree/

class Solution {
public:
    
    map<TreeNode*, int> mp;
    
    int getHeight(TreeNode *root) {
        if(root->left == NULL and root->right == NULL)
            return mp[root] = 0;
        
        int lheight = 0, rheight = 0;
        if(root->left)
            lheight = getHeight(root->left);
        if(root->right)
            rheight = getHeight(root->right);
        
        return mp[root] = max(lheight, rheight) + 1;
    }
    
    int getDiameter(TreeNode *root) {
        if(root->left == NULL and root->right == NULL)
            return 0;
        
        int lmaxD = 0, rmaxD = 0;
        if(root->left)
            lmaxD = getDiameter(root->left);
        if(root->right)
            rmaxD = getDiameter(root->right);
        
        int reqValue = (root->left && root->right) ? (2 + mp[root->left] + mp[root->right]): (1 + mp[root->left] + mp[root->right]);
        return max({lmaxD, rmaxD, reqValue});
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        getHeight(root);
        
        return getDiameter(root);
    }
};