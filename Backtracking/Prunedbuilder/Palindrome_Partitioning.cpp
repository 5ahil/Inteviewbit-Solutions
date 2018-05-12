/*Given a string s, partition s such that every string of the partition is a palindrome.

Return all possible palindrome partitioning of s.

For example, given s = "aab",
Return

  [
    ["a","a","b"]
    ["aa","b"],
  ]
 Ordering the results in the answer : Entry i will come before Entry j if :
len(Entryi[0]) < len(Entryj[0]) OR
(len(Entryi[0]) == len(Entryj[0]) AND len(Entryi[1]) < len(Entryj[1])) OR
*
*
*
(len(Entryi[0]) == len(Entryj[0]) AND … len(Entryi[k] < len(Entryj[k]))
In the given example,
["a", "a", "b"] comes before ["aa", "b"] because len("a") < len("aa")*/
bool palin(string s)
{
    int i=0,j=s.length()-1;
    while(i<j)
    {
        if(s[i]!=s[j])return false;
        i++;j--;
    }
    return true;
}
void rec(int idx,vector<vector<string>>&ans,vector<string>&ms,string s){
    if(idx==s.length()){
        ans.push_back(ms);
        return ;
    }
    for(int i=idx;i<s.length();i++)
    {
        if(palin(s.substr(idx,i-idx+1)))
        {
            ms.push_back(s.substr(idx,i-idx+1));
            rec(i+1,ans,ms,s);
            ms.pop_back();
        }
    }
}
vector<vector<string>>  f(string s) {
    
    vector<vector<string>>ans;
    vector<string>ms;
    rec(0,ans,ms,s);
    return ans;
}
vector<vector<string> > Solution::partition(string A) {
    return f(A);
}

