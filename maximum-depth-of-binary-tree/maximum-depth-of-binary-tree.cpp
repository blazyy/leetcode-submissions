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
// Recursive DFS.
// TC - O(n) ?
// SC - O(n) ?
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        return max(maxDepth(root -> left), maxDepth(root -> right)) + 1;
    }
};
​
// BFS. Depth increases when all nodes of a level have been dealt with.
// TC - O(n)
// SC - O(n)
// class Solution {
// public:
//     int maxDepth(TreeNode *root) {
//         if(root == nullptr) return 0;
//         int max_depth = 0, depth = 0, nodes_in_current_level;
//         queue <TreeNode *> q;
//         TreeNode *current = root;
//         q.push(current);
//         while(q.size()) {
//             nodes_in_current_level = q.size();
//             while(nodes_in_current_level) {
//                 current = q.front(); q.pop();
//                 if(current -> left) q.push(current -> left);
//                 if(current -> right) q.push(current -> right);
//                 nodes_in_current_level--;
//             }
//             depth++;
//             max_depth = max(max_depth, depth);
//         }
//         return max_depth;
//     }
// };
​
// Iterative DFS. We keep track of current depth using a stack. Each item in the depths stack corresponds to the depth of the item in the same place/index as the node in the other stack.
// TC - O(n) where n is the number of nodes in the tree
// SC - O(n)
// class Solution {
// public:
//     int maxDepth(TreeNode *root) {
//         if(root == nullptr) return 0;
//         int max_depth = 0;
//         TreeNode *current = root;
//         stack <int> depths; stack <TreeNode *> s;
//         s.push(current); depths.push(1);
//         while(!s.empty()) {
//             current = s.top(); cout << current -> val << " "; s.pop();
//             int temp = depths.top(); depths.pop();
//             max_depth = max(max_depth, temp);
//             if(current -> right) {
//                 s.push(current -> right);
//                 depths.push(temp + 1);
//             }
//             if(current -> left) {
//                 s.push(current -> left);
//                 depths.push(temp + 1);
//             }
//         }
//         return max_depth;
//     }
// };
