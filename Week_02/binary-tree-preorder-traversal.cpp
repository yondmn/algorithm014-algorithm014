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
    // 方法1. 借助栈
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> call;
        if(root!=nullptr) call.push(root);
        while(!call.empty()){
            TreeNode *t = call.top();
            call.pop();
            if(t!=nullptr){
                if(t->right) call.push(t->right);
                call.push(t);  //在左节点之前重新插入该节点，以便在左节点之后处理（访问值）
                call.push(nullptr); //nullptr跟随t插入，标识已经访问过，还没有被处理
                if(t->left) call.push(t->left);
            }else{
                res.push_back(call.top()->val);
                call.pop();
            }
        }
        return res;
    }

    // 方法2. 递归
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;

        helper(root, result);

        return result;
    }

    void helper(TreeNode* root, vector<int>& res) {
        if (root == NULL) return;
        res.push_back(root->val);
        helper(root->left, res);
        helper(root->right, res);
    }
};