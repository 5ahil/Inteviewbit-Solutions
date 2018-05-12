/*Given an array A of integers and another non negative integer k, find if there exists 2 indices i and j such that A[i] - A[j] = k, i != j.

Example :

Input :

A : [1 5 3]
k : 2
Output :

1
as 3 - 1 = 2

Return 0 / 1 for this problem.*/
/*int Solution::diffPossible(const vector<int> &A, int B) {
    map<int,int>mp;
    if(A.size()<2)return 0;
    for(int i=0;i<A.size();i++)
    {
        mp[A[i]]=i;
    }
    for(int i=0;i<A.size();i++)
    {
        if(mp.find(A[i]-B)!=mp.end())
        {
            if(mp[A[i]-B]!=i)return 1;
        }
        else if (mp.find(A[i]+B)!=mp.end())
        {
            if(mp[A[i]+B]!=i)return 1;
        }
    }
    return 0;
}*/
int Solution::diffPossible(const vector<int> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    unordered_map<int, int> myMap;
    
    for(int i = 0; i < A.size(); i++){
        if(myMap.find(A[i]) == myMap.end()){
            myMap[A[i]] = 1;
        }
        else{
            myMap[A[i]] = 2;
        }
    }
    
    auto it = myMap.begin();
    
    while(it != myMap.end()){
        int num = it->first-B;
        if(myMap.find(num) != myMap.end()){
            if(myMap.find(num) != it){
                return 1;    
            }
            else{
                if(it->second > 1){
                    return 1;
                }
            }
        }
        it++;
    }
    
    return 0;
}
