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
    int ans = 0;
    pair<int,int> solve(TreeNode* root) {
        if(root==NULL) return {0,INT_MAX};
        pair<int,int> val = solve(root->left);
        pair<int,int> chk = solve(root->right);
        val = {max(val.first,chk.first),min(val.second,chk.second)};
        if(val.second==INT_MAX) return {root->val,root->val};
        ans = max(ans,max(abs(root->val-val.first),abs(root->val-val.second)));
        return {max(val.first,root->val),min(val.second,root->val)};
    }
    int maxAncestorDiff(TreeNode* root) {
        solve(root);
        return ans;
    }
};