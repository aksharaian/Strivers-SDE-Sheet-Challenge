
class Solution {
public:
//recursive call for inorder traversal
    void inorder(TreeNode* root, vector<int>&v){
//check if root is null then retrun
         if(!root){
         return;
         }
//trvaverse for the left node
           inorder(root->left,v);
//push the data of the current nodes
           v.push_back(root->val);
//traverse for right node
           inorder(root->right,v);
   }
//driver code
 vector<int> inorderTraversal(TreeNode* root) {
        vector<int>v;
//recursion call
        inorder(root,v);
        return v;
        }
};