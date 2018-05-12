/*Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

Example:

Given s = "Hello World",

return 5 as length("World") = 5.

Please make sure you try to solve this problem without using library functions. Make sure you only traverse the */
int Solution::lengthOfLastWord(const string A) {
    int clw=0,m=0;
    
    for(int i=0;i<A.length();i++)
    {
        if(A[i]==' ' )
        {
            //m=max(m,clw);
            clw=0;
        }
        else
        {
            clw++;m=clw;
        }
    }
    return m;
}
