/*Given a sorted array of integers, find the starting and ending position of a given target value.

Your algorithm’s runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

Example:

Given [5, 7, 7, 8, 8, 10]

and target value 8,

return [3, 4].*/
void f1(const vector<int>&a,int key,int l,int h,vector<int>&d)
{
    if(l<=h && key<=a[h]&& key>=a[l])
    {
       
       if(a[l]==a[h]&&a[l]==key)
       {
           if(d[0]>l)d[0]=l;
           if(d[1]<h)d[1]=h;
           return;
       }
       int mid=(l+h)/2;
       f1(a,key,l,mid,d);
       f1(a,key,mid+1,h,d);
    }
    else {
        
    }
    
    
}
vector<int> Solution::searchRange(const vector<int> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    vector<int>d;
    d.push_back(INT_MAX);
    d.push_back(-1);
    f1(A,B,0,A.size()-1,d);
    if(d[0]>d[1])
    {
        d[0]=-1;
        d[1]=-1;
    }
    return d;
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
}
