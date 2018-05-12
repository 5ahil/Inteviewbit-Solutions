/*You are given a binary string(i.e. with characters 0 and 1) S consisting of characters S1, S2, …, SN. In a single operation, you can choose two indices L and R such that 1 ≤ L ≤ R ≤ N and flip the characters SL, SL+1, …, SR. By flipping, we mean change character 0 to 1 and vice-versa.

Your aim is to perform ATMOST one operation such that in final string number of 1s is maximised. If you don’t want to perform the operation, return an empty array. Else, return an array consisting of two elements denoting L and R. If there are multiple solutions, return the lexicographically smallest pair of L and R.

Notes:

Pair (a, b) is lexicographically smaller than pair (c, d) if a < c or, if a == c and b < d.
For example,

S = 010

Pair of [L, R] | Final string
_______________|_____________
[1 1]          | 110
[1 2]          | 100
[1 3]          | 101
[2 2]          | 000
[2 3]          | 001

We see that two pairs [1, 1] and [1, 3] give same number of 1s in final string. So, we return [1]
*/
vector<int> Solution::flip(string A) {
    int count1;int mx=0;int sm=0;
    int l=0,l1=0;int r=-1;
    for(int i=0;i<A.length();i++){
        
        int k=A[i]=='1'?-1:1;
        //cout<<"k= "<<k<<endl;
        sm+=k;
        if(mx<sm){
            l=l1;
            r=i;
            mx=sm;
        }
        if(sm<0){
            sm=0;l1=i+1;
        }
    }
    vector<int>ans;
    if(l<=r){
        ans.push_back(l+1);
        ans.push_back(r+1);
    }
    return ans;
    
    
}
