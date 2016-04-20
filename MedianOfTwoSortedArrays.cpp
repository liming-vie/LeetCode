class Solution {
public:
  double findkth(int A[], int m, int B[], int n, int k) {
    if (m > n)  return findkth(B, n, A, m, k);
    if (m == 0) return B[k - 1];
    if (k == 1) return (B[0] < A[0] ? B[0] : A[0]);
    int pa = k >> 1;
    if (pa>m) pa = m;
    int pb = k - pa;
    if (A[pa - 1] < B[pb - 1])
      return findkth(A+pa, m - pa, B, n, k - pa);
    else if (A[pa - 1] > B[pb - 1])
      return findkth(A, m, B+pb, n - pb, k - pb);
    else return A[pa - 1];
  }

  double findMedianSortedArrays(int A[], int m, int B[], int n) {
    if ((m + n) & 1)  return findkth(A, m, B, n, ((m + n) >> 1) + 1);
    else return (findkth(A, m, B, n, (m + n) >> 1) + findkth(A, m, B, n, ((m + n) >> 1) + 1)) / 2;
  }

};