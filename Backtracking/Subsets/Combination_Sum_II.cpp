/*Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

Each number in C may only be used once in the combination.

 Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.
Example :

Given candidate set 10,1,2,7,6,1,5 and target 8,

A solution set is:

[1, 7]
[1, 2, 5]
[2, 6]
[1, 1, 6]*/
void rec(int idx,vector<int> A,int B,vector<vector<int>>&ans,vector<int >&ms,map<vector<int>,bool>&isv){
    if(B>0)
    {
       if(idx>=A.size())return ;
       ms.push_back(A[idx]);
       rec(idx+1,A,B-A[idx],ans,ms,isv);
       ms.pop_back();
       rec(idx+1,A,B,ans,ms,isv);
       
    }
    else if(B==0 && !isv[ms])
    {
        ans.push_back(ms);
        isv[ms]=true;
    }
}
vector<vector<int> > f(vector<int> &A, int B) {
    
    vector<vector<int>>ans;
    vector<int >ms;
    map<vector<int>,bool>isv;
    sort(A.begin(),A.end());
    rec(0,A,B,ans,ms,isv);
    
    return ans;
}
vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {
    
    
    return f(A,B);
}



