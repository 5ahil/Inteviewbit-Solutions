/*Given a positive integer which fits in a 32 bit signed integer, find if it can be expressed as A^P where P > 1 and A > 0. A and P both should be integers.

Example

Input : 4
Output : True  
as 2^2 = 4. */
bool Solution::isPower(int A) {
    
    int i,j,k;bool ans=false;
    if(A==1)return true;
    for(i=2;i<=sqrt(A);i++)
    {
        j=2;
        while(pow(i,j)<A)
        {
            j++;
        }
        if(pow(i,j)==A)
        {
            ans=true;break;
        }
        
    }
    return ans;
}
