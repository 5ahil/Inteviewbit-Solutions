/* Given a non-negative number represented as an array of digits,

add 1 to the number ( increment the number represented by the digits ).

The digits are stored such that the most significant digit is at the head of the list.

Example:

If the vector has [1, 2, 3]

the returned vector should be [1, 2, 4]

as 123 + 1 = 124.  */
vector<int> Solution::plusOne(vector<int> &A) {
    int l=0;
    for(int i=0;i<A.size();i++){
        if(A[i]!=0)break;
        l++;
    }
    int h=A.size();
    int l1=l,h1=h-1;h--;
    while(l<h){
        int t=A[l];
        A[l]=A[h];
        A[h]=t;
        l++;h--;
    }
    int carry=1;
    int i=l1;
    while(i<=h1){
        int t=A[i]+carry;
        carry=0;
        if(t>9){
            t=0;
            carry=1;
        }
        A[i]=t;
        i++;
    }
    
    if(carry>0){
        A.push_back(1);
        h1++;
    }
    
    vector<int> ans;
    for(i=h1;i>=l1;i--){
        ans.push_back(A[i]);
    }
    return ans;
}
