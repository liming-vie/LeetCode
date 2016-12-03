class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        int n=words.size();
        if(!n)  return res;
        int curl=0;
        int curn=0;
        int start=0;
        for(int i=0; i<n; ++i){
            if(curl+words[i].length()+((curl>0)?1:0)<=maxWidth){
                curl+=words[i].length()+(curl>0?1:0);
                curn++;
                continue;
            }
            string line=words[start];
            if(curn==1){
                for(int j=line.length(); j<maxWidth; ++j)
                    line+=' ';
            }else{
                int space=maxWidth-curl+curn-1;
                int k=space%(curn-1);
                int t=space/(curn-1);
                for(int i=1; i<curn; ++i){
                    if(k>=i)    line+=' ';
                    for(int j=0; j<t; ++j)  line+=' ';
                    line+=words[start+i];
                }
            }
            res.push_back(line);
            curn=1;
            curl=words[i].length();
            start=i;
        }
        string line=words[start];
        for(int i=1; i<curn; ++i){
            line+=' ';
            line+=words[start+i];
        }
        curl=maxWidth-curl;
        for(int i=0; i<curl; ++i)   line+=' ';
        res.push_back(line);
        return res;
    }
};