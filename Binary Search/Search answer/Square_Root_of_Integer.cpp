/*Implement int sqrt(int x).

Compute and return the square root of x.

If x is not a perfect square, return floor(sqrt(x))

Example :

Input : 11
Output : 3*/
int Solution::sqrt(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    long long i=1;long long k=A;
    while (i*i<k)
    {
       i++; 
    }
    if(i*i==k)return i;
    return i-1;
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
}
