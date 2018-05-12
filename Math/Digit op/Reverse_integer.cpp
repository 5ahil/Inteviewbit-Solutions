/*Reverse digits of an integer.

Example1:

x = 123,

return 321
Example2:

x = -123,

return -321

Return 0 if the result overflows and does not fit in a 32 bit signed integer*/
int Solution::reverse(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    long num=0;
    int m=10;
    int ispositive;
    ispositive=(A>0)?1:0;
    int k=abs(A);
    while(k>0)
    {
        num=m*num+(k%10);
        k/=10;
        //cout<<"New num "<<num<<endl;
    }
   // cout<<"New num "<<num<<endl;
    
    if(num>2147483947&&ispositive)return 0;
    else if(num>2147483948&&!ispositive) return 0;
    else if(ispositive)return (int )num;
    else return 0-(int )num;
}
