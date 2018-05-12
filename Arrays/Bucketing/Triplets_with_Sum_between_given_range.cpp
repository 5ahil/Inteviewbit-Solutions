/*Given an array of real numbers greater than zero in form of strings.
Find if there exists a triplet (a,b,c) such that 1 < a+b+c < 2 . 
Return 1 for true or 0 for false.

Example:

Given [0.6, 0.7, 0.8, 1.2, 0.4] ,

You should return 1

as

0.6+0.7+0.4=1.7

1<1.7<2

Hence, the output is 1.

O(n) solution is expected.

Note: You can assume the numbers in strings don’t overflow the primitive data type and there are no leading zeroes in numbers. Extra memory usage is allowed.*/
int Solution::solve(vector<string> &s) {
    vector<float>A;
    for(int i=0;i<s.size();i++){
        A.push_back(std::stof(s[i]));
    }
    
	float ah1_23=-1,ah2_23=-1,ah3_23=-1,bh_231=-1;
	float al1_23=3,al2_23=3,bl1_231=3,bl2_231=3,cl=3;
	float ah1_12=-1,ah2_12=-1;
	float al1_12=3,al1_1223=3,al2_1223=3;
	for(int i=0;i<A.size();i++){
		if(3*A[i]<2){
			if(A[i]>ah1_23){
				ah3_23=ah2_23;
				ah2_23=ah1_23;
				ah1_23=A[i];
			}
			else if(A[i]>ah2_23){
				ah3_23=ah2_23;
				ah2_23=A[i];
			}
			else if(A[i]>ah3_23){
				ah3_23=A[i];
			}
			if(A[i]<al1_23){
				
				al2_23=al1_23;
				al1_23=A[i];
			}
			else if(A[i]<al2_23){
				
				al2_23=A[i];
			}
			if(A[i]<0.5){
				if(A[i]>ah1_12){
				    ah2_12=ah1_12;
					ah1_12=A[i];
				}
				else if(A[i]>ah2_12){
					ah2_12=A[i];
				}
				if(A[i]<al1_12){
				    al1_12=A[i];
				}
			}
			else if(A[i]>=0.5){
				if(A[i]<al1_1223){
				    al2_1223=al1_1223;
					al1_1223=A[i];
				}
				else if(A[i]<al2_1223){
					al2_1223=A[i];
				}
			}
			
		}
		else if(3*A[i]>=2&&A[i]<1){
			if(A[i]<bl1_231){
			    bl2_231=bl1_231;
				bl1_231=A[i];
			}
			else if(A[i]<bl2_231){
				bl2_231=A[i];
			}
			if(A[i]>bh_231){
				bh_231=A[i];
			}
			
		}
		else {
			if(A[i]<cl){
				cl=A[i];
			}
		}
	}
	if(ah1_23+ah2_23+ah3_23>1){   // cout<<"line1\n";     
		return 1;
	}
	if(al1_23+bl1_231+bl2_231<2){ //  cout<<"line2\n";
		return 1;
	}
	if(al1_23+bl1_231+cl<2){//cout<<"line3\n";
		return 1;
	}
	if(al1_23+al2_23+cl<2){//cout<<"line4\n";
		return 1;
	}
	if(al1_1223+al2_1223+bl1_231<2){//cout<<"line5\n";
		return 1;
	}
	if(ah1_12+ah2_12+bh_231>1){//cout<<"line6\n";
		return 1;
	}
	if(al1_12+al1_1223+bl1_231<2){//cout<<"line7\n";
		return 1;
	}
	return 0;
}
