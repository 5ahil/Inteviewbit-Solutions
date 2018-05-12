/*The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.

N Queens: Example 1

Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens’ placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

For example,
There exist two distinct solutions to the 4-queens puzzle:

[
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]
*/
bool is_safe(vector<string>&ans,int a,int b,int n)
{
    for(int i=0;i<n;i++)
    if(ans[a][i]=='Q')return false;
    for(int i=0;i<n;i++)
    if(ans[i][b]=='Q')return false;
    int i=a;int j=b;
    while(i>=0&&j>=0)
    {
        if(ans[i][j]=='Q')return false;
        i--;j--;
    }
    i=a;j=b;
    while(i<n&&j<n)
    {
        if(ans[i][j]=='Q')return false;
        i++;j++;
    }
    i=a;j=b;
    while(i>=0&&j<n)
    {
        if(ans[i][j]=='Q')return false;
        i--;j++;
    }
    i=a;j=b;
    while(i<n&&j>=0)
    {
        if(ans[i][j]=='Q')return false;
        i++;j--;
    }
    return true;
}
void print(vector<vector<string>>&ans,int n)
{
    for(int i=0;i<ans.size();i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<ans[i][j]<<"\n";
        }
        cout<<endl;
    }
    cout<<endl;
}
void rec(int idx,vector<string>&ms,vector<vector<string>>&ans,int n)
{
    if(idx>=n)
    {
        ans.push_back(ms);
        return ;
    }
    for(int i=0;i<n;i++)
    {
        if(is_safe(ms,idx,i,n))
        {
            ms[idx][i]='Q';
            rec(idx+1,ms,ans,n);
            ms[idx][i]='.';
        }
    }
}
vector<vector<string>> f(int n)
{
    vector<vector<string>>ans;
    vector<string>ms;
    string s="";
    for(int j=0;j<n;j++)
    {
        s+=".";
    }
    for(int i=0;i<n;i++)
    {
        
        ms.push_back(s);
    }
    rec(0,ms,ans,n);
    //print(ans,n);
     return ans;
}
vector<vector<string> > Solution::solveNQueens(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    return f(A);
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
}

