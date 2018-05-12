/Given an index k, return the kth row of the Pascal’s triangle.

Pascal’s triangle : To generate A[C] in row R, sum up A’[C] and A’[C-1] from previous row R - 1.

Example:

Input : k = 3

Return : [1,3,3,1]
 NOTE : k is 0 based. k = 0, corresponds to the row [1]. 
Note:Could you optimize your algorithm to use only O(k) extra space?

Seen this question in a real interview beforeYesNo**/
vector<int> Solution::getRow(int A) {
    vector<int>pascle;
    pascle.push_back(1);
    if(A==0){
        return pascle;
    }
    pascle.push_back(1);
    if(A==1)return pascle;
    int i=2;
    while(i<=A){
        
        int j=1;int prev=1;
        
        while(j<pascle.size()){
            int tmp=pascle[j];
            pascle[j]=prev+pascle[j];
            prev=tmp;
            j++;
        }
        pascle.push_back(1);
        
        i++;
    }
    return pascle;
}
