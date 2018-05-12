/*
Given two integers n and k, return all possible combinations of k numbers out of 1 2 3 ... n.

Make sure the combinations are sorted.

To elaborate,

Within every entry, elements should be sorted. [1, 4] is a valid entry while [4, 1] is not.
Entries should be sorted within themselves.
Example :
If n = 4 and k = 2, a solution is:

[
  [1,2],
  [1,3],
  [1,4],
  [2,3],
  [2,4],
  [3,4],
]
*/
bool rec(int idx,int A,int B,vector<vector<int>>&ans,vector<int >&ms){
    if(B>0)
    {
       if(idx>=A.size())return false;
       ms.push_back(A[idx]);
       bool res=rec(idx+1,A,B-A[idx],ans,ms);
       if(res)
       {
           ans.push_back(ms);
       }
       ms.pop_back();
       res=rec(idx+1,A,B,ans,ms);
       if(res)
       {
           ans.push_back(ms);
       }
    }
    else if(B<0)
    {
        retrun false;
    }
    else 
    {
        return true;
    }
}
vector<vector<int> > Solution::combine(int A, int B) {
    vector<vector<int>>ans;
    vector<int>myset;
    int i=1;
    rec(0,A,B,ans,myset);
    return ans;
}

