/*Given a positive integer, return its corresponding column title as appear in an Excel sheet.

For example:

    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB */
	string Solution::convertToTitle(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    string ans="";int i,j,k;k=A;
    while(k>0)
    {
        j=k%26;
        k/=26;
        if(j==0){j=26;k--;}
        ans+=char(j+64);
        
    }
    int len=ans.length()-1;
    int st=0;char ch;
    while(st<len)
    {
        ch=ans[st];
        ans[st]=ans[len];
        ans[len]=ch;
        st++;len--;
    }
    return ans;
}
n