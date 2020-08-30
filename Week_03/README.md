# 递归 & 树形递归 & 分治 & 回溯

## 递归 & 树形递归

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


## 分治 & 回溯 (Divide & Conquer)

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

### 回溯 (backtracking)

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





