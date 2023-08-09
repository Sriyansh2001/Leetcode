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
    int ans = 0;
public:
    void solve(TreeNode* root,int targetSum,long long sum,map<long long,int> &mp) {
        if(root) {
            sum += root->val;
            if(mp.find(sum-targetSum)!=mp.end()) {
                ans += mp[sum-targetSum];
            }
            mp[sum] += 1;
            solve(root->left,targetSum,sum,mp);
            solve(root->right,targetSum,sum,mp);
            mp[sum] -= 1;
            if(mp[sum] == 0) {
                mp.erase(sum);
            }
        }
    }

    int pathSum(TreeNode* root, int targetSum) {
        map<long long,int> freq;
        freq[0] = 1;
        solve(root,targetSum,0,freq);
        return ans;
    }
};