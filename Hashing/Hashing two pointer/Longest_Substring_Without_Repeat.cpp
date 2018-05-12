/*Given a string, 
find the length of the longest substring without repeating characters.

Example:

The longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3.

For "bbbbb" the longest substring is "b", with the length of 1.*/
int Solution::lengthOfLongestSubstring(string A) {
    
    int i=0;int mx=1;int cnt=0;
    do
    {
        map<char,int>mp;cnt=0;
        while(i<A.size()&&mp[A[i]]==0)
        {
            mp[A[i]]=i+1;cnt++;
            i++;
        }
        
        if(mx<cnt)
        {
            mx=cnt;
        }
        if(i>=A.size())break;
        i=mp[A[i]];
    }while(i<A.size());
    
    return mx;
}

