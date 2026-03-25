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
    int maxDepth(TreeNode* root) {
        return Height(root);
    }

private:
    int Height(TreeNode* root){
        if (root == NULL){
            return 0;
        }

        int leftht= Height(root->left);
        int rightht= Height(root->right);
        return max(leftht,rightht) +1;
    }

};