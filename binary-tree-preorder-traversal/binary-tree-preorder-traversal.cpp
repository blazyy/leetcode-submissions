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
// TC - O(n)
// SC - O(h)
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector <int> traversal;
        stack <TreeNode*> s;
        TreeNode* current = root;
        while(true) {
            if(current) {
                traversal.push_back(current -> val);
                s.push(current);
                current = current -> left;
            }
            else if(s.size()) {
                current = s.top(); s.pop();
                current = current -> right;
            }
            else break;
        }
        return traversal;
    }
};
