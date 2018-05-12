/*You are in an infinite 2D grid where you can move in any of the 8 directions :

    (x,y) to 
    (x+1, y), 
    (x - 1, y), 
    (x, y+1), 
    (x, y-1), 
    (x-1, y-1), 
    (x+1,y+1), 
    (x-1,y+1), 
    (x+1,y-1) 
You are given a sequence of points and the order in which you need to cover the points. 
Give the minimum number of steps in which you can achieve it. You start from the first point.
Example:-Input : [(0, 0), (1, 1), (1, 2)]
         Output : 2
*/
// Input : X and Y co-ordinates of the points in order. 
// Each point is represented by (X[i], Y[i])
int Solution::coverPoints(vector<int> &X, vector<int> &Y) {
    int s=0;
    for(int i=1;i<X.size();i++){
        s+=max(abs(X[i-1]-X[i]),abs(Y[i-1]-Y[i]));
    }
    return s;
}
