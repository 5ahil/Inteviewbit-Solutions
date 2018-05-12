/*Given an input string, reverse the string word by word.

Example:

Given s = "the sky is blue",

return "blue is sky the".

A sequence of non-space characters constitutes a word.
Your reversed string should not contain leading or trailing spaces, even if it is present in the input string.
If there are multiple spaces between words, reduce them to a single space in the reversed string*/
void Solution::reverseWords(string &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    int i=0;
    while(i<A.length())
    {
        int l=i;
        while(i<A.length()&&A[i]!=' ')
        {
            i++;
        }
        int h=i-1;
        //cout<<l<<" ff"<<h<<endl;
        while(l<h)
        {
            char c=A[l];
            A[l]=A[h];
            A[h]=c;
            l++;h--;
        }
        i++;
    }
    //cout<<A<<endl;
    int l=0;int h=A.length()-1;
    while(l<h)
        {
            char c=A[l];
            A[l]=A[h];
            A[h]=c;
            l++;h--;
        }
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
}
