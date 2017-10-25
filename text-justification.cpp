class Solution {
public:
    string fill(int len) {
        string res;
        while(len--)    res+=" ";
        return res;
    }
    
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        if (!words.size())  return res;
        int start=0, curl=words[0].length();
        
        for (int i=1; i<=words.size(); ++i) {
            if (i==words.size() || curl+words[i].length()+1 > maxWidth) {
                int num_interval = i-start-1;
                int tot_space =maxWidth-curl+num_interval;
                
                string blank, str;
                if (i==start+1) {
                    str = words[start]+fill(tot_space);;
                } else if (i==words.size()) {
                    str = words[start++];
                    for (; start<i; ++start) {
                        str += " " + words[start];
                    }
                    str += fill(tot_space-num_interval);
                } else {
                    int per_spaces=tot_space/num_interval;
                    blank = fill(per_spaces);
                    
                    int left = tot_space % num_interval;
                    str=words[start++];
                    for (int j=1; start<i; ++j, ++start) {
                        if (j<=left)    str += " ";
                        str += blank + words[start];
                    }
                }
                
                res.push_back(str);
                start=i;
                curl=i==words.size()?0:words[i].length();
            } 
            else curl += words[i].length() + 1;
        }        
        
        return res;
    }
};