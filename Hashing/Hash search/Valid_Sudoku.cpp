/*Determine if a Sudoku is valid, according to: http://sudoku.com.au/TheRules.aspx

The Sudoku board could be partially filled, where empty cells are filled with the character ‘.’.



The input corresponding to the above configuration :

["53..7....", "6..195...", ".98....6.", "8...6...3", "4..8.3..1", "7...2...6", ".6....28.",*/
bool is_safe(const vector<string>&A,int i,int j,int num)
{
    int si=3*(i/3),sj=3*(j/3);
    //cout<<"line1\n";
    for(int i1=si;i1<si+3;i1++)
    {
        for(int j1=sj;j1<sj+3;j1++)
        {
            if(num==(A[i1][j1]-'0')&&i1!=i&&j1!=j)
            return false;
        }
    }
    //cout<<"line2\n";
    for(int i1=0;i1<9;i1++)
    {
        if(num==(A[i1][j]-'0')&&i1!=i)
            return false;
    }//cout<<"line3\n";
    for(int i1=0;i1<9;i1++)
    {
        if(num==(A[i][i1]-'0')&&i1!=j)
            return false;
    }
    //cout<<"line4\n";
    return true;
}
int Solution::isValidSudoku(const vector<string> &A) {
    int n=9;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(A[i][j]!='.')
            {
                //cout<<"call for"<<A[i][j]<<endl;
                int num=A[i][j]-'0';
                bool safe=is_safe(A,i,j,num);
                if(!safe)return 0;
            }
        }
    }
    return 1;
}

