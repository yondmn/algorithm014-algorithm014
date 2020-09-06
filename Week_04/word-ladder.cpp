class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (dict.find(endWord) == dict.end() ) return 0;
        // 初始化起始和终点
        unordered_set<string> beginSet, endSet, tmp, visited;
        beginSet.insert(beginWord);
        endSet.insert(endWord);
        int len = 1;

        while (!beginSet.empty() && !endSet.empty()){
            if (beginSet.size() > endSet.size()){
                tmp = beginSet;
                beginSet = endSet;
                endSet = tmp;
            }
            tmp.clear();
            for ( string word : beginSet){
                for (int i = 0; i < word.size(); i++){
                    char old = word[i];
                    for ( char c = 'a'; c <= 'z'; c++){
                        if ( old == c) continue;
                        word[i] = c;
                        if (endSet.find(word) != endSet.end()){
                            return len+1;
                        }
                        if (visited.find(word) == visited.end() && dict.find(word) != dict.end()){
                            tmp.insert(word);
                            visited.insert(word);
                        }
                    }
                    word[i] = old;
                }
            }
            beginSet = tmp;
            len++;
            

        }
        return 0;
    }
};
