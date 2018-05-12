/*Given a collection of integers that might contain duplicates, S, return all possible subsets.

 Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
The subsets must be sorted lexicographically.
Example :
If S = [1,2,2], the solution is:

[
[],
[1],
[1,2],
[1,2,2],
[2],
[2, 2]
]*/
vector<int>v;
map<vector<int>,bool>memo;
vector<vector<int> > r;
void solve(int i,vector<int>uso){
    if(i>=v.size()){
        if(!memo[uso])r.push_back(uso);
        memo[uso]=true;
        return;
    }
    uso.push_back(v[i]);
    solve(i+1,uso);
    uso.pop_back();
    solve(i+1,uso);
}
vector<vector<int> > Solution::subsetsWithDup(vector<int> &A) {
    v=A;
    memo.clear();
    r.clear();
    sort(v.begin(),v.end());
    vector<int>uso;
    solve(0,uso);
    sort(r.begin(),r.end());
    return r;
}
