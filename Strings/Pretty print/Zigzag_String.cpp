/*The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P.......A........H.......N
..A..P....L....S....I...I....G
....Y.........I........R
And then read line by line: PAHNAPLSIIGYIR
Write the code that will take a string and make this conversion given a number of rows:

string convert(string text, int nRows);
convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR"
**Example 2 : **
ABCD, 2 can be written as

A....C
...B....D
and hence the answer would be ACBD.*/
 string f(string s,int k)
{
    int n=s.length();string re="";
    if(k==1)return s;
    int i=0,even=0;
    while(i<k)
    {
        if(i==0||i==k-1)
        {
            int j=i;
            while(j<n)
            {
                re+=s[j];
                j=j+2*k-2;
            }
            i++;
           // re+="\n";
           continue;
        }
        int j=i;
        even=0;
        while(j<n)
            {
                re+=s[j];
                if(even==0)
                {
                    if(k-i>2)
                    j=j+2*(k-i-2)+2;
                    else
                    j=j+2;
                    even=1;
                }
                else
                {
                    if(i+1>2)
                    j=j+2*(i-1)+2;
                    else
                    j=j+2;
                    even=0;
                }
                
               // cout<<"j="<<j<<endl;
            }
            i++;
            //re+="\n";
    }
    
    return re;
}
string Solution::convert(string A, int B) {
    return f(A,B);
}
