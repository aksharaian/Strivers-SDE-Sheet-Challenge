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
      

      bool isSymmetric(TreeNode* root) {
    if (root == NULL) {
        return true; // An empty tree is symmetric
    }
    
    return isMirror(root->left, root->right);
}

bool isMirror(TreeNode* left, TreeNode* right) {
    if (left == NULL && right == NULL) {
        return true; // Both subtrees are empty, they're symmetric
    }
    
    if (left == NULL || right == NULL) {
        return false; // One subtree is empty, they're not symmetric
    }
    
    if (left->val != right->val) {
        return false; // Values of nodes don't match, not symmetric
    }
    
    // Check the mirror condition recursively
    return isMirror(left->left, right->right) && isMirror(left->right, right->left);
}
};

      
       
//       bool isSymmetric(TreeNode* root) {
//          if(root == NULL){ 
//              return true;
//          }
//          return findsymmetric(root->left,root->right);
//     }
// };