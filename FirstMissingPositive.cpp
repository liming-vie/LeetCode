class Solution {
public:
   int firstMissingPositive(int A[],int n)
{
    bool flag=false;
    for (int i=1;i<=n;i++) if (A[i-1]==1) flag=true;
    if (flag==false) return 1;
    for (int i=1;i<=n;i++) if (A[i-1]<=0) A[i-1]=1;
    for (int i=1;i<=n;i++) if (A[i-1]>n) A[i-1]=1;
    for (int i=1;i<=n;i++)
    {
        while (1)
        {
            if (A[A[i-1]-1]==A[i-1]) break;
            swap(A[i-1],A[A[i-1]-1]);
        }
    }
    for (int i=1;i<=n;i++) if (A[i-1]!=i) return i;
    return n+1;
}
};