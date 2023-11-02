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
    vector<int> solve(TreeNode* root) {
        if(root) {
            vector<int> left = solve(root->left);
            vector<int> right = solve(root->right);
            int nodes = left[1]+right[1]+1;
            int val = left[0]+right[0]+root->val;
            int avg = val/nodes;
            if(avg == root->val) {
                ans+=1;
            }
            return {val,nodes};
        }
        return {0,0};
    }

    int averageOfSubtree(TreeNode* root) {
        solve(root);
        return ans;
    }
};