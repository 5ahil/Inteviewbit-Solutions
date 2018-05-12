/*Divide two integers without using multiplication, division and mod operator.

Return the floor of the result of the division.

Example:

5 / 2 = 2
Also, consider if there can be overflow cases. For overflow case, return INT_MAX.*/
int Solution::divide(int A, int B) {
    long long a=A;long long b=B;
    int sign=(a^b)<0;
    a=abs(a);b=abs(b);long long q=0,t=0;
    for(int i=31;i>=0;i--)
    {
        //cout<<"for "<<i<<"  "<<(b<<i)<<" "<<a<<endl;
        if(t+(b<<i)<=a )
        {
            t+=(b<<i);
            
            q|=1ll<<i;
            //cout<<t<<" "<<q<<endl;
        }
    }
    if(sign)
    {
        return -q;
    }
    return q>INT_MAX?INT_MAX:q;
}
