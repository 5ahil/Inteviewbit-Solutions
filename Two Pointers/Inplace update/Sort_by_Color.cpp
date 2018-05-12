/*Given an array with n objects colored red, white or blue, 
sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note: Using library sort function is not allowed.

Example :

Input : [0 1 2 0 1 2]
Modify array so that it becomes : [0 0 1 1 2 2]*/
void Solution::sortColors(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    int zero=0,one=0,two=0;
    for(int i=0;i<A.size();i++)
    {
        if(A[i]==0)zero++;
        else if(A[i]==1)one++;
        else two++;
    }
    int i=0;
    while(i<zero)
    {
        A[i]=0;i++;
    }
    while(i<zero+one)
    {
        A[i]=1;i++;
    }
    while(i<zero+one+two)
    {
        A[i]=2;i++;
    }
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
}
