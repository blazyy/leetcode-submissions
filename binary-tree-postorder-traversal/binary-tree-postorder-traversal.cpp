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
// Using two stacks. Postorder in reverse is similar to preorder. Only difference is, we visit the right child first. Push the traversal onto the stack. Then pop one by one to get the reverse.
// TC - O(n)
// SC - O(h)
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector <int> traversal;
        stack <TreeNode*> s;
        stack <int> ss;
        TreeNode* current = root;
        while(true) {
            if(current) {
                cout << current -> val;
                ss.push(current -> val);
                s.push(current);
                current = current -> right;
            }
            else if(s.size()) {
                current = s.top(); s.pop();
                current = current -> left;
            }
            else break;
        }
        while(ss.size()) {
            traversal.push_back(ss.top());
            ss.pop();
        }
        return traversal;
    }
};
