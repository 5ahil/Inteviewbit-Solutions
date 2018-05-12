/*Given an unsorted array, find the maximum difference between the successive elements in its sorted form.

Try to solve it in linear time/space.

Example :

Input : [1, 10, 5]
Output : 5 
Return 0 if the array contains less than 2 elements.

You may assume that all the elements in the array are non-negative integers and fit in the 32-bit signed integer range.
You may also assume that the difference will not overflow.*/
/*int Solution::maximumGap(const vector<int> &A) {
    int len=A.size();
    int *arr_mx=new int[len-1];
    int *arr_mn=new int[len-1];
    
    int mn=INT_MAX,mx=INT_MIN;
	for(int i=0;i<len;i++)
    {
        mn=min(mn,A[i]);
	    mx=max(mx,A[i]);
    }
    if(mn==mx)return 0;
    int gap=(mx-mn)/(len-1);gap=gap?gap:1;
	int a=mn,b=mx;
    for(int i=0;i<len-1;i++)
    {
        arr_mn[i]=INT_MAX;
		arr_mx[i]=INT_MIN;
    }
    for(int i=0;i<len;i++)
    {
        int idx=(A[i]-mn)/gap;
        idx=idx>(len-2)?idx-1:idx;
        arr_mx[idx]=max(arr_mx[idx],A[i]);
        arr_mn[idx]=min(arr_mn[idx],A[i]);
    }
	
	int ans=gap;
        a=arr_mx[0]==INT_MIN?mn:arr_mx[0];b=mx;
	for(int i=1;i<len-1;i++)
	{
	  
	   if(arr_mx[i]!=INT_MIN)
           {
                b=arr_mn[i];
                ans=max(ans,b-a);
                a=arr_mx[i]==mx?arr_mn[i]:arr_mx[i];
           }
	}
    ans=max(ans,mx-a);
	return ans;
}*/
int Solution::maximumGap(const vector<int> &A){
	if(A.size()<2)return 0;
	int mn=INT_MAX,mx=INT_MIN;
	for(int i=0;i<A.size();i++){
		mx=max(mx,A[i]);
		mn=min(mn,A[i]);
	}
	if(mx==mn)return 0;
	int gap=ceil((float)(mx-mn)/(A.size()-1));
	//cout<<"gap<<"<<gap<<endl;
	vector<int>mxv(A.size(),INT_MIN);
	vector<int>mnv(A.size(),INT_MAX);
	
	for(int i=0;i<A.size();i++){
		int idx=ceil((A[i]-mn)/gap);
		mxv[idx]=max(mxv[idx],A[i]);
		mnv[idx]=min(mnv[idx],A[i]);
	}
	int mxDiff=INT_MIN;int i=0,j=1;
	while(j<A.size()){
		if(mxv[j]!=INT_MIN){
			mxDiff=max(mxDiff,mnv[j]-mxv[i]);
			i=j;j++;
		}
		else{
			j++;
		}
	}
	return mxDiff;
}
