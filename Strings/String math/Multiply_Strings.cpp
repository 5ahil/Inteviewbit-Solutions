/*Given two numbers represented as strings, return multiplication of the numbers as a string.

 Note: The numbers can be arbitrarily large and are non-negative.
Note2: Your answer should not have leading zeroes. For example, 00 is not a valid answer. 
For example, 
given strings "12", "10", your answer should be “120”.

NOTE : DO NOT USE BIG INTEGER LIBRARIES ( WHICH ARE AVAILABLE IN JAVA / PYTHON ). 
We will retroactively disqualify such submissions and the submissions will incur penalties.*/
string Solution::multiply(string a, string b) {
    string vs[b.length()];
	for(int i=0;i<b.length();i++)
	vs[i]="";
	int i=0;int mxl=0;
	while(i<b.length())
	{
	    int nm=b[b.length()-1-i]-'0';
	    int j=0;int carry=0;string kk="";
	    int m=i;
	    while(m>0)
	    {
	        kk+="0";m--;
	    }
	    while(j<a.length())
	    {
	        int nm2=a[a.length()-1-j]-'0';
	        int nm3=nm*nm2+carry;
	        carry=nm3/10;
	        nm3=nm3%10;
	        kk+=to_string(nm3);j++;
	    }
	    if(carry!=0)
	    {
	        kk+=to_string(carry);
	    }
	    i++;
	    int l=0;int h=kk.length()-1;
	    while(l<h&&0)
	    {
	        char ch=kk[l];
	        kk[l]=kk[h];
	        kk[h]=ch;l++;h--;
	    }
	    vs[i-1]=kk;
	    int gh=kk.length();
	    mxl=max(mxl,gh);
	}
	 i=0;string as="";int carry=0;
	while(i<mxl)
	{
	    int num=0;
	    for(int j=0;j<b.length();j++)
	    {
	        if(i<vs[j].length())
	        {
	            num+=(vs[j][i]-'0');
	        }
	    }
	    num+=carry;
	    carry=num/10;
	    num%=10;
	    as+=to_string(num);i++;
	}
	if(carry!=0)as+=to_string(carry);
	/*for(int i=0;i<b.length();i++)
	{
	    cout<<vs[i]<<endl;
	}*/
	int l=0;int h=as.length()-1;
	    while(l<h)
	    {
	        char ch=as[l];
	        as[l]=as[h];
	        as[h]=ch;l++;h--;
	    }
	    i=0;
	    while(i<as.length()&&as[i]=='0')i++;
	    string ans="";
	    if(i==as.length())return "0";n
	    else
	    {
	        while(i<as.length()){ans+=as[i];i++;}
	    }
	    return ans;
}
