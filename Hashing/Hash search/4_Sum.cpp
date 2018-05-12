/*Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

 Note:
Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ≤ b ≤ c ≤ d)
The solution set must not contain duplicate quadruplets.
Example : 
Given array S = {1 0 -1 0 -2 2}, and target = 0
A solution set is:

    (-2, -1, 1, 2)
    (-2,  0, 0, 2)
    (-1,  0, 0, 1)
Also make sure that the solution set is lexicographically sorted.
Solution[i] < Solution[j] iff Solution[i][0] < Solution[j][0] OR (Solution[i][0] == Solution[j][0] AND ... Solution[i][k] < Solution[j][k])*/

vector<vector<int> > Solution::fourSum(vector<int> &A, int B) {
    sort(A.begin(),A.end());int n=A.size();
    vector<vector<int>>wer;
    for(int i=0;i<n-3;)
    {
        for(int j=i+1;j<n-2;)
        {
            int l=j+1;int h=n-1;
            while(l<h)
            {
                if(A[i]+A[j]+A[l]+A[h]==B)
                {
                    vector<int>ans;
                    ans.push_back(A[i]);ans.push_back(A[j]);ans.push_back(A[l]);ans.push_back(A[h]);
                    wer.push_back(ans);
                    while(A[l]==A[l+1]&&l<A.size()-1)
                    {
                        l++;
                    }
                    while(A[h]==A[h-1]&&h>0)
                    {
                        h--;
                    }
                    ans.clear();l++;h--;
                }
                else if(A[i]+A[j]+A[l]+A[h]>B)h--;
                else l++;
            }
            while(A[j]==A[j+1])j++;j++;
        }
        while(A[i]==A[i+1])i++;i++;
    }
    return wer;
}

