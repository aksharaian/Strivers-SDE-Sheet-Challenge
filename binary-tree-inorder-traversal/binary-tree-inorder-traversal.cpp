class Solution {
public:
    vector<int> ans;
    
    vector<int> inorderTraversal(TreeNode* root) {
        TreeNode* cur = root;
        TreeNode* predecessor;
        
        while(cur) {
            if (cur->left == NULL) {
                visit(cur);
                cur = cur->right;
            } else {
                predecessor = find_predecessor(cur);
                
                // build threaded binary tree
                if (predecessor->right == NULL) {
                    predecessor->right = cur;
                    cur = cur->left;
                } else {
                    // destroy threaded binary tree 
                    //      because it has been visited.
                    
                    // the left sub-tree is visited.
                    predecessor->right = NULL;
                    visit(cur);
                    
                    // visit right subtree.
                    cur = cur->right;
                }
            }
        }
        
        return ans;
    }
    
    
    inline void visit(TreeNode* p) {
        ans.push_back(p->val);
    }
    
    
    /*
     *  search predeceesor of root.
     *      i.e. search root's left subtree.
     */
    inline TreeNode* find_predecessor(TreeNode* root) {
        TreeNode* p = root->left;
        
        // The tree might be threaded binary tree.
        //     Thus the 2nd condition avoids searching successor of root.
        //          i.e. avoids searching root's right subtree.
        while(p->right && p->right != root) {
            p = p->right;
        }
        
        return p;
    }
};