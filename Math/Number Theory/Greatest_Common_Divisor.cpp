/*Given 2 non negative integers m and n, find gcd(m, n)

GCD of 2 integers m and n is defined as the greatest integer g such that g is a divisor of both m and n.
Both m and n fit in a 32 bit signed integer.

Example

m : 6
n : 9

GCD(m, n) : 3 */
int fun(int a,int b)
{
    if(b%a==0)return a;
    return fun(b%a,a);
}
int Solution::gcd(int A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int a=min(A,B);int b=max(A,B);
    if(A==0)return B;
    if(B==0)return A;
    return fun(a,b);
}
