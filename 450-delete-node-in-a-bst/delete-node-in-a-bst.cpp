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
    TreeNode* s;
    TreeNode* succ(TreeNode* root) {
        if(root->left) {
            root->left = succ(root->left);
            return root;
        }
        s = root;
        return root->right;
    }

    TreeNode* find(TreeNode* root,int key) {
        if(root) {
            if(root->val > key) {
                root->left = find(root->left,key);
                return root;
            }
            else if(root->val < key){
                root->right = find(root->right,key);
                return root;
            }
            if(root->right) {
                root->right = succ(root->right);
                root->val = s->val;
            }
            else {
                return root->left;
            }
            return root;
        }
        return NULL;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        return find(root,key);
    }
};