/*Given a collection of numbers, return all possible permutations.

Example:

[1,2,3] will have the following permutations:

[1,2,3]
[1,3,2]
[2,1,3] 
[2,3,1] 
[3,1,2] 
[3,2,1]*/
void rec(int idx,vector<int>&A,vector<int>&ms,map<int,bool>&mp,vector<vector<int>>&ans){
    if(idx==A.size()){
        ans.push_back(ms);
        return;
    }
    for(int i=0;i<A.size();i++)
    {
       // cout<<"for i"<<i<<endl;
        if(!mp[A[i]])
        {
            //cout<<"in here for "<<
            ms.push_back(A[i]);
            mp[A[i]]=true;
            rec(idx+1,A,ms,mp,ans);
            ms.pop_back();
            mp[A[i]]=false;
            
        }
    }
}

vector<vector<int> > f(vector<int> &A) {
    vector<vector<int> >ans;
    vector<int>ms;
    map<int,bool>mp;
     rec(0,A,ms,mp,ans);
    return ans;
}
vector<vector<int> > Solution::permute(vector<int> &A) {

    return f(A);
}

