/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *      TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
 * };
 **/

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;

        queue<pair<TreeNode*, unsigned long long>> q;
        q.push({root, 0});
        int maxWidth = 0;

        while (!q.empty()) {
            int levelSize = q.size();
            unsigned long long levelStart = q.front().second;
            unsigned long long levelEnd = q.back().second;
            maxWidth = max(maxWidth, (int)(levelEnd - levelStart + 1));

            for (int i = 0; i < levelSize; i++) {
                auto [node, position] = q.front();
                q.pop();
                if (node->left) q.push({node->left, position * 2});
                if (node->right) q.push({node->right, position * 2 + 1});
            }
        }

        return maxWidth;
    }
};