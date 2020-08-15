# 第一周总结

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


## 总结

第一周按照老师的方法去学习是很有帮助的，比起之前自己刷一遍就不管了的办法好多了，真的要一直刷，就能看很多相似的问题本质
双指针夹逼的方法一般适用于排序后的，接雨水问题虽然不是排序，但是本质上也是比较左右两个指针的大小，然后去想中间夹逼
