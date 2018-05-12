/*Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.



The digit 0 maps to 0 itself.
The digit 1 maps to 1 itself.

Input: Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Make sure the returned strings are lexicographically sorted.*/
void rec(int idx,vector<string>&ms,vector<string >&ans,string s,string ins){
    if(idx==s.length()){
        ans.push_back(ins);
        return ;
    }
    for(int i=0;i<ms[s[idx]-'0'].length();i++)
    {
        rec(idx+1,ms,ans,s,ins+ms[s[idx]-'0'][i]);
    }
    
}
vector<string>  f(string s) {
    
    vector<string>ans;
    vector<string>ms;
    ms.push_back("0");	
    ms.push_back("1");	
	ms.push_back("abc");
	ms.push_back("def");
	ms.push_back("ghi");
	ms.push_back("jkl");
	ms.push_back("mno");
	ms.push_back("pqrs");
	ms.push_back("tuv");
	ms.push_back("wxyz");
	
	
	
    
    rec(0,ms,ans,s,"");
    
    return ans;
}
vector<string> Solution::letterCombinations(string A) {
    return f(A);
}

