/*
Given a set of distinct integers, S, return all possible subsets.

 Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
Also, the subsets should be sorted in ascending ( lexicographic ) order.
The list is not necessarily sorted.
Example :

If S = [1,2,3], a solution is:

[
  [],
  [1],
  [1, 2],
  [1, 2, 3],
  [1, 3],
  [2],
  [2, 3],
  [3],
]
Seen this question in a real interview before
*/
vector<vector<int> > Solution::subsets(vector<int> &A) {
	int n=A.size();
	sort(A.begin(),A.end());
	int csz=1<<n;vector<vector<int>>ans;
	for(int i=0;i<csz;i++)
	{
		vector<int>aa;//cout<<"for i="<<i<<endl;
		for(int j=0;j<n;j++)
		{
			
			if(i&1<<j)
			{
				aa.push_back(A[j]);
				//cout<<"pushing "<<A[j]<<"int set "<<i<<"\n";
			}
		}
		ans.push_back(aa);
	}
	sort(ans.begin(),ans.end());
	return ans;
    
}

