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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> callstack;

        TreeNode* current = root;
        while (current != NULL || callstack.empty()) {
            while (current != NULL) {
                callstack.push(current);
                current = current->left;
            }
            current = callstack.top();
            callstack.pop();
            res.push_back(current->val);
            current = current->right;
        }

        return result;
    }

    vector<int> inorderTraversal1(TreeNode* root) {
        vector<int> res;
        stack<TreeNode *> call;
        if (root != nullptr) call.push(root);
        while(!call.empty()) {
            TreeNode* t = call.top();
            call.pop();
            if (t != nullptr) {
                if (t->right) call.push(t->right);
                call.push(t);
                call.push(nullptr);
                if (t->left) call.push(t->left);
            } else {
                res.push_back(call.top()->val);
                call.pop();
            }
        }

        return res;
    }

    vector<int> inorderTraversal2(TreeNode* root) {
        vector<int> result;
        helper(root, result);
        return result;
    }

    void helper(TreeNode* root, vector<int>& result) {
        if (root == NULL) return;
        helper(root->left, result);
        result.push_back(root->val);
        helper(root->right, result);
    }
};
