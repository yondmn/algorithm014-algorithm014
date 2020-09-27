class Solution {
public:
	int Dif_num(string& s1, string& s2){
		int cnt = 0;
		for (int i = 0; i < s1.size(); i++){
			if (s1[i] != s2[i])cnt++;
		}
		return cnt;
	}
	int minMutation(string start, string end, vector<string>& bank) {
		queue<string>qu;
		qu.push(start);
		int res = 0;
		unordered_map<string, int>vis;
		while (!qu.empty()){
			int size = qu.size();
			for (int i = 0; i < size; i++){
				string cur = qu.front();
				vis[cur] = 1;
				qu.pop();
				if (cur == end)return res;
				for (int i = 0; i < bank.size(); i++){
					if (Dif_num(cur, bank[i]) == 1 && !vis[bank[i]]){
						qu.push(bank[i]);
					}
				}
			}
			res++;
		}
		return -1;
	}
};
