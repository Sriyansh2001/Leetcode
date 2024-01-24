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
    int solve(TreeNode* root,vector<int> &v) {
        if(root==NULL) return 0;
        if(root->left==NULL && root->right==NULL) {
            int ans=0;
            v[root->val]++;
            for(int i=0 ; i<v.size() ; i++) {
                // cout << v[i] << " ";
                if(v[i]%2==1) ans+=1;
            }
            // cout << endl;
            v[root->val]-=1;
            if(ans>1) return 0;
            return 1;
        }
        int ans=0;
        v[root->val]+=1;
        ans += solve(root->left,v);
        ans += solve(root->right,v);
        v[root->val]-=1;
        return ans;
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> v(10);
        return solve(root,v);
    }
};