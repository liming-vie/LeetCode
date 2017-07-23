class Solution {
public:
    int comparePart(string &version1, string &version2, int &s1, int &s2) {
        int l1=version1.length(), l2=version2.length();
        int i1=s1, i2=s2;
        int v1=0, v2=0;
        while(true) {
            if ((i1>=l1 || version1[i1]=='.') && (i2>=l2 || version2[i2]=='.')) break;
            if (i1 < l1 && version1[i1]!='.') v1 = v1*10 + version1[i1++]-'0';
            if (i2 < l2 && version2[i2]!='.') v2 = v2*10 + version2[i2++]-'0';
        }
        s1=i1+1, s2=i2+1;
        if (v1 > v2)    return 1;
        if (v2 > v1)    return -1;
        return 0;
    }
    int compareVersion(string version1, string version2) {
        int s1=0, s2=0, l1=version1.length(), l2=version2.length(), res=0;
        while ((s1<l1 || s2<l2) && res==0) 
            res=comparePart(version1, version2, s1, s2);
        return res;
    }
};