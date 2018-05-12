/*Write a function to find the longest common prefix string amongst an array of strings.

Longest common prefix for a pair of strings S1 and S2 is the longest string S which is the prefix of both S1 and S2.

As an example, longest common prefix of "abcdefgh" and "abcefgh" is "abc".

Given the array of strings, you need to find the longest S which is the prefix of ALL the strings in the array.

Example:

Given the array as:

[

  "abcdefgh",

  "aefghijk",

  "abcefgh"
]*/
string Solution::longestCommonPrefix(vector<string> &A) {
    string ans="";
    string qq=A[0];int k=0;
    while(k<qq.length())
    {
        int i;
        for(i=1;i<A.size();i++)
        {
            if(k==A[i].length()||qq[k]!=A[i][k])
            {
                break;
            }
        }
        if(i!=A.size())
        {
            break;
        }
        ans+=qq[k];k++;
    }
    return ans;
}
