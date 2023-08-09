


class Solution {
public:

TreeNode* maketree(int &index,int inorderstart,int inorderend,vector<int> preorder,vector<int> inorder,int n,map<int,int> &mp){

    if(index >= n || inorderstart > inorderend){
        return NULL;
    }

    TreeNode *root = new TreeNode(preorder[index]);
    int ele = preorder[index++];
    int pos = mp[ele];

    root->left  = maketree(index,inorderstart,pos-1,preorder,inorder,n,mp);
    root->right = maketree(index,pos+1,inorderend,preorder,inorder,n,mp);

    return root;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {      
map<int,int> mp;

for(int i=0;i<inorder.size();i++){
    mp[inorder[i]] = i;
}

int start = 0;
return maketree(start,0,inorder.size()-1,preorder,inorder,inorder.size(),mp);
    }

};
