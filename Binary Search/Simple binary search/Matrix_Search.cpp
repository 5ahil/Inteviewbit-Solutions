/*Write an efficient algorithm that searches for a value in an m x n matrix.

This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than or equal to the last integer of the previous row.
Example:

Consider the following matrix:

[
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
Given target = 3, return 1 ( 1 corresponds to true )

Return 0 / 1 ( 0 if the element is not present, 1 if the element is present ) for this problem*/
int find_row(vector<vector<int> > &a,int key,int l,int h)
{
    if(l>=h)return l;
    int mid=(l+h)/2;
    if(key<=a[mid][0])
    return find_row(a,key,l,mid);
    return find_row(a,key,mid+1,h);
}
int find_col(vector<vector<int> > &a,int key,int row,int l,int h)
{
    if(l>=h)return l;
    int mid=(l+h)/2;
    if(key<=a[row][mid])
    return find_col(a,key,row,l,mid);
    return find_col(a,key,row, mid+1,h);
}
int f(vector<vector<int> > &a,int key,int r,int c,int l)
{
    if(key<a[0][0])return 0;
    int k=find_row(a,key,0,r);
    //if(k>=r)k--;
    //cout<<k<<"nbn\n";
    if(k<r&&a[k][0]==key)return 1;
    k--;
    //cout<<"k="<<k<<endl;
    int t=find_col(a,key,k,0,c-1);
    if(a[k][t]!=key)return 0;
    //cout<<"k="<<k<<" t="<<t<<endl;
    return 1;
}
int Solution::searchMatrix(vector<vector<int> > &a, int B) {
    // Do not write main() function.
    
    //cout<<a.size()<<" nndndn "<<a[0].size()<<endl;
    return f(a,B,a.size(),a[0].size(),0);
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
}
