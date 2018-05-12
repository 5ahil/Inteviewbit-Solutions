/*
Validate if a given string is numeric.

Examples:

"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true
Return 0 / 1 ( 0 for false, 1 for true ) for this problem

Clarify the question using “See Expected Output”

Is 1u ( which may be a representation for unsigned integers valid?
For this problem, no.
Is 0.1e10 valid?
Yes
-01.1e-10?
Yes
Hexadecimal numbers like 0xFF?
Not for the purpose of this problem
3. (. not followed by a digit)?
No
Can exponent have decimal numbers? 3e0.1?
Not for this problem.
Is 1f ( floating point number with f as prefix ) valid?
Not for this problem.
How about 1000LL or 1000L ( C++ representation for long and long long numbers )?
Not for this problem.
How about integers preceded by 00 or 0? like 008?
Yes for this problem*/
bool isd(char c)
{
    return c>='0' && c<='9';
}
bool isvalid(const string s)
{
    int n=s.length();
    int kk=n;
    while(s[kk-1]==' ')kk--;
    n=kk;
    if(n==0||(n==1 && !isd(s[0])) )
    {
        return false;
    }
    if(!isd(s[n-1]) )
    {
        return false;
    }
    int i=1;
    while(i<n&&(isd(s[i])||s[i]==' '))
    {
        i++;
        
    }
    if(i==n)
    {
        return true;
    }
    if(s[i]=='e')
    {
        i++;
        if(s[i]=='-')
        {
            i++;
        }
        while(i<n&&(isd(s[i])||s[i]==' '))
        {
            i++;
        }
        if(i==n)return true;
    }
    else if(s[i]=='.')
    {
        i++;int ss=0;
        while(i<n&&(isd(s[i])||s[i]==' '))
        {
            i++;
            ss=1;
        }
        if(ss==0)
        {
            return false;
        }
        if(i==n)
        {
            return true;
        }
        
        if(s[i]=='e')
        {
            i++;
            if(i<n&&s[i]=='-')
            {
                i++;
            }
            while(i<n&&(isd(s[i])||s[i]==' '))
            {
                i++;
            }
            if(i==n)return true;
        }
    }
    return false;
}
int Solution::isNumber(const string A) {
   return isvalid(A);
}
