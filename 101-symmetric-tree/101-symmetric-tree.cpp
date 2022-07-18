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
    bool helper(TreeNode* left, TreeNode* right){
        
        if(left == NULL && right == NULL) return true;
        if(left == NULL || right == NULL) return false;
        
        return (left -> val == right -> val) && helper(left -> left, right -> right) 
                && helper(left -> right, right -> left);
    }
    // Recursive Approach
    bool isSymmetric(TreeNode* root) {
        
	    return helper(root, root);   
    }
};