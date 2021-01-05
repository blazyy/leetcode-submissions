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
​
// Iterative DFS. The number of nodes in the stack is the depth of the tree at any point in the traversal. The maximum number of elements seen in the stack at any point of time will give us the depth of the tree.
// TC - O(n) where n is the number of nodes in the tree
// SC - O(n)
class Solution {
public:
    int maxDepth(TreeNode *root) {
        if(root == nullptr) return 0;
        int max_depth = 0;
        stack <TreeNode *> s;
        vector <TreeNode *> visited;
        TreeNode *current = root;
        s.push(current);
        visited.push_back(current);
        while(!s.empty()) {
            current = s.top();
            max_depth = max(max_depth, (int)s.size());
            if(current -> left and find(visited.begin(), visited.end(), current -> left) == visited.end()) {
                s.push(current -> left);
                visited.push_back(current -> left);
            }
            else if(current -> right and find(visited.begin(), visited.end(), current -> right) == visited.end()) {
                s.push(current -> right);
                visited.push_back(current -> right);
            }
            else s.pop();
        }
        return max_depth;
    }
};
​
// Old Solution
// Recursive DFS.
// TC - O(n) ?
// SC - O(n) ?
// class Solution {
// public:
//     int maxDepth(TreeNode* root) {
//         if(root == nullptr) return 0;
//         return max(maxDepth(root -> left), maxDepth(root -> right)) + 1;
//     }
// };
