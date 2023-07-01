class Solution {
   public:
   vector<vector<int>> verticalTraversal(TreeNode* root) {
      vector<vector<int>> ansfinal;
      if(root==NULL){
          return ansfinal;
      }

      map<int,map<int,multiset<int>>> node;
      queue<pair<TreeNode*,pair<int,int>>> q;

      q.push({root,{0,0}});

      while(!q.empty()){
       pair<TreeNode*,pair<int,int>> temp = q.front();
       q.pop();

       TreeNode* nd = temp.first;
       int ver = temp.second.first;
       int hor = temp.second.second;

       node[ver][hor].insert(nd->val);

       if(nd->left){
       q.push({nd->left,{ver-1,hor+1}});
       } 

       if(nd->right){
       q.push({nd->right,{ver+1,hor+1}});
       }
      } 

      for(auto it:node){
          vector<int> ans;
          for(auto horizontal : it.second){
           ans.insert(ans.end(),horizontal.second.begin(),horizontal.second.end());
          }
          ansfinal.push_back(ans);
      }
      return ansfinal;
   }
};
