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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int length = preorder.size();
        if (length == 0) return NULL;
        return helper(preorder, inorder, 0, length - 1, 0, length - 1);
    }

    TreeNode* helper(
        vector<int>& preorder,
        vector<int>& inorder,
        int preorderStart,
        int preorderEnd,
        int inorderStart,
        int inorderEnd
    ) {
        TreeNode* root = new TreeNode(preorder[preorderStart]);

        if (preorderStart == preorderEnd) return root;

        // 中序遍历中找跟节点
        int rootIndex = preorderStart;
        while (rootIndex <= inorderEnd && root->val != inorder[rootIndex]) rootIndex++;

        // 重新下一层下边然后递归
        int leftLength = rootIndex - preorderStart;
        int leftPreorderEnd = preorderStart + leftLength;
        if (leftLength > 0) {
            root->left = helper(
                preorder,
                inorder,
                preorderStart + 1,
                leftPreorderEnd,
                inorderStart,
                rootIndex - 1
            );
        }

        if (leftLength < preorderEnd - preorderStart) {
            root->right = helper(
                preorder,
                inorder,
                leftPreorderEnd + 1,
                preorderEnd,
                rootIndex + 1,
                inorderEnd
            );
        }

        return root;
    }
};
