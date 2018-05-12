/*You are given a string. The only operation allowed is to insert characters in the beginning of the string. How many minimum characters are needed to be inserted to make the string a palindrome string

Example:
Input: ABC
Output: 2
Input: AACECAAAA
Output: 2*/
int fun(string s)
{
        int n=s.length();int k=0;
        for(int i=0;i<n;i++)
        {
                int l=0;
                int r=n-i-1;k=r;
                while(l<=r && s[l]==s[r])
                {
                   l++;r--;
                }
                if(l>r){break;}
                
        }
        return n-k-1;
        
}
int Solution::solve(string A) {
    return fun(A);
}
