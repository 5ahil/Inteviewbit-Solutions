/*Compare two version numbers version1 and version2.

If version1 > version2 return 1,
If version1 < version2 return -1,
otherwise return 0.
You may assume that the version strings are non-empty and contain only digits and the . character.
The . character does not represent a decimal point and is used to separate number sequences.
For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.

Here is an example of version numbers ordering:

0.1 < 1.1 < 1.2 < 1.13 < 1.13.4*/
int f(string s1,string s2)
{
    int n1=s1.length();
    int n2=s2.length();
    int i=0;int j=0;
    while(i<n1||j<n2)
    {
        int nm1=0,nm2=0;
        while(i<n1&&s1[i]=='0')i++;
        while(j<n2&&s2[j]=='0')j++;
        if(i==n1||j==n2)
        {
            if(j!=n2)
            {
                if(s2[j]!='.')  //s1 finished and s2 having one more digit
                {
                    return -1;
                }
                else
                {
                    j++;
                }
            }
            else if(i!=n1)
            {
                if(s1[i]!='.')
                {
                    return 1;
                }
                else
                {
                    i++;
                }
            }
            else
            {
                return 0;
            }
        }
        else if(s1[i]=='.'||s2[j]=='.')
        {
            if(s2[j]!='.')
            {
                return -1;
            }
            else if(s1[i]!='.')
            {
                return 1;
            }
            else
            {
                i++;j++;
            }

        }
        else
        {
            int rr=0;
            if(s1[i]>s2[j])rr=1;
            else if(s1[i]<s2[j])rr=-1;
            i++;j++;
            while(i<n1&&j<n2 &&s1[i]!='.' && s2[j]!='.')
            {
                if(rr==0)
                {
                    if(s1[i]>s2[j])rr=1;
                    else if(s1[i]<s2[j])rr=-1;
                }
                i++;j++;
            }
            if(i==n1||j==n2)
            {
                if(j!=n2)
                {
                    if(s2[j]=='.')
                    {
                        if(rr!=0)return rr;
                        j++;
                    }
                    else
                    {
                        return -1;
                    }
                }
                else if(i!=n1)
                {
                    if(s1[i]=='.')
                    {
                        if(rr!=0)return rr;
                        i++;
                    }
                    else
                    {
                        return 1;
                    }
                }
                else
                {
                    return rr;
                }
            }
            else if(s1[i]=='.' || s2[j]=='.')
            {
                if(s1[i]!='.')
                {
                    return 1;
                }
                else if(s2[j]!='.')
                {
                    return -1;
                }
                else{
                    if(rr!=0)return rr;
                    i++;j++;
                }
            }
        }
    }
    return 123456;
}


int Solution::compareVersion(string A, string B) {
    return f(A,B);
}
