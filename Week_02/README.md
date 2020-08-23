# 哈希表、映射、集合、树、二叉树、二叉搜索树

## 哈希表 Hash Table

哈希表，也叫散列表，是根据关键码值 (key value) 而直接进行访问的数据结构
它通过把关键码值映射到表中一个位置来访问记录，以加快查找的速度
这个哈希函数也叫散列函数 (Hash Function) , 存放记录的数组叫做哈希表 (或散列表)

![](http://assets.ym250.cn/1597678206.png?imageMogr2/thumbnail/!70p)

## 树、二叉树、二叉搜索树

> Linked List 是特殊化的树
> Tree 是特殊化的图

示例代码:

二叉树节点：

```C++
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    }
```

二叉树的三种遍历：

- 前序遍历 (pre-order traversal)
- 中序遍历 (in-order traversal)
- 后续遍历 (post-order traversal)

> 前中后序遍历是指的 **根节点** 的前中后

示例代码：

前序遍历
```C++
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
```

中序遍历
```C++
    vector<int> inorderTraversal(TreeNode* root) {
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
```

后续遍历
```C++
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;

        helper(root, result);
        return result;
    }

    helper(TreeNode* root, vector<int>& result) {
        if (root == NULL) return;

        helper(root->left, result);
        helper(root->right, result);
        result.push_back(root->val);
    }
```

### 二叉搜索树

二叉搜索树，也称二叉排序树、有序二叉树(Ordered Binary Tree)、排 序二叉树(Sorted Binary Tree)，是指一棵空树或者具有下列性质的二叉 树:
1. 左子树上所有结点的值均小于它的根结点的值;
2. 右子树上所有结点的值均大于它的根结点的值;
3. 以此类推:左、右子树也分别为二叉查找树。 (重复性)

特点：中序遍历是升序遍历

常见操作：

1. 查询
2. 插入
3. 删除

Demo: https://visualgo.net/zh/bst

复杂度分析

![](http://assets.ym250.cn/1598167993.png?imageMogr2/thumbnail/!70p)


树的解法为什么都是递归：

因为树的结构本身没有所谓的后继结构或者便于循环的结构，通常都是左节点、有节点，用递归便于将左右子节点做相同的操作即可


## 图

图：有点和边就是图

![](http://assets.ym250.cn/1598169069.png?imageMogr2/thumbnail/!70p)

图的属性：

- Graph(V, E);
- V-vertex: 点
  1. 度 (出度和入党)
  2. 点与点之间 (是否连通)
- E-edge: 边
  1. 有向和无向 (单行线)
  2. 权重 (边长，或者经过这条边所产生的费用)

图的分类:

1. 无向无权图

![](http://assets.ym250.cn/1598169322.png?imageMogr2/thumbnail/!70p)

2. 有向无权图

![](http://assets.ym250.cn/1598169378.png?imageMogr2/thumbnail/!70p)

3. 无向有权图

![](http://assets.ym250.cn/1598169416.png?imageMogr2/thumbnail/!70p)


常见写法：

DFS:

```Python
# 重点是 visited 
visited = set() # 和树中的DFS最大区别
def dfs(node, visited):
    if node in visited: # terminator
    # already visited
    return
    visited.add(node)
    # process current node here.
    ...
    for next_node in node.children(): if not next_node in visited:
    dfs(next_node, visited)
```

```Python
 def BFS(graph, start, end): queue = []
     queue.append([start])
     visited = set() # 和数中的BFS的最大区别
     while queue:
        node = queue.pop() visited.add(node)
        process(node)
        nodes = generate_related_nodes(node) queue.push(nodes)
```

