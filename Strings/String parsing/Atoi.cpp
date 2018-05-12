/*There are certain questions where the interviewer would intentionally frame the question vague.
The expectation is that you will ask the correct set of clarifications or state your assumptions before you jump into coding.

Implement atoi to convert a string to an integer.

Example :

Input : "9 2704"
Output : 9
Note: There might be multiple corner cases here. Clarify all your doubts using “See Expected Output”.

 Questions: Q1. Does string contain whitespace characters before the number?
A. Yes Q2. Can the string have garbage characters after the number?
A. Yes. Ignore it. Q3. If no numeric character is found before encountering garbage characters, what should I do?
A. Return 0. Q4. What if the integer overflows?
A. Return INT_MAX if the number is positive, INT_MIN otherwise. */
bool isd(char c)
{
    return c>='0' && c<='9';
}
int isvalid( const string s)
{
    //return INT_MIN;
    int n=s.length();
    if(s[0]!='-'&&!isd(s[0])&&s[0]!='+'||(n==1&&s[0]=='-'))return 0;
    int i=1;
    while(i<n&&isd(s[i]))i++;
    n=i;
    //i=s[0]=='-'?1:0
    if(s[0]=='-')
    {
        long long sahil=0;
        i=n-1;long long p=1;
        while(i>0&&sahil<=2147483648)
        {
            sahil=sahil + p*(s[i]-'0');i--;p=p*10;
        }
        if(sahil>2147483648)return INT_MIN;
        return 0-(int)sahil;
    }
    long long sahil=0;
        i=n-1;long long p=1;int ll=0;
        if(s[0]=='+')ll++;
        while(i>=ll&&sahil<=2147483648)
        {
            sahil=sahil + p*(s[i]-'0');i--;p=p*10;
        }
        if(sahil>2147483648)return INT_MAX;
        return (int)sahil;
    return 0;
}
int Solution::atoi(const string A) {
    return isvalid(A);
}
