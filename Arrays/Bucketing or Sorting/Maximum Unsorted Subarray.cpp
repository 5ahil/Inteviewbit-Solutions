/*You are given an array (zero indexed) of N non-negative integers, A0, A1 ,…, AN-1.
Find the minimum sub array Al, Al+1 ,…, Ar so if we sort(in ascending order) that sub array, then the whole array should get sorted.
If A is already sorted, output -1.

Example :

Input 1:

A = [1, 3, 2, 4, 5]

Return: [1, 2]

Input 2:

A = [1, 2, 3, 4, 5]

Return: [-1]
In the above example(Input 1), if we sort the subarray A1, A2, then whole array A should get sorted.*/
vector<int> Solution::subUnsort(vector<int> &A) {
    int s=0;int e=A.size()-2;int i=1;vector<int>ans;
    while(i<A.size()&&A[i]>=A[i-1]){
       i++;
    }
    if(i==A.size()){ans.push_back(-1);return ans;}
    s=i-1;
    //cout<<"s1 "<<s<<endl;
    while(e>=0&&A[e]<=A[e+1]){
        e--;
    }
    e++;
    //cout<<"e1 "<<e<<endl;
    int mn=INT_MAX,mx=INT_MIN;
    //int j=e;
    i=s;
    while(i<=e){
        mn=min(mn,A[i]);
        mx=max(mx,A[i]);
        i++;
    }
    //cout<<"mn max "<<mn<<" "<<mx<<endl;
    i=0;
    while(i<s){
        if(A[i]>mn){
            s=i;
            break;
        }
        i++;
    }
    i=A.size()-1;
    while(i>e){
        if(A[i]<mx){
            e=i;
            break;
        }
        i--;
    }
    ans.push_back(s);
    ans.push_back(e);return ans;
    
}
