/*Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses of length 2*n.

For example, given n = 3, a solution set is:

"((()))", "(()())", "(())()", "()(())", "()()()"
Make sure the returned list of strings are sorted.*/
void rec(int left,int right,vector<string>&ms,int n,string ins){
    
    if(left==right&&right==n)
    {
        ms.push_back(ins);
        return;
    }
    if(right>left||left>n)return;
    rec(left+1,right,ms,n,ins+"(");
    if(right<left)
    rec(left,right+1,ms,n,ins+")");
}
vector<string>  f(int n) {
    
    vector<vector<string>>ans;
    vector<string>ms;
    rec(0,0,ms,n,"");
    //pp(ms);
    return ms;
}
vector<string> Solution::generateParenthesis(int A) {
    return f(A);
}

