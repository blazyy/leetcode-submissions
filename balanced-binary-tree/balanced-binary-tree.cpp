/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
// Get height of left subtree and right subtree, and check if the height difference is more than 1.
// TC - O(2^h) ?
// SC - O(h) - Why not O(n)? Because if we reach a child node we return. This space is reused for consequent function calls. There aren't n function calls on the stack at any given time, but the max at any point is h function calls. 
class Solution {
public:
    bool isBalanced(TreeNode *root) {
        if(!root)
            return true;
        if(abs(get_height(root -> left) - get_height(root -> right)) > 1)
            return false;
        else
            return isBalanced(root -> left) and isBalanced(root -> right);
    }
    int get_height(TreeNode *root) {
        if(!root)
            return -1;
        return max(get_height(root -> left), get_height(root -> right)) + 1;
    }
};
