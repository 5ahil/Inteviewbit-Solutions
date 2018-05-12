/*You are given an array of N integers, A1, A2 ,…, AN. Return maximum value of f(i, j) for all 1 ≤ i, j ≤ N.
f(i, j) is defined as |A[i] - A[j]| + |i - j|, where |x| denotes absolute value of x.

For example,

A=[1, 3, -1]

f(1, 1) = f(2, 2) = f(3, 3) = 0
f(1, 2) = f(2, 1) = |1 - 3| + |1 - 2| = 3
f(1, 3) = f(3, 1) = |1 - (-1)| + |1 - 3| = 4
f(2, 3) = f(3, 2) = |3 - (-1)| + |2 - 3| = 5

So, we return 5.*/
int Solution::maxArr(vector<int> &A) {
    int mx1=INT_MIN,mx2=INT_MIN;
    int mn1=INT_MAX,mn2=INT_MAX;
    for(int i=0;i<A.size();i++)
    {
        mx1=max(mx1,A[i]+i);
        mx2=max(mx2,A[i]-i);
        mn1=min(mn1,A[i]+i);
        mn2=min(mn2,A[i]-i);
    }
    int ans=0;
    ans=max(ans,mx1-mn1);
    ans=max(ans,mx2-mn2);
    return ans;
}
