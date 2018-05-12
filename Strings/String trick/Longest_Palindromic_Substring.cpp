/*Given a string S, find the longest palindromic substring in S.

Substring of string S:

S[i...j] where 0 <= i <= j < len(S)

Palindrome string:

A string which reads the same backwards. More formally, S is palindrome if reverse(S) = S.

Incase of conflict, return the substring which occurs first ( with the least starting index ).

Example :

Input : "aaaabaaa"
Output : "aaabaaa"*/
string fun(string s)
{
    int n=s.length();
    int l=0,r=0;int mx=0;
    for(int i=0;i<n;i++)
    {
        int ln=min(i,n-i-1);
        int j=0;
        while(j+1<=ln && s[i-j-1]==s[i+j+1])
        {
            j++;
        }
         ln=2*j+1;
        if(mx<ln)
        {
           mx=ln;
           l=i-j;
        }
    }
    for(int i=0;i<n-1;i++)
    {
        if(s[i]!=s[i+1])continue;
        int ln=min(i,n-i-2);
        int j=0;
        while(j+1<=ln && s[i-j-1]==s[i+j+2])
        {
            j++;
        }
         ln=2*j+2;
        if(mx<ln)
        {
           mx=ln;
           l=i-j;
        }
    }
    return s.substr(l,mx);
}
string Solution::longestPalindrome(string A) {
    //return fun(A);
     int n = A.length();

int ar[n][n];

string result = "";

int l = 0;

int r = 0;

int mx = 1;



if(n == 0) {

    return result;

}

for(int i = 0;i < n;i++) {

    ar[i][i] = 1;

}

for(int i = 0;i < n-1;i++) {

    if(A[i] == A[i+1]) {

        l = i;

        r = i+1;

        mx = 2;

        ar[i][i+1] = 1;

    }else {

        ar[i][i+1] = 0;

    }

}



for(int k = 3;k <= n;k++) {

    for(int i = 0;i < n-k+1;i++) {

        int j = i+k-1;

        if(A[i] == A[j] && ar[i+1][j-1] == 1) {

            ar[i][j] = 1;

            if(k > mx) {

                l = i;

                r = j;

                mx = k;

            }

        }else {

            ar[i][j] = 0;

        }

    }

}

return A.substr(l,mx);
}
