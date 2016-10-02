class Solution {
public:
    bool isValidSerialization(string preorder) {
        int count=0;
        int p,pre=0;
        while((p=preorder.find(',',pre)) != -1) {
            if(preorder.substr(pre, p-pre) == "#") {
                if(--count < 0)
                    return false;
            }
            else ++count;
            pre=p+1;
        }
        return count == 0 ? preorder.substr(pre) == "#" : false;
    }
};