/*Given numRows, generate the first numRows of Pascal’s triangle.

Pascal’s triangle : To generate A[C] in row R, sum up A’[C] and A’[C-1] from previous row R - 1.

Example:

Given numRows = 5,

Return

[
     [1],
     [1,1],
     [1,2,1],
     [1,3,3,1],
     [1,4,6,4,1]
]
Seen this question in a real interview beforeYesNo*/
vector<vector<int> > Solution::generate(int A) {
    vector<vector<int>>pascle;
    if(A==0)return pascle;
    pascle.push_back(vector<int>(1,1));
    for(int i=1;i<A;i++){
        vector<int>t;
        t.push_back(1);
        if(i>1){
            int j=1;
            while(j<pascle[i-1].size()){
                t.push_back(pascle[i-1][j-1]+pascle[i-1][j]);
                j++;
            }
        }
        t.push_back(1);
        pascle.push_back(t);
        t.clear();
    }
    return pascle;
}
