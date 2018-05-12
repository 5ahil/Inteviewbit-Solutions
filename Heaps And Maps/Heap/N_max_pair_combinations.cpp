/*Given two arrays A & B of size N each.
Find the maximum n elements from the sum combinations (Ai + Bj) formed from elements in array A and B.

For example if A = [1,2], B = [3,4], then possible pair sums can be 1+3 = 4 , 1+4=5 , 2+3=5 , 2+4=6
and maximum 2 elements are 6, 5

Example:

N = 4
a[]={1,4,2,3}
b[]={2,5,1,6}

Maximum 4 elements of combinations sum are
10   (4+6), 
9    (3+6),
9    (4+5),
8    (2+6)*/
struct compare{
    bool operator()(int a,int b)
    {
        return a>b;
    }
};
vector<int> Solution::solve(vector<int> &A, vector<int> &B) {
    //priority_queue<int,vector<int>,compare>pq;
    priority_queue <pair<int,pair<int,int>>>pq;
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    
    int n=A.size();
    set<pair<int,int>>ss;vector<int>ans;
    ss.insert(make_pair(n-1,n-1));
    pq.push(make_pair(A[n-1]+B[n-1],make_pair(n-1,n-1)));
    while(n--){
        pair<int,pair<int,int>>tmp=pq.top();
        pq.pop();
        ans.push_back(tmp.first);
        int i=tmp.second.first;
        int j=tmp.second.second;
        if(ss.find(make_pair(i-1,j))==ss.end()){
            pq.push(make_pair(A[i-1]+B[j],make_pair(i-1,j)));
            ss.insert(make_pair(i-1,j));
        }
        if(ss.find(make_pair(i,j-1))==ss.end()){
            pq.push(make_pair(A[i]+B[j-1],make_pair(i,j-1)));
            ss.insert(make_pair(i,j-1));
        }
    }
    return ans;
}

