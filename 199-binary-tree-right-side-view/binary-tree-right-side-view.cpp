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
/* // using bfs
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
      vector<int> ans;
      if (root == NULL ) return ans;
      queue<TreeNode *>q;
      q.push( root);
      while( ! q.empty()){
        int size = q.size();
        vector<int> level;
        for ( int i=0; i<size; i++){
            TreeNode * node = q.front();
            q.pop();
            
                if ( node -> left) q.push( node -> left);
                if ( node -> right) q.push( node -> right);
                if ( i== size-1)  level.push_back( node -> val); // for right side  and for left side i=0
            
        }
          ans.push_back( level[0]);
      }
      return ans;
        
    }
};
*/ 
// using dfs
class Solution {
public:

    void dfs( TreeNode * root, int level, vector<int> & ans){
        if ( root == NULL) return;
        if ( level == ans.size())
        ans.push_back( root -> val);
        dfs( root -> right, level+1,ans);
        dfs( root -> left, level+1, ans);
     
    }


    vector<int> rightSideView(TreeNode* root) {
         vector<int> ans;
         dfs( root, 0, ans);
         return ans;

    }
    };