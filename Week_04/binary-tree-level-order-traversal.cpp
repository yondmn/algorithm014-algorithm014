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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (root == NULL) return result;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            vector<int> temp;
            int currSize = q.size();
            int i = 0;
            while (i < currSize) {
                TreeNode* node = q.front();
                q.pop();
                temp.push_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
                i++;
            }
            result.push_back(temp);
        }

        return result;
    }
};