/*Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? 
Find all unique triplets in the array which gives the sum of zero.

Note:

 Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
The solution set must not contain duplicate triplets. For example, given array S = {-1 0 1 2 -1 -4}, A solution set is:
(-1, 0, 1)
(-1, -1, 2) */
int bin_search(vector<int>&A,int key,int l,int h)
{
    if(l>h){return -1;}
    if(l==h&&A[l]==key){return l;}
    if(l==h)return -1;
    int mid=(l+h)/2;
    if(key<=A[mid])
    {
        return bin_search(A,key,l,mid);
    }
    return bin_search(A,key,mid+1,h);

}
vector<vector<int> > Solution::threeSum(vector<int> &A) {
     sort(A.begin(),A.end());vector<vector<int>>as;
    
    //cout<<endl<<A.size()<<endl;
    int i=0;int j=A.size()-1;int hh=A.size()-2;
	while(i<hh)
	{
		j=i+1;
		while(j<A.size()-1)
		{
			
			//cout<<"Checking for "<<i<<","<<j<<endl;
			int k=bin_search(A,0-A[i]-A[j],j+1,A.size()-1);
			if(k!=-1)
			{
				vector<int >t;
				//cout<<"inserting "<<i<<","<<j<<","<<k<<" "<<A[i]<<","<<A[j]<<","<<A[k]<<endl;
				t.push_back(A[i]);
				t.push_back(A[j]);
				t.push_back(A[k]);
				as.push_back(t);
			}
			while(j<A.size()-2&&A[j]==A[j+1])j++;   //possible error
			
			j++;
			
		}
		while(i<A.size()-3&&A[i]==A[i+1])i++;   //possible error
		i++;	
			
	}
   
    return as;
}

/*

*/