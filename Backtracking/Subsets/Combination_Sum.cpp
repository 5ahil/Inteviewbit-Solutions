/*Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

 Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The combinations themselves must be sorted in ascending order.
CombinationA > CombinationB iff (a1 > b1) OR (a1 = b1 AND a2 > b2) OR … (a1 = b1 AND a2 = b2 AND … ai = bi AND ai+1 > bi+1)
The solution set must not contain duplicate combinations.
Example, 
Given candidate set 2,3,6,7 and target 7,
A solution set is:

[2, 2, 3]
[7]*/
	void rec(int idx,vector<int> A,int B,vector<vector<int>>&ans,vector<int >&ms,map<vector<int>,bool>&isv){
    if(B>0)
    {
       if(idx>=A.size())return ;
       ms.push_back(A[idx]);
       rec(idx,A,B-A[idx],ans,ms,isv);
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
    sort(ans.begin(),ans.end());
    return ans;
}



vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {

    return f(A,B);
}

