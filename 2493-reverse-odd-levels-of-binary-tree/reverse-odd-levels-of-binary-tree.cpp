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
    void reverse(vector<TreeNode*> &arr) {
        int n = arr.size();
        for(int i=0 ; i<n/2 ; ++i) {
            TreeNode* t1Left = arr[i]->left;
            TreeNode* t1Right = arr[i]->right;
            TreeNode* t2Left = arr[n-i-1]->left;
            TreeNode* t2Right = arr[n-i-1]->right;

            TreeNode* temp = arr[i];
            arr[i] = arr[n-i-1];
            arr[n-i-1] = temp;

            arr[i]->left = t1Left;
            arr[i]->right = t1Right;
            arr[n-i-1]->left = t2Left;
            arr[n-i-1]->right = t2Right;
        }
    }

    TreeNode* reverseOddLevels(TreeNode* root) {
        vector<int> v;
        queue<TreeNode*> q;
        q.push(root);
        bool odd = true;
        while(!q.empty()) {
            vector<TreeNode*> prev,current;
            int size = q.size();
            while(size--) {
                TreeNode* temp = q.front();
                q.pop();
                if(odd) {
                    prev.push_back(temp);
                    if(temp->left) current.push_back(temp->left);
                    if(temp->right) current.push_back(temp->right);
                }
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            if(odd && current.size() > 0) {
                reverse(current);
                for(int i=0 ; i<prev.size() ; ++i) {
                    prev[i]->left = current[2*i];
                    prev[i]->right = current[2*i+1];
                }
            }
            odd = !odd;
        }
        return root;
    }
};