/*Given three sorted arrays A, B and Cof not necessarily same sizes.

Calculate the minimum absolute difference between the maximum and minimum number from the triplet a, b, c such that a, b, c belongs arrays A, B, C respectively.
i.e. minimize | max(a,b,c) - min(a,b,c) |.

Example :

Input:

A : [ 1, 4, 5, 8, 10 ]
B : [ 6, 9, 15 ]
C : [ 2, 3, 6, 6 ]
Output:

1
Explanation: We get the minimum difference for a=5, b=6, c=6 as | max(a,b,c) - min(a,b,c) | = |6-5| = 1.*/
int Solution::solve(vector<int> &A, vector<int> &B, vector<int> &C) {
    int i=0;int j=0;int k=0;
    int n1=A.size();int n2=B.size();int n3=C.size();int ans=INT_MAX;
    while(i<n1&&j<n2&&k<n3)
    {
        int mn=min(A[i],B[j]);
        mn=min(mn,C[k]);
        int mx=max(A[i],B[j]);
        mx=max(mx,C[k]);
        if(mx-mn<ans)
        {
            ans=mx-mn;
        }
        if(A[i]==mn)i++;
        else if(B[j]==mn)j++;
        else k++;
    }
    return ans;
}
