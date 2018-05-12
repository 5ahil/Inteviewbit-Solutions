/*Given an unsorted integer array, find the first missing positive integer.

Example:

Given [1,2,0] return 3,

[3,4,-1,1] return 2,

[-8, -7, -6] returns 1

Your algorithm should run in O(n) time and use constant space.*/
int Solution::firstMissingPositive(vector<int> &a) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    int ans=a.size()+1;
    for(int i=0;i<a.size();)
    {
        if(a[i]>0&& a[i]<=a.size()&& a[a[i]-1]!=a[i] )
        {
            int pos=a[i]-1;
            //swap i and pos
            int t=a[pos];
            a[pos]=a[i];
            a[i]=t;
            //cout<<"fe"<<i;
        }
        else i++;
    }
    for(int i=0;i<a.size();i++)
    {
        if(a[i]!=i+1)
        {
            ans=i+1;
            break;
        }
    }
    return ans;
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
}