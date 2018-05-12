\*Give a N*N square matrix, return an array of its anti-diagonals. Look at the example for more details.

Example:

		
Input: 	

1 2 3
4 5 6
7 8 9

Return the following :

[ 
  [1],
  [2, 4],
  [3, 5, 7],
  [6, 8],
  [9]
]


Input : 
1 2
3 4

Return the following  : 

[
  [1],
  [2, 3],
  [4]
]

See*/
vector<vector<int> > Solution::diagonal(vector<vector<int> > &A) {

    vector<vector<int>>ans;
    int i=1;int r,c;
    while(i<2*A.size()){
        vector<int>tmp;
        if(i<=A.size()){
            r=0;c=i-1;
            while(c>=0){
                //insert
                tmp.push_back(A[r][c]);
                r++;c--;
            }
        }
        else{
            r=i-A.size();c=A.size()-1;
            while(r<A.size()){
                //insert
                tmp.push_back(A[r][c]);
                r++;c--;
            }
        }
        ans.push_back(tmp);
        tmp.clear();
        i++;
    }
    return ans;
    
}
