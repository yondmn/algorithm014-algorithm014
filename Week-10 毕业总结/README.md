# 毕业总结

## 五毒神掌

1. 5-10 分钟读题和思考，如果没有思路，看题解，默写代码
2. 马上自己写，提交LeetCode，多种解法，体会优化
3. 24 小时之后，再重复做题
4. 一周后重复做题
5. 面试前一周恢复性训练


## 时间和空间复杂度

## 时间复杂度

### Big O notation

#### O(1) Constant Complexity 常数复杂度

#### O(log n) Logarithmic Complexity 对数复杂度

#### O(n) Linear Complexity 线性复杂度

#### O(n^2) N square Complexity 平方

#### O(n^3) N cubic Complexity 立方

#### O(2^n) Exponential Growth 指数

#### O(n!) Factorial 阶乘

> 只看最高复杂度的运算

递归函数如何分析复杂度 (主定理 Master Theorem)

![](http://assets.ym250.cn/1597066369.png?imageMogr2/thumbnail/!70p)


## 空间复杂度

1. 数组的长度
2. 递归的深度（特殊说明）


## Array 操作时间复杂度

- prepend O(1)
- append O(1)
- look up O(1)
- insert O(n)
- delete O(n)

> 正常情况下数组的 prepend 操作的时间复杂度是 O(n), 但是可以进行特殊操作到 O(1)。采用的方式就是申请稍大的空间，然后在数组的最开始预留一部分空间，然后 prepend 的操作则
> 是把头下标前移一个位置即可。

## LinkedList 操作时间复杂度

- prepend O(1)
- append O(1)
- look up O(n)
- insert O(1)
- delete O(1)

## Skip List (跳表)

跳表的特点：

**只能用于元素有序的情况** (元素个数不多的情况??)

所以，跳表 (skip list) 对标的是平衡树 (AVL Tree) 和二分查找，是一种 **插入、删除、搜索** 都是 **O(log n)** 的数据结构
它最大的优势就是原理简单、实现容易、方便扩展、效率更高。因此在一些热门项目里用来替代平衡树，如 Redis, LevelDB 等。

思考：

如何给有序列表加速？
![](http://assets.ym250.cn/1597069617.png?imageMogr2/thumbnail/!70p)

增加索引 (升维思想，)

![](http://assets.ym250.cn/1597069968.png?imageMogr2/thumbnail/!70p)


## 解题思路

1. 升维 (一维变二维)
2. 空间换时间
3. 懵逼的时候 (暴力? 基本情况递推分析? 找最近重复子问题?)


## 栈、队列、双端队列、优先队列

栈 Stack：FIFO(先进先出) 添加、删除皆为 O(1)
最近相关性

队列 Queue：FILO(先进后出) 添加、删除皆为 O(1)
双端队列 Double-End Queue: 前后都可以添加删除 (就相当于 JavaScript 的数组有 push pop shift unshift)
优先队列 Priority Queue: 插入 O(1); 取出 O(log n) 按元素的优先级取出
优先队列底层的实现的实现较为多样和复杂: heap bst treap avl 等实现


### 总结

第一周按照老师的方法去学习是很有帮助的，比起之前自己刷一遍就不管了的办法好多了，真的要一直刷，就能看很多相似的问题本质
双指针夹逼的方法一般适用于排序后的，接雨水问题虽然不是排序，但是本质上也是比较左右两个指针的大小，然后去想中间夹逼


## 哈希表、映射、集合、树、二叉树、二叉搜索树

### 哈希表 Hash Table

哈希表，也叫散列表，是根据关键码值 (key value) 而直接进行访问的数据结构
它通过把关键码值映射到表中一个位置来访问记录，以加快查找的速度
这个哈希函数也叫散列函数 (Hash Function) , 存放记录的数组叫做哈希表 (或散列表)

![](http://assets.ym250.cn/1597678206.png?imageMogr2/thumbnail/!70p)

### 树、二叉树、二叉搜索树

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

## 二叉搜索树

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


## 递归 & 树形递归 & 分治 & 回溯

### 递归 & 树形递归

> 树的问题的解法一般都是递归

前中后续遍历代码示例

```Python
def preorder(self, root):
    if root:
        self.traverse_path.append(root.val)
        self.preorder(root.left)
        self.preorder(root.right)

def inorder(self, root):
    if root:
        self.inorder(root.left)
        self.traverse_path.append(root.val)
        self.inorder(root.right)

def postorder(self, root):
    if root:
        self.postorder(root.left)
        self.postorder(root.right)
        self.traverse_path.append(root.val)
```

递归四部法则：

1. recursion terminator
2. process logic in current level
3. drill down
4. reverse the current level status if needed

代码模板：

```Java
public void recur(int level, int param) {
     // terminator
    if (level > MAX_LEVEL) { // process result
       return; 
    }
     // process current logic
     process(level, param);
     // drill down
     recur( level: level + 1, newParam);
     // restore current status
}
```

注意：
1. 不要人肉进行递归 (最大误区)
2. 找到最近最简方法，将其拆解成可重复解决的问题 (重复子问题)
3. 数学归纳法思维


### 分治 & 回溯 (Divide & Conquer)

状态树：

![](http://assets.ym250.cn/1598784916.png?imageMogr2/thumbnail/!70p)

分治代码模板：

```Python

def divide_conquer(problem, param1, param2, ...): # recursion terminator
    if problem is None:
        print_result
    return
    # prepare data
    data = prepare_data(problem)
    subproblems = split_problem(problem, data)
    # conquer subproblems
    subresult1 = self.divide_conquer(subproblems[0], p1, ...)
    subresult2 = self.divide_conquer(subproblems[1], p1, ...)
    subresult3 = self.divide_conquer(subproblems[2], p1, ...)
    ...
    # process and generate the final result
    result = process_result(subresult1, subresult2, subresult3, ...)
    # revert the current level states
```

#### 回溯 (backtracking)

回溯法采用试错的思想，它尝试分步的去解决一个问题。在分步解决问题的过程 中，当它通过尝试发现现有的分步答案不能得到有效的正确的解答的时候，它将 取消上一步甚至是上几步的计算，再通过其它的可能的分步解答再次尝试寻找问 题的答案。
回溯法通常用最简单的递归方法来实现，在反复重复上述的步骤后可能出现两种 情况:
- 找到一个可能存在的正确的答案;
- 在尝试了所有可能的分步方法后宣告该问题没有答案;
- 在最坏的情况下，回溯法会导致一次复杂度为指数时间的计算。

核心就是在 for 循环中进行递归

```Python
result = []
def backtrack(路径, 选择列表): if 满足结束条件:
    result.add(路径) return
    for 选择 in 选择列表:
        做选择
        backtrack(路径, 选择列表)
        撤销选择
```

## 深度优先 (DFS)、广度优先 (BFS)

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



