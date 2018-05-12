/*Remove Duplicates from Sorted Array

Given a sorted array, remove the duplicates in place such that each element can appear atmost twice and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

Note that even though we want you to return the new length, make sure to change the original array as well in place

For example,
Given input array A = [1,1,1,2],

Your function should return length = 3, and A is now [1,1,2].*/
int Solution::removeDuplicates(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    int k=1;int nn=A[0];int cnt=1;int cc=1;
    for(int i=1;i<A.size();i++)
    {
        if(A[i]==nn)
        {
            if(cnt==1)
            {
                A[k]=A[i];k++;
            cnt++;cc++;
            }
            
        }
        else
        {
            A[k]=A[i];k++;
            nn=A[i];
            cnt=1;cc++;
        }
    }
    return cc;
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
}
