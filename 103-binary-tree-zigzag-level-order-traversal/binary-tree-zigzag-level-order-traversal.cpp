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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
            
            vector<vector<int>> ans;
            queue< TreeNode *> q;
            q.push(root);
            bool left_to_right =true ;

            if ( root == NULL) return ans;
            while( ! q.empty()){
                int size = q.size();
                vector<int> level(size);
                
                for ( int i=0; i<size; i++){
                     TreeNode * node = q.front();
                     q.pop(); 
                    int index =  left_to_right? i : size - 1 - i;  // Determine index where this node's value should be placed based on traversal direction  left t0 right  or right to left 
                     
                    if ( node -> left) q.push( node -> left);
                    if ( node -> right) q.push( node -> right);
                    level[index] = node->val;
                }  
                left_to_right = !left_to_right; // toggle direction
                ans.push_back(level);

            }
            return ans;  
    }
};