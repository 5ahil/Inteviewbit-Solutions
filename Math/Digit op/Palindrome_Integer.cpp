/*Determine whether an integer is a palindrome. Do this without extra space.

A palindrome integer is an integer x for which reverse(x) = x where reverse(x) is x with its digit reversed.
Negative numbers are not palindromic.

Example :

Input : 12121
Output : True

Input : 123
Output : False*/
bool Solution::isPalindrome(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int len=0,a=A;
    while(a>0)
    {
        len++;
        a/=10;
    }
    int aL=A,aR=A;int left=0,right=len-1;
    while(left<right)
    {
        if(aL/pow(10,right)!=aR%10)
        return false;
        left++;right--;
        aL%=(int)pow(10,right);
        aR/=10;
    }
    
    return true;
    
}
