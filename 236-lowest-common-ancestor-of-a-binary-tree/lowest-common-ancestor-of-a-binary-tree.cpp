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
    bool solve(TreeNode* root,vector<TreeNode*> &v1,TreeNode* q) {
        if(root) {
            v1.push_back(root);
            if(root->val == q->val) {
                return true;
            } 
            if(solve(root->left,v1,q) || solve(root->right,v1,q)) {
                return true;
            }
            v1.pop_back();
        }
        return false;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> v1,v2;
        solve(root,v1,p);
        solve(root,v2,q);
        int n = min(v1.size(),v2.size());
        TreeNode* prev;
        for(int i=0 ; i<n ; ++i) {
            if(v1[i]->val != v2[i]->val) {
                return prev;
            }
            prev = v1[i];
        }
        return prev;
    }
};