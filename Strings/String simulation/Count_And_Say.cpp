/*The count-and-say sequence is the sequence of integers beginning as follows:

1, 11, 21, 1211, 111221, ...
1 is read off as one 1 or 11.
11 is read off as two 1s or 21.

21 is read off as one 2, then one 1 or 1211.

Given an integer n, generate the nth sequence.

Note: The sequence of integers will be represented as a string.

Example:

if n = 2,
the sequence is 11.*/
string Solution::countAndSay(int n) {
    	string s="1";
	//s+=(to_string(2));
	//cout<<s;
	//return 0;
	//int n=10;
	for(int i=1;i<n;i++)
	{
	    int j=0;string q="";
	    while(j<s.length())
	    {
	        char ch=s[j];int cnt=1;
	        j++;
	        while(j<s.length()&&s[j]==ch)
	        {
	            cnt++;j++;
	        }
	        q+=to_string(cnt);
	        q+=to_string(ch-'0');
	    }
	    //cout<<q<<endl;
	    s=q;
	}
return s;
}
