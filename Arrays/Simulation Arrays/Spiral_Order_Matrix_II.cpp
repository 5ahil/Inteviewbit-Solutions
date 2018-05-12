/*Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

Example:

Given n = 3,

You should return the following matrix:

[
  [ 1, 2, 3 ],
  [ 8, 9, 4 ],
  [ 7, 6, 5 ]
]
Seen this question in a real interview beforeYesNo*/
vector<vector<int> > Solution::generateMatrix(int A) {
    vector<vector<int>>ans(A,vector<int>(A,0));
    int i=0;int n=A;int pass=0;
    while(pass<A){
        int r=pass,c=pass;
        while(c<A-pass){
            ans[r][c]=++i;
           c++; 
        }
        c--;
        r++;
        while(r<A-pass)
        {
            ans[r][c]=++i;
            r++;
        }
        r--;
        c--;
        while(c>=pass&&ans[r][c]==0){
            ans[r][c]=++i;
            c--;
        }
        c++;
        r--;
        while(r>pass){
            ans[r][c]=++i;
            r--;
        }
        pass++;
    }
    return ans;
}
