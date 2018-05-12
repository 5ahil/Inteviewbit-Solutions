/*You are given an array of N integers, A1, A2 ,…, AN and an integer K. Return the of count of distinct numbers in all windows of size K.

Formally, return an array of size N-K+1 where i’th element in this array contains number of distinct elements in sequence Ai, Ai+1 ,…, Ai+k-1.

Note:

If K > N, return empty array.
For example,

A=[1, 2, 1, 3, 4, 3] and K = 3

All windows of size K are

[1, 2, 1]
[2, 1, 3]
[1, 3, 4]
[3, 4, 3]

So, we return an array [2, 3, 3, 2].*/
vector<int> Solution::dNums(vector<int> &A, int B) {
    map<int,int>mp;vector<int >ans;
    int cnt=0;
    for(int i=0;i<B;i++){
        if(mp.find(A[i])==mp.end()){
            cnt++;
        }
        mp[A[i]]++;
    }
    ans.push_back(cnt);int j=0;
    for(int i=B;i<A.size();i++){
        if(mp[A[j]]==1){
            mp.erase(A[j]);cnt--;
        }
        else{
            mp[A[j]]--;
        }
        if(mp.find(A[i])==mp.end()){
            cnt++;
        }
        mp[A[i]]++;
        ans.push_back(cnt);j++;
    }
    return ans;
}

