/*You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

You need to do this in place.

Note that if you end up using an additional array, you will only receive partial score.

Example:

If the array is

[
    [1, 2],
    [3, 4]
]
Then the rotated array becomes:

[
    [3, 1],
    [4, 2]
]*/
void Solution::rotate(vector<vector<int> > &A) {
    int n=A.size();int loop=1;
    //int i=0;c=A[0][0];
    while(loop<=n/2)
    {
        int i=0;
        while(i<n-2*loop+1)
        {
            //cout<<"loop:i"<<loop<<":"<<i<<endl;
            int c=A[loop-1+i][n-loop];
            //cout<<"c="<<c<<" and a["<<loop-1<<"]["<<n-loop<<"] ="<<A[loop-1][loop-1+i];
            A[loop-1+i][n-loop]=A[loop-1][loop-1+i];
            int d=A[n-loop][n-loop-i];
            A[n-loop][n-loop-i]=c;
            c=A[n-loop-i][loop-1];
            A[n-loop-i][loop-1]=d;
            A[loop-1][loop-1+i]=c;i++;
        }
        loop++;
    }
    
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
}
