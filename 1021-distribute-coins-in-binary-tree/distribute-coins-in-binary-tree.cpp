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
    int totalMoves = 0;
    int solve(TreeNode* root) {
        if(root == NULL) return 0;
        int coinOnLeft = solve(root->left);
        int coinOnRight = solve(root->right);
        int coinForParent = root->val-1+coinOnRight+coinOnLeft;
        totalMoves += abs(coinForParent);
        return coinForParent;
    }

    int distributeCoins(TreeNode* root) {
        solve(root);
        return totalMoves;
    }
};