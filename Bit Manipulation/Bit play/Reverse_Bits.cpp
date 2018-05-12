/*Reverse bits of an 32 bit unsigned integer

Example 1:

x = 0,

          00000000000000000000000000000000  
=>        00000000000000000000000000000000
return 0

Example 2:

x = 3,

          00000000000000000000000000000011 
=>        11000000000000000000000000000000
return 3221225472

Since java does not have unsigned int, use long*/
unsigned int Solution::reverse(unsigned int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    unsigned int ans=0;int kk=31;
    while(A>0)
    {
        int t=A%2;
        ans+=(t<<kk);
        kk--;
        A=A>>1;
    }
    return ans;
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
}
