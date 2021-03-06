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
    // TC: O(N)
    // SC: O(N)
    void inorder(TreeNode *root, vector<int> &in){
        
        if(root == NULL)
            return;
            
        inorder(root->left, in);
        
        in.push_back(root->val);
        
        inorder(root->right, in);
    }
    bool findTarget(TreeNode* root, int k)
    {
        // step 1: calculating inorder traversal array
        vector<int> in;
        inorder(root, in);
        
        // step 2: 2 pointer approach on array
        int i = 0;
        int j = in.size() - 1;
        
        while(i < j){
            
            if(in[i] + in[j] == k)
                return true;
            else if(in[i] + in[j] < k)
                i++;
            else
                j--;
        }
        
        return false;
    }
};