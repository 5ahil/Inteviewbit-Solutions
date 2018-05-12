/*Given an array A of integers, find the maximum of j - i subjected to the constraint of A[i] <= A[j].

If there is no solution possible, return -1.

Example :

A : [3 5 4 2]

Output : 2 
for the pair (3, 4)*/
int Solution::maximumGap(const vector<int> &A) {
	vector<bool>tmp(A.size());
	tmp[0]=true;
	int mn=A[0];
	for(int i=0;i<A.size();i++){
		if(mn>=A[i]){
			tmp[i]=true;
			mn=A[i];
		}
		else{
			tmp[i]=false;
		}
	}
	int i=A.size()-1;
	int j=i;int mx=-1;
	while(i>=0){
		if(tmp[i]==false){
			i--;
			continue;
		}
		while(A[i]>A[j]&&j>i){
			j--;
		}
		mx=max(mx,j-i);
		i--;
		
	}
	return mx;
}