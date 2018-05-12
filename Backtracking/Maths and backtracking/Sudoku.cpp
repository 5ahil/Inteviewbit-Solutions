/*Write a program to solve a Sudoku puzzle by filling the empty cells.
Empty cells are indicated by the character '.' 
You may assume that there will be only one unique solution.



A sudoku puzzle,



and its solution numbers marked in red.

Example :

For the above given diagrams, the corresponding input to your program will be

[[53..7....], [6..195...], [.98....6.], [8...6...3], [4..8.3..1], [7...2...6], [.6....28.], [...419..5], [....8..79]]
and we would expect your program to modify the above array of array of characters to

[[534678912], [672195348], [198342567], [859761423], [426853791], [713924856], [961537284], [287419635], [345286179]]
Seen this question in a real interview */
bool is_safe(int i,int j,int k,vector<vector<char>>&s)
{
    //cout<<i<<" "<<j<<" "<<k<<" "<<s[i][j]<<endl;
    for(int ii=3*(i/3);ii<3*(i/3)+3;ii++)
    {
        for(int jj=3*(j/3);jj<3*(j/3)+3;jj++)
        {
            
            //cout<<ii<<" "<<jj<<endl;
            if(s[ii][jj]==char(k+48))return false;
        }
    }
    
    for(int ii=0;ii<9;ii++)
    if(s[ii][j]==char(k+48))return false;
    for(int ii=0;ii<9;ii++)
    if(s[i][ii]==char(k+48))return false;
    return true;
}
bool issafe(int i,int j,int n,vector<vector<char> > &vec,int nu)
{
   // cout<<i<<" "<<j<<endl;
    int r,c,ii,jj;
    for(r=0;r<n;r++)
    {
        if(vec[r][j]-'0'==nu)
        {
           // cout<<"row"<<" "<<r<<" "<<j<<" "<<nu<<endl;
             return false;
        }
    }
    for(c=0;c<n;c++)
    {
        if(vec[i][c]-'0'==nu)
        {
             // cout<<"col"<<" "<<i<<" "<<c<<" "<<nu<<endl;
              return false;
        }
        
    }
    if(i<=2)
    ii=0;
    else if(ii<=5)
    ii=3;
    else
    ii=6;
     if(j<=2)
    jj=0;
    else if(j<=5)
    jj=3;
    else
    jj=6;
   // cout<<ii<<" "<<jj<<endl;
    for(r=ii;r<ii+3;r++)
    {
        for(c=jj;c<jj+3;c++)
        {
              if(vec[r][c]-'0'==nu)
              {
                   // cout<<"blo"<<" "<<r<<" "<<c<<" "<<nu<<endl;
                       return false;
              }
              
        }
      
    }
  // cout<<i<<" "<<j<<" "<<nu<<endl;
    return true;
}

bool f(vector<vector<char>>&s)
{
    //cout<<"hello";
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            if(s[i][j]=='.')
            {
                for(int k=1;k<=9;k++)
                {
                    if(is_safe(i,j,k,s))
                    //if(issafe(i,j,9,s,k))
                    {
                        //cout<<"worked"<<s[i][j]<<"\n";
                        s[i][j]=char(k+48);
                        //cout<<"become"<<s[i][j]<<"\n";
                        bool t=f(s);
                        if(!t)
                        {
                            s[i][j]='.';
                        }
                    }
                    //cout<<""
                }
            }
            if(s[i][j]=='.')return false;
        }
    }
    return true;
}
void Solution::solveSudoku(vector<vector<char> > &s) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    if(f(s));
    
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
}

