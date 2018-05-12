/*Find out the maximum sub-array of non negative numbers from an array.
The sub-array should be continuous. That is, a sub-array created by choosing the second and fourth element and skipping the third element is invalid.

Maximum sub-array is defined in terms of the sum of the elements in the sub-array. Sub-array A is greater than sub-array B if sum(A) > sum(B).

Example:

A : [1, 2, 5, -7, 2, 3]
The two sub-arrays are [1, 2, 5] [2, 3].
The answer is [1, 2, 5] as its sum is larger than [2, 3]
NOTE: If there is a tie, then compare with segment's length and return segment which has maximum length
NOTE 2: If there is still a tie, then return the segment with minimum starting index*/
vector<int> Solution::maxset(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    long long mx=0,l=0,r=-1;
	long long cmx=0,cl=0,cr=-1;
	for(int i=0;i<A.size();i++){
		cmx+=A[i];
		if(mx<cmx||mx==cmx&&(r-l)<(i-cl)){
			l=cl;
			r=i;
			mx=cmx;
		}
		if(A[i]<0){
			cl=i+1;
			cmx=0;
		}
	}
	vector<int >ans;
	for(int i=l;i<=r;i++){
		ans.push_back(A[i]);
	}
	return ans;
}