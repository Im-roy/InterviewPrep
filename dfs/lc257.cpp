// URL: https://leetcode.com/problems/binary-tree-paths/

class Solution {
public:
    vector<string> result;
    
    string appendNumber(string temp, int num) {
        return temp + to_string(num) + "->";
    }
    
    string popNumber(string temp, int num) {
        string numString = to_string(num);
        for(int i=0; i<numString.size() + 2; i++)
            temp.pop_back();
        return temp;
    }
    
    void getPath(TreeNode *root, string str) {
        if(root->left == NULL and root->right == NULL) {
            str += to_string(root->val);
            result.push_back(str);
            string numString = to_string(root->val);
            for(int i=0; i<numString.size(); i++)
                str.pop_back();
            return;
        }
        
        str = appendNumber(str, root->val);
        if(root->left) 
            getPath(root->left, str);
        if(root->right)
            getPath(root->right, str);
        
        str = popNumber(str, root->val);
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        getPath(root, "");
        return result;
    }
};