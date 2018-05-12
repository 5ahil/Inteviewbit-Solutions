/*Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

Example:

"A man, a plan, a canal: Panama" is a palindrome.

"race a car" is not a palindrome.

Return 0 / 1 ( 0 for false, 1 for true ) for this problem*/
int Solution::isPalindrome(string A) {
    int l=0;
    int h=A.length();
    while(l<h)
    {
        while(l<h&&(A[l]<'0'||A[l]>'9'&&A[l]<'A'  ||  A[l]>'Z'&&A[l]<'a' || A[l]>'z'))
        {
            l++;
        }
        while(l<h&&(A[h]<'0'||A[h]>'9'&&A[h]<'A'  ||  A[h]>'Z'&&A[h]<'a' || A[h]>'z'))
        {
            h--;
        }
        if(l<h)
        {
            int x;
            if(A[l]>='A'&&A[l]<='Z')x=A[l]-'A';
            else if(A[l]>='a'&&A[l]<='z')
            x=A[l]-'a';
            else x=A[l]-'0';
            int y;
            if(A[h]>='A'&&A[h]<='Z')y=A[h]-'A';
            else if(A[h]>='a'&&A[h]<='z')
            y=A[h]-'a';
            else
            y=A[h]-'0';
            if(x!=y)
            break;
            l++;h--;
        }
        
    }
    if(l<h)return 0;
    return 1;
}
