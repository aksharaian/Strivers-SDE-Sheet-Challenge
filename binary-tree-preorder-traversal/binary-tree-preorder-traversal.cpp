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

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>ans;
        if(!root){    //if root is null
            return ans;
        }
        stack<TreeNode*>op;
        op.push(root);
        while(!op.empty()){
            TreeNode* top=op.top();
            op.pop();
            ans.push_back(top->val);
            if(top->right) op.push(top->right);
            if(top->left) op.push(top->left);
        }
        return ans;
    }
};