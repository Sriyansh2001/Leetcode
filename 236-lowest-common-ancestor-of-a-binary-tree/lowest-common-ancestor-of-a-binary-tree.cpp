/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    TreeNode* result(TreeNode* root,TreeNode* p,TreeNode* q) {
        if(root ==  q || root == p) {
            return root;
        }
        if(root) {
            TreeNode* left = result(root->left,p,q);
            TreeNode* right = result(root->right,p,q);
            if(left && right) {
                return root;
            }
            if(left) return left;
            return right;
        }
        return nullptr;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return result(root,p,q);
    }
};