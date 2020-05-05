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
public:
    TreeNode* mirrorTree(TreeNode* root) {
        if(root == nullptr) return root;
        swap(root);
        mirrorTree(root->left);
        mirrorTree(root->right);
        return root;
    }
    void swap(TreeNode* root){
        TreeNode* temp;
        temp = root->left;
        root->left = root->right;
        root->right = temp;
    }
};