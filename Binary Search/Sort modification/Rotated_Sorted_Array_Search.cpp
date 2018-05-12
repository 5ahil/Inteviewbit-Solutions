/*Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7  might become 4 5 6 7 0 1 2 ).

You are given a target value to search. If found in the array, return its index, otherwise return -1.

You may assume no duplicate exists in the array.

Input : [4 5 6 7 0 1 2] and target = 4
Output : 0

NOTE : Think about the case when there are duplicates. Does your current solution work? How does the time complexity change?*/
int fun(const vector<int>&a,int key,int l,int h)
{
    if(l>h)return -1;
    if(l==h&&a[l]==key)return l;
    int mid=(l+h)/2;
    if(a[l]<=a[mid])
    {
        if(key>=a[l]&&key<=a[mid])
        {
            return fun(a,key,l,mid);
        }
        return fun(a,key,mid+1,h);
    }
    else 
    {
        if(key>=a[mid+1]&&key<=a[h])
        {
            return fun(a,key,mid+1,h);
        }
        return fun(a,key,l,mid);
    }
    //retrurn -1;
}

int Solution::search(const vector<int> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
   return fun(A,B,0,A.size()-1);
    
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
}
