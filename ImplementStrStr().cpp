class Solution {
public:
    void getnext(char *s, int *next, int n){
        int k=-1,i=0;
        next[0]=-1;
        while(i<n){
            while(k>=0 && s[i]!=s[k])   k=next[k];
            ++i,++k;
            if(s[i]==s[k])  next[i]=next[k];
            else next[i]=k;
        }
    }

    int strStr(char *haystack, char *needle) {
        if(haystack==NULL || needle==NULL)  return-1;
        
        int len2=strlen(needle);
        if(len2==0) return 0;
        
        int len1=strlen(haystack);
        if(len1<len2)   return -1;
        
        int *next=new int[len2+1];
        getnext(needle,next,len2);
        int i=0,j=0;
        while(i<len1&&j<len2){
            if(j<0||haystack[i]==needle[j]) ++i,++j;
            else j=next[j];
        }
        if(j==len2) return i-j;
        return -1;
    }
};