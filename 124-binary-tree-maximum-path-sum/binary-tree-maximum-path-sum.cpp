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
    int maxSum;
     
    int solve( TreeNode *root){
        if (root == NULL) return 0;   // tree hi nahi hai
         int l = solve( root -> left); // left ka sum trust on recursion
         int r = solve( root -> right); 

        // niche hi path mil gaya ab upar nahi jaa sakte 
         int niche_hi_milgaya_answer = l + r + root-> val; //(1)

         int koi_ek_acha = max( l ,r) + root -> val; // (2)

         int only_root_acha = root ->val; // (3)

         maxSum = max({maxSum,niche_hi_milgaya_answer,koi_ek_acha,only_root_acha });

         return max( koi_ek_acha, only_root_acha); // (1) vale ko uper nahi bhej sakte cz usmai path hamne le liye hai and not ready for addition 2,3 are open for modification
    }

    int maxPathSum(TreeNode* root) {
        
        maxSum = INT_MIN;

        solve(root);  // ye fn maxsum calculate karega 
        return maxSum;

        
    }
};