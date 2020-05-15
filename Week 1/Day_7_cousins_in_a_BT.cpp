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
    bool isSibling(TreeNode* root,int x,int y){
        if(!root)
            return false;
        bool a=false;
        bool b=false;
        if(root->left && root->right){
            a=(root->left->val==x) && (root->right->val==y);
            b=(root->left->val==y) && (root->right->val==x);
        }
        bool c=isSibling(root->left,x,y);
        bool d=isSibling(root->right,x,y);
        return a||b||c||d;
    }
    int depth(TreeNode* root,int x,int d){
        if (root == NULL) 
            return 0; 
        if (root->val == x)  
          return d; 
        int l = depth(root->left, x,d+1); 
        if (l != 0)  
            return l; 
  
    return depth(root->right,x,d+1); 
    }
    bool isCousins(TreeNode* root, int x, int y) {
       if(depth(root,x,1)==depth(root,y,1) && !isSibling(root,x,y))
           return true;
        else
            return false;
        
    }
};
