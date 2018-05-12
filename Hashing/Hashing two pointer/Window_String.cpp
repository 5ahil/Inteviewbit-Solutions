/*Given a string S and a string T, find the minimum window in S which will contain all the characters in T in linear time complexity.
Note that when the count of a character C in T is N, then the count of C in minimum window in S should be at least N.

Example :

S = "ADOBECODEBANC"
T = "ABC"
Minimum window is "BANC"

 Note:
If there is no such window in S that covers all characters in T, return the empty string ''.
If there are multiple such windows, return the first occurring minimum window ( with minimum start index )*/
string f(string A,string B){
    
    int alen=A.size();
    int blen=B.size();int mn=INT_MAX,cnt=0,astart=-1,start=0;
    int ahash[256]={0},bhash[256]={0};
    for(int i=0;i<blen;i++)
    {
        bhash[B[i]]++;
    }
    for(int i=0;i<alen;i++)
    {
        ahash[A[i]]++;
        if(ahash[A[i]]<=bhash[A[i]])cnt++;
        if(cnt==blen)
        {
            while(ahash[A[start]]>bhash[A[start]]){
                ahash[A[start]]--;
                start++;
            }
            int win_len=i-start+1;
            if(mn>win_len){
                mn=win_len;
                astart=start;
            }
            
        }
    }
    if(astart==-1)return "";
    return A.substr(astart,mn);
}
string Solution::minWindow(string A, string B) {
    return f(A,B);
}
.
