/*
You’re given a read only array of n integers. Find out if any integer occurs more than n/3 times in the array in linear time and constant additional space.

If so, return the integer. If not, return -1.

If there are multiple solutions, return any one.

Example :

Input : [1 2 3 1 1]
Output : 1 
1 occurs 3 times which is more than 5/3 times. */
public class Solution {
 
	// DO NOT MODIFY THE LIST
 
public int repeatedNumber(final List<Integer> a) {

  int cnt1=0,cnt2=0;

  int c = -1,b = -1;

  for(int i=0;i<a.size();++i){

      if(cnt1 == 0 || a.get(i) == c){

          cnt1++;

          c = a.get(i);

      }
 
      else if(cnt2 == 0 || a.get(i) == b){
 
          cnt2++;
 
          b = a.get(i);
 
      }
 
      else{
 
          cnt1--;
 
          cnt2--;
 
      }
 
  }
 
  cnt1=0;
 
  cnt2=0;
 
  for(int x : a){
 
      if(x == c){
 
          cnt1++;
 
      }
 
      else if(x == b){
 
          cnt2++;
 
      }
 
  }
 
  if(cnt1*3 > a.size()){
 
      return c;
 
  }
 
  if(cnt2*3 > a.size()){
 
      return b;
 
  }
 
  return -1;
 

 }
}