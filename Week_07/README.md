Trie 树模板

```JavaScript
class Trie {
  constructor() {
    this.root = {};
    this.endOfWord = "$";
  }

  insert(word) {
    let node = this.root;
    for (let ch of word) {
      node[ch] = node[ch] || {};
      node = node[ch];
    }
    node[this.endOfWord] = this.endOfWord;
  }

  search(word) {
    let node = this.root;
    for (let ch of word) {
      if (!node[ch]) return false;
      node = node[ch];
    }
    return node[this.endOfWord] === this.endOfWord;
  }

  startsWith(word) {
    let node = this.root;
    for (let ch of word) {
      if (!node[ch]) return false;
      node = node[ch];
    }
    return true;
  }
}


let trie = new Trie();
console.log(trie.insert("apple"));
console.log(trie.search("apple")); // 返回 true
console.log(trie.search("app")); // 返回 false
console.log(trie.startsWith("app")); // 返回 true
console.log(trie.insert("app"));
console.log(trie.search("app")); // 返回 true
```

并查集 模板

```Java
class UnionFind {
  private int count = 0;
  private int[] parent;
  public UnionFind(int n) {
   count = n;
   parent = new int[n];
   for (int i = 0; i < n; i++) {
     parent[i] = i;
   }
  }
  public int find(int p) {
      while (p != parent[p]) {
          parent[p] = parent[parent[p]];
          p = parent[p];
      }
        return p; 
    }
  public void union(int p, int q) {
   int rootP = find(p);
   int rootQ = find(q);
   if (rootP == rootQ) return;
   parent[rootP] = rootQ;
count--; }
}
 
```