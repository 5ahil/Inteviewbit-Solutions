/*Given two binary strings, return their sum (also a binary string).

Example:

a = "100"

b = "11"
Return a + b = “111”.*/
string Solution::addBinary(string A, string B) {
    int n1=A.length();
    int n2=B.length();
    int i=0;int j=0;string s="";int carry=0;
    while(i<n1&&j<n2)
    {
        if(A[n1-i-1]+B[n2-j-1]+carry-'0'-'0'>1)
        {
            if(A[n1-i-1]+B[n2-j-1]+carry-'0'-'0'>2)
            {
                s+='1';carry=1;
            }
            else
            {
                s+='0';carry=1;
            }
        }
        else
        {
            s+=to_string(A[n1-i-1]+B[n2-j-1]+carry-'0'-'0');carry=0;
        }
        i++;j++;
    }
    while(i<n1)
    {
        if(A[n1-i-1]+carry-'0'>1)
        {
            if(A[n1-i-1]+carry-'0'>2)
            {
                s+='1';carry=1;
            }
            else
            {
                s+='0';carry=1;
            }
        }
        else
        {
            s+=to_string(A[n1-i-1]+carry-'0');carry=0;
        }
        i++;
    }
    while(j<n2)
    {
        if(B[n2-j-1]+carry-'0'>1)
        {
            if(B[n2-j-1]+carry-'0'>2)
            {
                s+='1';carry=1;
            }
            else
            {
                s+='0';carry=1;
            }
        }
        else
        {
            s+=to_string(B[n2-j-1]+carry-'0');carry=0;
        }
        j++;
    }
    if(carry==1)
    {
        s+='1';
    }
    i=0;j=s.length()-1;
    while(i<j)
    {
        char ch=s[i];
        s[i]=s[j];
        s[j]=ch;i++;j--;
    }
    return s;
}
