class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
        int res=1;
        int len=beginWord.length();
        queue<string> q;
        q.push(beginWord);  q.push("");
        while(true) {
            auto t=q.front();
            q.pop();
            if(t!="") {
                if(t==endWord)  return res;
                for(int i=0; i<len; ++i) {
                    char cur=t[i];
                    for(int j='a'; j<='z'; ++j) {
                        if(j==cur)  continue;
                        t[i]=j;
                        if(wordList.find(t)!=wordList.end()) {
                            q.push(t);
                            wordList.erase(t);
                        }
                    }
                    t[i]=cur;
                }    
            } else {
                if (q.empty())  return 0;
                q.push("");
                ++res;
            }
        }
        return 0;
    }
};