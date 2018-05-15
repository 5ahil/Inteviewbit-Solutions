/*
Modified a bit--Sahil
You are given with an array of 1s and 0s. And you are given with an integer M, which signifies number of flips allowed.
Find the position of zeros which when flipped will produce maximum continuous series of 1s.

For this problem, return the indices of maximum continuous series of 1s in order.

Example:

Input : 
Array = {1 1 0 1 1 0 0 1 1 1 } 
M = 1

Output : 
[0, 1, 2, 3, 4] 

If there are multiple possible solutions, return the sequence which has the minimum start index.*/
vector<int> Solution::maxone(vector<int> &Vec, int M) {
    int N = Vec.size();
        int i = 0;
        int j = 0;
        int max_len = 0;
        int cnt = 0;
        vector<int> ans;
	
	int ans_start = 0; 
	int ans_end = 0;

        while(i < N) {
            if(cnt + (Vec[i] == 0) > M) {
                int temp_len = (i - j); // length from j to i - 1. 
                if(temp_len > max_len) {
                        max_len = temp_len;
                        ans_start = j;
			ans_end = i - 1;
                }

                while(i >= j && cnt + (Vec[i] == 0) > M) {
                    cnt -= (Vec[j] == 0);
                    j++;
                }
                cnt += (Vec[i] == 0);
            } else {
                cnt +=(Vec[i] == 0);
            }

            i++;
        }

        int temp_len = (i - j);
        if(temp_len > max_len) {
            temp_len = max_len;
	    ans_start = j;
	    ans_end = i - 1;
        }

	for (int ele = ans_start; ele <= ans_end; ele++) {
		ans.push_back(ele);
	}
	return ans;
    }

