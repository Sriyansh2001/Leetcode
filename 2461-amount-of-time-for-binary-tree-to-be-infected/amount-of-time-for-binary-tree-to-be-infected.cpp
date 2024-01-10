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
    // Computing height at each node.
    int get_height(TreeNode* root) {
        if(root) {
            //height of left subtree
            int left = get_height(root->left);
            //height of right subtree
            int right = get_height(root->right);
            //maximum among left and right
            int height = max(left,right)+1;
            //returning height.
            return height;
        }
        return 0;
    }

    //Computing the path from root to start.
    bool path_to_start(TreeNode* root,int start,vector<TreeNode*> &path) {
        if(root) {
            // Current value.
            int val = root->val;
            //pushing in the array.
            path.push_back(root);
            //if we get the value then does not required to compute later.
            if(val == start) {
                return true;
            }
            //compute for left.
            bool left = path_to_start(root->left,start,path);
            if(left) {
                return true;
            }
            //compute for right
            bool right = path_to_start(root->right,start,path);
            if(right) {
                return true;
            }
            path.pop_back();
            return false;
        }
        return false;
    }

    //compue result.
    int result(vector<TreeNode*> &path) {
        int n = path.size();
        TreeNode* prev = path[n-1];
        int height = get_height(prev);
        int current = 0;
        int top = 1;
        for(int i=n-2 ; i>=0 ; --i) {
            TreeNode* curr = path[i];
            if(curr->left == prev) {
                current = max(current,top+get_height(curr->right));
            }
            else {
                current = max(current,top+get_height(curr->left));
            }
            top += 1;
            prev = curr;
        }
        return max(height-1,current);
    }

    int amountOfTime(TreeNode* root, int start) {
        vector<TreeNode*> path;
        path_to_start(root,start,path);
        return result(path);
    }
};