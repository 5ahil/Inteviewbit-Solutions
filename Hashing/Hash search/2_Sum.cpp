/*Given an array of integers, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 < index2. Please note that your returned answers (both index1 and index2 ) are not zero-based. 
Put both these numbers in order in an array and return the array from your function ( Looking at the function signature will make things clearer ). Note that, if no pair exists, return empty list.

If multiple solutions exist, output the one where index2 is minimum. If there are multiple solutions with the minimum index2, choose the one with minimum index1 out of them.

Input: [2, 7, 11, 15], target=9
Output: index1 = 1, index2 = 2*/
vector<int> f(const vector<int>&A,int B)
{
    map<int,int>mp;vector<int>hs(A.size(),0);
    vector<int>ans;int hlf1=-1,hlf2=-1;
    for(int i=0;i<A.size();i++)
    {
        if(2*A[i]==B)
        {
            if(hlf1==-1)hlf1=i;
            else if(hlf2==-1)hlf2=i;
        }
        else if(mp.find(A[i])==mp.end())
        {
            mp[A[i]]=i;
        }
    }
    
    int a=0,b=INT_MAX;
    for(int i=A.size()-1;i>0;i--)
    {
        if(mp[A[i]]==i)
        {
            if(mp.find(B-A[i])!=mp.end()&&mp[B-A[i]]!=i&&hs[i]==0)
            {
                b=i;
                a=mp[B-A[i]];hs[a]=1;
            }
        }
    }
    if(hlf2==-1&&b==INT_MAX)return ans;
    if(hlf2!=-1&&b>hlf2)
    {
        a=hlf1;
        b=hlf2;
    }
    ans.push_back(a+1);
    ans.push_back(b+1);
    return ans;
}
vector<int> Solution::twoSum(const vector<int> &A, int B) {
    return f(A,B);
}

