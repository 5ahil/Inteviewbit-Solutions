/*Please Note:
Another question which belongs to the category of questions which are intentionally stated vaguely. 
Expectation is that you will ask for correct clarification or you will state your assumptions before you start coding.

Implement strStr().

 strstr - locate a substring ( needle ) in a string ( haystack ). 
Try not to use standard library string functions for this question.

Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

 NOTE: Good clarification questions:
What should be the return value if the needle is empty?
What if both haystack and needle are empty?
For the purpose of this problem, assume that the return value should be -1 in both cases. */
void cal_pi(string s,int p[])
{
    int i=1,j=0;p[0]=0;
    while(i<s.length())
    {
        while(s[i]!=s[j]&&j>0)
        {
            j=p[j-1];
        }
        if(s[i]==s[j])
        {
            p[i]=j+1;j++;
        }
        i++;
    }
    
}
int Solution::strStr(const string haystack, const string needle) {
    if (needle[0] == '\0') return 0;
        for (int i = 0; haystack[i] != '\0'; i++) {
            bool isMatched = true; 
            for (int j = 0; needle[j] != '\0'; j++) {
                // If remaining haystack length is less than needle's length, 
                // we know needle is not present in haystack.
                if (haystack[i + j] == 0) return -1;
                if (haystack[i + j] != needle[j]) {
                    isMatched = false;
                    break;
                }
            }
            if (isMatched) return i; // Match found
        }
        return -1;
}
