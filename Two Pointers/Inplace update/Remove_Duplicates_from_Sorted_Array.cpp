/*Remove duplicates from Sorted Array
Given a sorted array, remove the duplicates in place such that each element appears only once and return the new length.

Note that even though we want you to return the new length, make sure to change the original array as well in place

Do not allocate extra space for another array, you must do this in place with constant memory.

 Example: 
Given input array A = [1,1,2],
Your function should return length = 2, and A is now [1,2*/
int Solution::removeDuplicates(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    int k=1,nn=A[0];int i;
    for(i=1;i<A.size();i++)
    {
        if(nn==A[i])
        {
            
        }
        else
        {
            A[k]=A[i];nn=A[i];
            k++;
        }
        
    }
    A.resize(k);
    return k;
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
}
