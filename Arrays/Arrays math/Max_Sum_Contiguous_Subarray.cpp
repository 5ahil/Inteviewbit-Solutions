/*Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example:
Given the array [-2,1,-3,4,-1,2,1,-5,4],

the contiguous subarray [4,-1,2,1] has the largest sum = 6.

For this problem, return the maximum sum.*/
int Solution::maxSubArray(const vector<int> &A) {
    int i=0;
    int sm=0;int mx=INT_MIN;
    while(i<A.size()){
        sm+=A[i];
        mx=max(mx,sm);
        if(sm<0){
            
            sm=0;
            
        }
        i++;
    }
    return mx;
}
