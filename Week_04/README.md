# 深度优先 (DFS)、广度优先 (BFS)

DFS 模板:

```C++
map<int, int> visited;
void dfs(Node* root) {
    // terminator
    if (root == NULL) return;

    if (visited.count(root)) {
        // already visited
        return;
    }

    visited[root->val] = 1;

    // process current node here
    for (int i = 0; i < root->children.size(); ++i) {
        dfs(root->children[i]);
    }

    return;
}
```

BFS 模板:

```C++
void bfs(Node* root) {
    if (root == NULL) return;
    
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* n = q.top();
        q.pop();

        if (visited.count(n->val)) continue;

        visited[n->val] = 1;

        for (int i = 0; i < n->children.size(); i++) {
            q.push(n->children[i]);
        }
    }

    return;
}
```

