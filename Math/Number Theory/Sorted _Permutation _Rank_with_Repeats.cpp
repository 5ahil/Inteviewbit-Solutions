/*Given a string, find the rank of the string amongst its permutations sorted lexicographically. 
Note that the characters might be repeated. If the characters are repeated, we need to look at the rank in unique permutations. 
Look at the example for more details.

Example :

Input : 'aba'
Output : 2

The order permutations with letters 'a', 'a', and 'b' : 
aab
aba
baa*/
public class Solution {
    public int findRank(String A) {
        int length = A.length();
        long strFactorial = factorial(length);
        long rank = 1;
        for(int i = 0; i < length; i++){
            strFactorial /= length - i;
            rank += findSmallerInRight(A, i, length - 1) * strFactorial;
        }
        //System.out.println("Rank : "+ Integer.MAX_VALUE);
        rank %= 1000003;
        return (int)rank;
    }
}
