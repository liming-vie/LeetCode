class Solution {
public:
    inline int compute(int a, int b, int c, int d) {
        return (c-a)*(d-b);
    }
    
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int res = compute(A,B,C,D) + compute(E,F,G,H);
        if (B>H || C<E || F>D || A>G)   return res;
        
        int a=A<E?E:A;
        int b=B>F?B:F;
        int c=C<G?C:G;
        int d=D<H?D:H;
        return res - compute(a,b,c,d);
    }
};