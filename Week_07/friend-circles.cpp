/*思路二：利用并查集的思想，并查集的思想；
         并查集主要有两个操作，一个是find，一个是union；
         find的作用是找到一个元素所在集合的代表元素，主要是一个递归的过程；
         union的作用就是将两个元素分别所在的集合合并成一个集合，就是将其中一个元素的代表元素变成另一个元素的代表元素*/
class Solution {
public:
    int find(vector<int> &Vec, int n) {
        if(Vec[n] == -1)
            return n;
        return find(Vec,Vec[n]);
    }

    void Union(vector<int> &Vec,int m,int n){
        int parent_m = find(Vec,m);
        int parent_n = find(Vec,n);
        if(parent_m != parent_n)
            Vec[parent_m] = parent_n;
    }

    int findCircleNum(vector<vector<int>>& M) {
        int N = M.size();
        vector<int> parent(N,-1);
        for(int i = 0; i < N; ++i){
            for(int j = 0; j < N; ++j){
                if (M[i][j] == 1 && i != j)
                    Union(parent,i,j);
            }
        }
        int count = 0;
        for(int i = 0;i < N; ++i)
            if(parent[i] == -1)
                count++;
        return count;
    }
};
