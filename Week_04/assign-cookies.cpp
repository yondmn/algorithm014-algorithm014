class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        std::sort(g.begin(),g.end());
        std::sort(s.begin(),s.end());
        int child=0;
        int cookie = 0;
        while(cookie<s.size()&&child<g.size()){
            if(g[child]<=s[cookie]){
                child++;
            } 
            cookie++;
        }
        return child;
    }
};
