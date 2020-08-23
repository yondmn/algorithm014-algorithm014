/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> result;
        if (root == NULL) return result;

        result.push_back(vector<int>{root->val});
        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            int qs = q.size();
            vector<int> temp;
            for (int i = 0; i < qs; i++) {
                Node* n = q.front();
                q.pop();

                for (Node* c: n->children) {
                    temp.push_back(c->val);
                    q.push(c);
                }
            }

            if (temp.size() > 0)
                result.push_back(temp);
        }

        return result;
    }
};
