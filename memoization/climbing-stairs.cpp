class Solution {
public:
    int climbStairs(int n) {
        vector<int>stair(n+1);
        stair[0]=1;
        stair[1]=1;
        for(int i=2;i<n+1;i++){
            stair[i]=stair[i-1]+stair[i-2];
        }
        return stair[n];
    }
};