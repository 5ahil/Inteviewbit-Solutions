/*Find the largest continuous sequence in a array which sums to zero.

Example:


Input:  {1 ,2 ,-2 ,4 ,-4}
Output: {2 ,-2 ,4 ,-4}
*/
vector<int> Solution::lszero(vector<int> &A) {
    vector<int>s,d;int sum=0;map<int,int>hs;
    for(int i=0;i<A.size();i++)
    {
        sum+=A[i];
        s.push_back(sum);
    }
    
    for(int i=0;i<A.size();i++)
    {
        hs[s[i]]=i;
    }
    int l=-1,r=-1,mx=-1;
    for(int i=0;i<A.size();i++)
    {
        int t=s[i]-A[i];
        if(hs.find(t)!=hs.end())
        {
            if(mx<hs[t]-i+1)
            {
                mx=hs[t]-i+1;
                l=i;
                r=hs[t];
            }
        }
    }
    for(int i=l;i<=r&&r!=-1;i++)
    d.push_back(A[i]);
    return d;
}

