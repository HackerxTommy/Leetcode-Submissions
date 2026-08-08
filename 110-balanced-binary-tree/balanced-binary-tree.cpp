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
    bool isBalanced(TreeNode* root) { //O(N) using height of bt
        return dfsheight(root) !=-1;                
    }
        int dfsheight( TreeNode *root){
            if ( root == NULL) return 0;           // if node is  empty
            int leftheight = dfsheight(root -> left);
            if (leftheight == -1) return -1;       

            int rightheight = dfsheight( root -> right);
            if ( rightheight == -1) return -1;

            if ( abs (leftheight - rightheight)>1) return -1;    // checking balanced bt using height( left )- height ( right ) >1 false;
            return (max(leftheight, rightheight)+1);
    
        }
        
    
};