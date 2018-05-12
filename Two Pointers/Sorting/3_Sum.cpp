/*Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. 
Return the sum of the three integers.

Assume that there will only be one solution

Example: 
given array S = {-1 2 1 -4}, 
and target = 1.

The sum that is closest to the target is 2. (-1 + 2 + 1 = 2)*/

int bin(vector<int>&a,int key,int j,int l,int h)
{
    if(l>=h)
    {
        if(h==0)return h;
        return abs(a[h]-key)<abs(a[h-1]-key)||h-1==j?h:h-1;
    }
    int mid=(l+h)/2;
    if(a[mid]>=key)
    return bin(a,key,j,l,mid);
    return bin(a,key,j,mid+1,h);
}



int Solution::threeSumClosest(vector<int> &A,int target) {
    sort(A.begin(),A.end());int ans=INT_MAX,mn=INT_MAX;
    vector<vector<int>>as;
    for(int i=0;i<A.size()-2;i++)
    {
        //int k=i+2;
        for(int j=i+1;j<A.size()-1;j++)
        {
            int t=target-A[i]-A[j];
            //cout<<i<<","<<j<<","<<t<<","<<A[i]<<","<<A[j]<<","<<endl;
            int k=bin(A,t,j,j+1,A.size()-1);
            //cout<<"k = "<<k<<endl;
            if(mn>abs(A[j]+A[k]+A[i]-target))
                {
                    mn=abs(A[i]+A[j]+A[k]-target);
                    ans=A[j]+A[k]+A[i];
                    //cout<<mn<<" mn,ans "<<ans<<endl;
                    if(mn==0)return ans;
                }
        }
    }
    return ans;
    
}
/*
#include <bits/stdc++.h>

using namespace std;

int bin(vector<int>&a,int key,int l,int h)
{
    if(l>=h)return h;
    int mid=(l+h)/2;
    if(a[mid]>=key)
    return bin(a,key,l,mid);
    return bin(a,key,mid+1,h);
}



int f(vector<int> &A,int target) {
    sort(A.begin(),A.end());int ans=INT_MAX,mn=INT_MAX;
    vector<vector<int>>as;
    for(int i=0;i<A.size();i++)
    {
        cout<<A[i]<<",";
        if(i%13==0)cout<<endl;
    }
    cout<<endl;
    for(int i=0;i<A.size()-2;i++)
    {
        //int k=i+2;
        for(int j=i+1;j<A.size()-1;j++)
        {
            int t=target-A[i]-A[j];
            cout<<i<<","<<j<<","<<t<<","<<A[i]<<","<<A[j]<<","<<endl;
            int k=bin(A,t,j+1,A.size()-1);
            cout<<"k = "<<k<<endl;
            if(mn>abs(A[j]+A[k]+A[i]-target))
                {
                    mn=abs(A[i]+A[j]+A[k]-t);
                    ans=A[j]+A[k]+A[i];
                    cout<<mn<<" mn,ans "<<ans<<endl;
                    if(mn==0)return ans;
                }
        }
    }
    return ans;
    
}
line num t==target 
int main() {
	int a[]={-5, 1, 4, -7, 10, -7, 0, 7, 3, 0, -2, -5, -3, 
	-6, 4, -7, -8, 0, 4, 9, 4, 1, -8, -6, -6, 0, -9, 5, 3, 
	-9, -5, -9, 6, 3, 8, -10, 1, -2, 2, 1, -9, 2, -3, 9, 9, 
	-10, 0, -9, -2, 7, 0, -4, -3, 1, 6, -3};
	int n=sizeof(a)/sizeof(a[0]);
	vector<int>A;
	for(int i=0;i<n;i++)
		
	A.push_back(a[i]);
	cout<<f(A,-1);
	//for(int i=0;i<as.size();i++)
	//	cout<<as[i][0]<<" "<<as[i][1]<<" "<<as[i][2]<<endl;
	//cout<<"Sum of x+y = " << z;
}


*/
