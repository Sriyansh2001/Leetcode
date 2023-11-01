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
    vector<int> ans;
    int mx;

    void solve(TreeNode* root,int add) {
        stack<TreeNode*> st;
        int count=1;
        int temp = -1;

        while(true) {
            while(root != NULL) {
                st.push(root);
                root = root->left;
            }
            if(st.empty()) break;
            TreeNode* t = st.top();
            st.pop();
            if(t->val == temp) {
                count+=1;
            }
            else {
                temp = t->val; count = 1;
            }
            if(add && mx == count) {
                ans.push_back(t->val); 
            }
            mx = max(mx,count);
            root  = t->right;
        }
        return ;
    }

    vector<int> findMode(TreeNode* root) {
        mx=0;
        solve(root,false);
        solve(root,true);
        return ans;
    }
};