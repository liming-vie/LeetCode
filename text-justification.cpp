class Solution {
public:
    void fill(stringstream&ss, int size) {
        for(int i=0; i<size; ++i)
            ss<<' ';
    }
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        int n=words.size();
        if(n==0)    return res;
        
        int curl=words[0].length(), left=0;
        stringstream ss;
        
        for(int i=1; i<n; ++i) {
            if(curl+1+words[i].length()>maxWidth) {
                // fill words ans blanks
                int blank_count=i-left-1;
                int tot_blank=(maxWidth-curl)+blank_count;
                ss<<words[left];
                if(i-1==left) {
                    fill(ss,tot_blank);
                }
                else {
                    int blank_size=tot_blank/blank_count;
                    int mod=tot_blank%blank_count;
                    for(int j=left+1; j<i; ++j) {
                        if(j<=left+mod) fill(ss, blank_size+1);
                        else    fill(ss, blank_size);
                        ss<<words[j];
                    }
                }
                res.push_back(ss.str());
                ss.str("");
                left=i;
                curl=words[i].length();
            } else {
                curl+=1+words[i].length();
            }
        }
        ss<<words[left];
        for(int i=left+1; i<n; ++i) {
            ss<<' '<<words[i];
        }
        fill(ss, maxWidth-ss.str().length());
        res.push_back(ss.str());
        return res;
    }
};